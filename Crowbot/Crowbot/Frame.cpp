#include "resource.h"

FRAMETYPE Frame::getID()
{
    return id;
}

void Frame::setID(FRAMETYPE id_arg)
{
    id=id_arg;
}

Camera* Frame::getCamera()
{
    return camera;
}

void Frame::setCamera(Camera *camera_arg)
{
    camera=camera_arg;
}

int Frame::getX(int x_arg)
{
    return x_arg-region.getTL().getX();
}

int Frame::getY(int y_arg)
{
    return y_arg-region.getTL().getY();
}

Rect Frame::getRegion()
{
    return region;
}

void Frame::addButton(Button *button_arg)
{
    buttons.push_front(button_arg);
    (*buttons.begin())->push(this);
}
#ifdef ENET_ENABLED
bool Frame::startLANConnection()
{
    /* Initiate the connection, allocating the two channels 0 and 1. */
    enet_address_set_host(&address, "127.0.0.1");
    address.port=1234;
    host=enet_host_create (nullptr /* create a client host */,
                1 /* only allow 1 outgoing connection */,
                2 /* allow up 2 channels to be used, 0 and 1 */,
                57600 / 8 /* 56K modem with 56 Kbps downstream bandwidth */,
                14400 / 8 /* 56K modem with 14 Kbps upstream bandwidth */);
    peer=enet_host_connect(host, &address, 2, 0);
    int fails;
    const int max_fails=50;
    float alpha=0.5, delta=0.1;
    int bbx, bby, bbw, bbh;
    ALLEGRO_EVENT ev;
    al_get_text_dimensions(idToFont.getFont(FONT_FFF_TUSJ, 42), "SEARCHING FOR GAMES...", &bbx, &bby, &bbw, &bbh);
    for(fails=0; fails<max_fails; fails++)
    {
        for(; al_get_next_event(event_queue, &ev);)
        {
            switch(ev.type)
            {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
            {
                valid=false;
                return true;
            }
            case ALLEGRO_EVENT_KEY_CHAR:
            {
                switch(ev.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                {
                    valid=false;
                    return true;
                }
                default:
                {
                    break;
                }
                }
                break;
            }
            default:
            {
                break;
            }
            }
        }
        al_clear_to_color(AL_COL_BLACK);
        al_draw_text(idToFont.getFont(FONT_FFF_TUSJ, 42), al_map_rgba_f(alpha, alpha, alpha, alpha), disp_data.width/2.0-bbw/2.0, disp_data.height/2.0-bbh/2.0, 0, "SEARCHING FOR GAMES...");
        if(alpha<0.5 || alpha>=1.0)
        {
            delta=-delta;
        }
        alpha+=delta;
        al_flip_display();
        enet_host_service(host, &enet_event, 100);
        if(enet_event.type==ENET_EVENT_TYPE_CONNECT)
        {
            break;
        }
    }
    if(fails!=max_fails)
    {
        //join a server
        enet_state=ENETSTATE::IS_CLIENT;
    }
    else
    {
        enet_host_destroy(host);
        peer=nullptr;
        //make a server
        host=enet_host_create(&address /* the address to bind the server host to */,
                                  1      /* allow up to 1 client and/or outgoing connection */,
                                  2      /* allow up to 2 channels to be used, 0 and 1 */,
                                  0      /* assume any amount of incoming bandwidth */,
                                  0      /* assume any amount of outgoing bandwidth */);
        if(!host)
        {
            return false;
        }
        enet_state=ENETSTATE::IS_SERVER;
        currentMap.loadMap(this, "maps", mapID);
    }
    enet=true;
    return true;
}

void Frame::endLANConnection()
{
    if(enet)
    {
        enet_host_destroy(host);
        enet_state=ENETSTATE::IS_INVALID;
        host=nullptr;
        peer=nullptr;
        enet=false;
        peer_valid=false;
    }
}

bool Frame::validatePeer(ENetPacket *packet)
{
    switch(enet_state)
    {
    case ENETSTATE::IS_CLIENT:
    {
        return !strncmp((const char*)packet->data, ENET_SERVER_UUID, UUID_LENGTH) && !strcmp((const char*)(packet->data+UUID_LENGTH), VERSION);
    }
    case ENETSTATE::IS_SERVER:
    {
        return !strncmp((const char*)packet->data, ENET_CLIENT_UUID, UUID_LENGTH) && !strcmp((const char*)(packet->data+UUID_LENGTH), VERSION);
    }
    default:
    {
        return false;
    }
    }
    return false;
}

void Frame::sendInfo(std::string message, bool validate)
{
    if(validate || isConnectedOverLAN())
    {
        ENetPacket *packet=enet_packet_create(message.c_str(), message.length()+1, ENET_PACKET_FLAG_RELIABLE);
        /* Extend the packet so and append the string "foo", so it now */
        /* contains "packetfoo\0"                                      */
        /*
        enet_packet_resize (packet, strlen ("packetfoo") + 1);
        strcpy ((char*)& packet -> data [strlen ("packet")], "foo");
        */
        /* Send the packet to the peer over channel id 0. */
        /* One could also broadcast the packet by         */
        /* enet_host_broadcast (host, 0, packet);         */
        enet_peer_send(peer, 0, packet);
        /* One could just use enet_host_service() instead. */
        enet_host_flush(host);
    }
}

void Frame::recvInfo(ENetPacket *packet)
{
    std::string packetInfo((const char*)packet->data, packet->dataLength);
    switch(static_cast<ACTIONTYPE>(packetInfo[0]))
    {
    case ACTIONTYPE::TRANSFER_ID:
    {
        player->setTeamID(packetInfo[1]);
        break;
    }
    case ACTIONTYPE::TRANSFER_MAP:
    {
        std::stringstream ss;
        ss<<(int)packetInfo[1]<<" "<<(int)packetInfo[2]<<" ";
        for(int i=3; i+8<=(int)packetInfo.length(); i+=8)
        {
            ss<<strull(packetInfo.substr(i, 8))<<" ";
        }
        currentMap.loadMapFromStream(this, ss);
        if(underlyingMap)
        {
            al_destroy_bitmap(underlyingMap);
        }
        underlyingMap=al_create_bitmap(currentMap.getWidth()*TILE_WIDTH, currentMap.getHeight()*TILE_HEIGHT+TILE_HEIGHT/2);
        break;
    }
    case ACTIONTYPE::CHAT:
    {
        std::string name=packetInfo.substr(1, packetInfo.find((char)0, 1)-1);
        std::string message=packetInfo.substr(packetInfo.find((char)0, 1)+1, packetInfo.find((char)0, packetInfo.find((char)0, 1)+1)-(packetInfo.find((char)0, 1)+1));
        std::string rest=packetInfo.substr(packetInfo.find((char)0, packetInfo.find((char)0, 1)+1)+1);
        ullChar8 uch8;
        memset(uch8.ch8.ch, char(0), 8);
        strcpy(uch8.ch8.ch, rest.substr(6, 8).c_str());
        getChatlog()->insertWithoutSending(name, message, al_map_rgb(rest[0], rest[1], rest[2]), rest[3]+FONT_OFFSET, rest[4], rest[5], uch8.ull);
        break;
    }
    case ACTIONTYPE::END:
    {
#ifdef EVENT_ENABLED
        idToEvent[EVENTTYPE::TURN_END].fire(std::vector<EVENTOPTIONS>(), std::vector<int>(1, getPlayer()->getTeamID()==1?2:1));
#endif
        getWorld()->clearDeadEntities();
        getPlayer()->beginTurn(getWorld());
        break;
    }
    case ACTIONTYPE::MOVE:
    {
        Tile *t1=currentMap.getTileWithHexpt(hexpt(packetInfo[1], packetInfo[2])), *t2=currentMap.getTileWithHexpt(hexpt(packetInfo[3], packetInfo[4]));
        t1->getEntity()->move(t2, false);
        getWorld()->recalculate(this);
        break;
    }
    case ACTIONTYPE::ATTACK:
    {
        Tile *t1=currentMap.getTileWithHexpt(hexpt(packetInfo[1], packetInfo[2])), *t2=currentMap.getTileWithHexpt(hexpt(packetInfo[3], packetInfo[4]));
        t1->getEntity()->attack(t2->getEntity());
        getWorld()->recalculate(this);
        break;
    }
    case ACTIONTYPE::ENGULF:
    {
        Tile *t1=currentMap.getTileWithHexpt(hexpt(packetInfo[1], packetInfo[2])), *t2=currentMap.getTileWithHexpt(hexpt(packetInfo[3], packetInfo[4]));
        Slime *slimeEntity=dynamic_cast<Slime*>(t1->getEntity());
        if(slimeEntity)
        {
            slimeEntity->engulf(t2->getEntity());
            getWorld()->recalculate(this);
        }
        break;
    }
    case ACTIONTYPE::GUARD:
    {
        Tile *t1=currentMap.getTileWithHexpt(hexpt(packetInfo[1], packetInfo[2]));
        Hero *hero=dynamic_cast<Hero*>(t1->getEntity());
        if(hero)
        {
            hero->defenseTempUp(3);
            EventHandler *evHandler=new EventHandler(std::bind(&Hero::defenseTempUp, hero, -3));
            evHandler->push(idToEvent[EVENTTYPE::TURN_END]);
            evHandler->add(EVENTTYPE::TURN_END);
            evHandler->add(EVENTTYPE::TURN_END);
            evHandler->add(EVENTTYPE::TURN_END);
        }
        break;
    }
    case ACTIONTYPE::SPAWN:
    {
        Tile *t1=currentMap.getTileWithHexpt(hexpt(packetInfo[1], packetInfo[2]));
        ENTITY entityID=static_cast<ENTITY>(strint(packetInfo.substr(3, 4)));
        switch(entityID)
        {
        case ENTITY::SLIME_SCOUT:
        case ENTITY::SLIME_SOLDIER:
        case ENTITY::SLIME_SNIPER:
        case ENTITY::SLIME_SUMO:
        {
            t1->setEntity(new Slime(entityID, player->getTeamID()==1?2:1, UNIT_DATA[entityID].health, UNIT_DATA[entityID].mana, t1->pt, t1, getPlayer(), getChatlog()));
            break;
        }
        case ENTITY::ROBOT_TRINIV1:
        case ENTITY::ROBOT_TRINIV2:
        case ENTITY::ROBOT_RANGED:
        case ENTITY::ROBOT_TRINIV3:
        {
            t1->setEntity(new Robot(entityID, player->getTeamID()==1?2:1, UNIT_DATA[entityID].health, UNIT_DATA[entityID].mana, t1->pt, t1, getPlayer(), getChatlog()));
            break;
        }
        case ENTITY::BASE1:
        case ENTITY::BASE2:
        {
            t1->setEntity(new Base(entityID, player->getTeamID()==1?2:1, UNIT_DATA[entityID].health, UNIT_DATA[entityID].mana, t1->pt, t1, getPlayer(), getChatlog()));
            break;
        }
        case ENTITY::HERO_TALOS:
        case ENTITY::HERO_LYRA:
        {
            t1->setEntity(new Hero(entityID, player->getTeamID()==1?2:1, UNIT_DATA[entityID].health, UNIT_DATA[entityID].mana, t1->pt, t1, getPlayer(), getChatlog()));
            break;
        }
        default:
        {
            t1->setEntity(new Entity(entityID, player->getTeamID()==1?2:1, UNIT_DATA[entityID].health, UNIT_DATA[entityID].mana, t1->pt, t1, getPlayer(), getChatlog()));
            break;
        }
        }
        t1->getEntity()->push(camera->foreground.get());
        getWorld()->recalculate(this);
        break;
    }
    case ACTIONTYPE::KILL:
    {
        Tile *t1=currentMap.getTileWithHexpt(hexpt(packetInfo[1], packetInfo[2]));
        t1->getEntity()->onDeath();
        getWorld()->recalculate(this);
        break;
    }
    default:
    {
        break;
    }
    }
}

bool Frame::isConnectedOverLAN()
{
    return peer && peer_valid;
}
#endif
void Frame::delayTime()
{
#ifdef ENET_ENABLED
    if(enet)
    {
        enet_host_service(host, &enet_event, 1000/frames_per_second);
    }
    else
    {
        al_rest(1.0/frames_per_second);
    }
#else
    al_rest(1.0/frames_per_second);
#endif
}

void Frame::start(FRAMETYPE id_arg)
{
    if(!valid)
    {
        return;
    }
    setID(id_arg);
    key.resize(ALLEGRO_KEY_MAX, false);
    switch(id_arg)
    {
    case FRAMETYPE::STARTSCREEN:
    {
        if(!(event_queue=al_create_event_queue())||!(timer=al_create_timer(1.0/frames_per_second)))
        {
            return;
        }
        al_register_event_source(event_queue, al_get_display_event_source(display));
        al_register_event_source(event_queue, al_get_timer_event_source(timer));
        al_register_event_source(event_queue, al_get_keyboard_event_source());
        al_register_event_source(event_queue, al_get_mouse_event_source());
        //resource.stopAllAudio();
        addButton(new Button(
                             disp_data.width/2-200,
                             disp_data.height/2-96,
                             disp_data.width/2+200,
                             disp_data.height/2,
                             std::bind(&Frame::restart, this, getRegion(), mapID, FRAMETYPE::STAGE),
                             "Start Campaign",
                             BUTTONTYPE::INVALID,
                             resource.getFont(FONT_DEFAULT_GAME, FONT_SIZE_LARGE_GAME),
                             AL_COL_WHITE,
                             resource.getImage(IMAGETYPE::DEFAULT_BUTTON),
                             resource.getImage(IMAGETYPE::DEFAULT_BUTTON_H),
                             resource.getImage(IMAGETYPE::DEFAULT_BUTTON_D)));
        al_start_timer(timer);
        break;
    }
    case FRAMETYPE::STAGE:
    {
        if(!(event_queue=al_create_event_queue())||!(timer=al_create_timer(1.0/frames_per_second)))
        {
            return;
        }
        al_register_event_source(event_queue, al_get_display_event_source(display));
        al_register_event_source(event_queue, al_get_timer_event_source(timer));
        al_register_event_source(event_queue, al_get_keyboard_event_source());
        al_register_event_source(event_queue, al_get_mouse_event_source());
        //resource.stopAllAudio();
        al_start_timer(timer);
        break;
    }
/*
    case FRAME_MULTIPLAYER_STRATEGY:
    {
        if(!(event_queue=al_create_event_queue())||!(timer=al_create_timer(1.0/frames_per_second)))
        {
            return;
        }
        al_register_event_source(event_queue, al_get_display_event_source(display));
        al_register_event_source(event_queue, al_get_timer_event_source(timer));
        al_register_event_source(event_queue, al_get_keyboard_event_source());
        al_register_event_source(event_queue, al_get_mouse_event_source());
        idToAudio.stop();
        idToAudio[AUDIO_DUNGEON].play(ALLEGRO_PLAYMODE_LOOP);
#ifdef ENET_ENABLED
        if(!startLANConnection())
        {
            restart(getRegion(), mapID, FRAME_STARTSCREEN, getPlayer());
            return;
        }
        if(!valid)
        {
            end();
            return;
        }
#endif
        activeTile=nullptr;
        selectedTile=nullptr;
        activeMenu=new Menu;
#ifndef ENET_ENABLED
        currentMap.loadMap(this, "maps", mapID);
#endif
        underlyingMap=al_create_bitmap(0, 0);
        movesLeft=new Counter([this]() ->std::string
                              {
                                  return intToStr(getPlayer()->getMoves());
                              }, idToImage[IMG_ENERGY_LEFT_SYMBOL].get());
        movesLeft->push(this);
        std::function<void()> btnFunc;
        switch(getID())
        {
#ifdef ENET_ENABLED
        case FRAME_MULTIPLAYER_STRATEGY:
        {
            btnFunc=[this]()
            {
                if(isConnectedOverLAN() && getPlayer()->state==PLAYSTATE::IS_TURN)
                {
                    getPlayer()->endTurn();
                    sendInfo(getPacket(static_cast<char>(ACTIONTYPE::END)));
                }
                return;
            };
            break;
        }
#endif
        case FRAME_CAMPAIGN_STRATEGY:
        {
            btnFunc=[this]()
            {
                if(getPlayer()->state==PLAYSTATE::IS_TURN)
                {
                    getPlayer()->endTurn();
                    getPlayer()->beginTurn(getWorld());
                }
                return;
            };
            break;
        }
        default:
        {
            btnFunc=[]()
            {
                return;
            };
            break;
        }
        }
        addButton(new Button(
                             region.getBR().getX()-128,
                             region.getBR().getY()-32,
                             region.getBR().getX(),
                             region.getBR().getY(),
                             btnFunc,
                             "End Turn",
                             BTN_END_TURN,
                             idToFont.getFont(FONT_DEFAULT_GAME, FONT_SIZE_DEFAULT_GAME),
                             AL_COL_WHITE,
                             idToImage[IMG_BUTTON_BACKGROUND].get(),
                             idToImage[IMG_BUTTON_BACKGROUND_H].get(),
                             idToImage[IMG_BUTTON_BACKGROUND_D].get()));
        chatlog->insert("System", "Starting multiplayer mode...", AL_COL_YELLOW, CMSG_NOTICE, 0);
        al_start_timer(timer);
        break;
    }
    */
    default:
    {
        break;
    }
    }
    valid=true;
}

void Frame::end()
{
#ifdef ENET_ENABLED
    if(enet)
    {
        endLANConnection();
    }
#endif
    setID(FRAMETYPE::INVALID);
    al_clear_to_color(AL_COL_BLACK);
    al_flip_display();
    if(valid)
    {
        al_destroy_timer(timer);
        al_destroy_event_queue(event_queue);
#ifdef AUDIO
        al_destroy_sample(sample);
#endif
        camera->background->inner.clear();
        camera->foreground->inner.clear();
        camera->menus->inner.clear();
        valid=false;
    }
}

void Frame::destroy()
{
    al_ustr_free(input);
    camera->pull();
    delete camera;
    camera=nullptr;
}

void Frame::restart(Rect region_arg, int mapid_arg, FRAMETYPE id_arg)
{
    end();
    mapID=mapid_arg;
    frames_per_second=60;
    valid=true;
    region=region_arg;
    for(auto &it : buttons)
    {
        it->pull();
        delete it;
    }
    buttons.clear();
    if(id_arg!=FRAMETYPE::INVALID)
    {
        start(id_arg);
    }
}

void Frame::onLeftUp()
{
    if(activeButton)
    {
        activeButton->release();
        activeButton=nullptr;
    }
}

void Frame::onLeftClick()
{
    switch(id)
    {
    case FRAMETYPE::STARTSCREEN:
    {
        al_get_mouse_state(&cursorState);
        bool overlay_button_clicked=false;
        for(auto it=buttons.begin(); it!=buttons.end(); it++)
        {
            if((*it)->contains(cursorState.x, cursorState.y))
            {
                overlay_button_clicked=true;
                (*it)->press();
                activeButton=*it;
                break;
            }
        }
        if(!overlay_button_clicked)
        {
            //something
        }
        break;
    }
    default:
    {
        break;
    }
    }
}

void Frame::transformation()
{
    preset().preTranslate(region.getTL());
}

void Frame::onDraw()
{
    al_clear_to_color(AL_COL_BLACK);
}

void Frame::postDraw()
{
    //al_draw_tinted_scaled_bitmap(idToImage[IMG_RECTANGLE].get(), al_map_rgba_f(1, 1, 1, 0.7), 0, 0, 1, 1, 0, 0, disp_data.width, disp_data.height, 0);
}
