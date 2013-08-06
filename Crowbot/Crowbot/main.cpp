#include "resource.h"

int main(int argc, char **argv)
{
	//initializing allegro
    al_init();
    al_init_image_addon();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_get_display_mode(al_get_num_display_modes()-1, &disp_data);
    //al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    al_set_new_display_flags(ALLEGRO_WINDOWED);
    al_set_new_display_option(ALLEGRO_VSYNC, 1, ALLEGRO_SUGGEST);
    disp_data.width*=0.8;
    disp_data.height*=0.8;
    display=al_create_display(disp_data.width, disp_data.height);
	if(!display)
    {
        return -1;
    }
	al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
    al_install_keyboard();
    al_install_mouse();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(5);
    al_set_target_bitmap(al_get_backbuffer(display));
    // allegro initialization

	// initializing lua
	lua_state = luaL_newstate();
	// opening libraries for lua, otherwise functions dont work
	luaL_openlibs(lua_state);
	// lua initialization

	// initializing box2d
	world.SetGravity(b2Vec2(0, -9.8));
	ContactListener worldContactListener;
	world.SetContactListener(&worldContactListener);
	const int tlx=0, tly=0, brx=10000, bry=disp_data.height;
    Box ground(tlx, bry-10, brx, bry);
    Box ceiling(tlx, tly, brx, 10);
    Box leftWall(tlx, tly, 10, bry);
    Box rightWall(brx-10, 0, brx, bry);
    Chain chn;
    chn.getResource()->registerChainShape(&chn, b2Vec2(0, 0),
        PHYSICAL_ENVIRONMENT, PHYSICAL_ALL,
        0, -PX_TO_M(bry)/3,
        PX_TO_M(brx)*1/10, -PX_TO_M(bry)*3/9,
        PX_TO_M(brx)*2/10, -PX_TO_M(bry)*5/9,
        PX_TO_M(brx)*3/10, -PX_TO_M(bry)*9/9,
        PX_TO_M(brx)*4/10, -PX_TO_M(bry)*6/9,
        PX_TO_M(brx)*5/10, -PX_TO_M(bry)*5/9,
        PX_TO_M(brx)*6/10, -PX_TO_M(bry)*3/9,
        PX_TO_M(brx)*7/10, -PX_TO_M(bry)*5/9,
        PX_TO_M(brx)*8/10, -PX_TO_M(bry)*8/9,
        PX_TO_M(brx)*9/10, -PX_TO_M(bry)*9/9,
        PX_TO_M(brx)*10/10, -PX_TO_M(bry)*7/9
                                          );
	// box2d initialization

    resource.initialize();
    sysGC.initialize();

    /*
    Lexer lex;
    Parser psr;
    auto ret=lex.generateTokens("\
    if(y>-0.2 && x<=11)\n\
    {\n\
        if(x<0.2)\n\
        {\n\
            activeBullet.move(0.4, 0.4)\n\
        }\n\
        else\n\
        {\n\
            activeBullet.move(0.4, 0)\n\
        }\n\
    }\n\
    else if(x>11 && y>=-8.2)\n\
    {\n\
        if(y>-0.2)\n\
        {\n\
            activeBullet.move(0.4, -0.4)\n\
        }\n\
        else\n\
        {\n\
            activeBullet.move(0, -0.4)\n\
        }\n\
    }\n\
    else if(y<-8.2 && x>=0.2)\n\
    {\n\
        if(x>11)\n\
        {\n\
            activeBullet.move(-0.4, -0.4)\n\
        }\n\
        else\n\
        {\n\
            activeBullet.move(-0.4, 0)\n\
        }\n\
    }\n\
    else if(x<0.2 && y<=-0.2)\n\
    {\n\
        if(y<-8.2)\n\
        {\n\
            activeBullet.move(-0.4, 0.4)\n\
        }\n\
        else\n\
        {\n\
            activeBullet.move(0, 0.4)\n\
        }\n\
    }\n\
                              ");
    std::cout<<"Errors: "<<ret<<std::endl;
    psr.parse(lex, "updatebullet", "x, y", "luascripts/");
    */

    activeBatbot=new Batbot*;
    activeBullet=new Bullet*;
    activeMissile=new Missile*;

    Frame game(Rect(0, 0, disp_data.width, disp_data.height), 0);
    Robot rob(ENTITYTYPE::CROWBOT, 0, b2Vec2(PX_TO_M(20), -PX_TO_M(20)), 100, &game);

    lua_regmfunctions(lua_state, "FrameMT");
    lua_makemfunction(lua_state, "spawn_batbot", "FrameMT", Frame,
    {
        make_batbot(luaL_checkinteger(l, 1), b2Vec2(luaL_checknumber(l, 2), luaL_checknumber(l, 3)), luaL_checkinteger(l, 4), obj)->push(obj->getCamera()->midground);
        return 0;
    });
    lua_prepmfunctions(lua_state, "__game", "FrameMT", Frame, &game);

    lua_regmfunctions(lua_state, "RobotMT");
    lua_makemfunction(lua_state, "shoot", "RobotMT", Robot,
    {
        obj->shootBullet(b2Vec2(0, 0), luaL_checknumber(l, 1), luaL_checknumber(l, 2));
        return 0;
    });
    lua_prepmfunctions(lua_state, "the_robot", "RobotMT", Robot, &rob);

    lua_regmfunctions(lua_state, "BulletMT");
    lua_makemfunction(lua_state, "move", "BulletMT", Bullet*,
    {
        (*obj)->move(b2Vec2(luaL_checknumber(l, 1), luaL_checknumber(l, 2)));
        return 0;
    });
    lua_prepmfunctions(lua_state, "activeBullet", "BulletMT", Bullet*, activeBullet);

    lua_regmfunctions(lua_state, "MissileMT");
    lua_makemfunction(lua_state, "move", "MissileMT", Missile*,
    {
        (*obj)->move(b2Vec2(luaL_checknumber(l, 1), luaL_checknumber(l, 2)));
        return 0;
    });
    lua_prepmfunctions(lua_state, "activeMissile", "MissileMT", Missile*, activeMissile);

    lua_regmfunctions(lua_state, "BatbotMT");
    lua_makemfunction(lua_state, "x", "BatbotMT", Batbot*,
    {
        lua_pushnumber(l, (*obj)->getX());
        return 1;
    });
    lua_makemfunction(lua_state, "y", "BatbotMT", Batbot*,
    {
        lua_pushnumber(l, (*obj)->getY());
        return 1;
    });
    lua_makemfunction(lua_state, "mass", "BatbotMT", Batbot*,
    {
        lua_pushnumber(l, (*obj)->getMass());
        return 1;
    });
    lua_makemfunction(lua_state, "move", "BatbotMT", Batbot*,
    {
        (*obj)->move(luaL_checknumber(l, 1), luaL_checknumber(l, 2));
        return 0;
    });
    lua_makemfunction(lua_state, "shoot", "BatbotMT", Batbot*,
    {
        (*obj)->shootProjectile(b2Vec2(0, 0), luaL_checknumber(l, 1), luaL_checknumber(l, 2));
        return 0;
    });
    lua_prepmfunctions(lua_state, "batbot", "BatbotMT", Batbot*, activeBatbot);

    lua_makelfunction(lua_state, "luascripts/updatelua.lua", "updatelua");
    lua_reglfunction(lua_state, "luascripts/userscript.lua");
    lua_reglfunction(lua_state, "luascripts/updatebullet.lua");
    lua_reglfunction(lua_state, "luascripts/updatebatbot.lua");
    /*
    luaE_beginmfunctions(lua_state, "RobotMT");
    luaE_regmfunctions();
    luaE_makemfunction("press", Robot,
                                     {
                                         obj->onKeyPress(luaL_checkint(l, 1), ALLEGRO_KEY_RIGHT, luaL_checkint(l, 2));
                                         return 0;
                                     });
    luaE_prepmfunctions("the_robot", Robot, &rob);
    luaE_endmfunctions();
    */
    /*
    rob.push(game.getCamera()->midground);
    chn.push(game.getCamera()->background);
    ground.push(game.getCamera()->background);
    ceiling.push(game.getCamera()->background);
    leftWall.push(game.getCamera()->background);
    rightWall.push(game.getCamera()->background);
    */
    game.addOnRestart([](FRAMETYPE){return true;}, [&rob, &game](){rob.push(game.getCamera()->midground);});
    game.addOnRestart([](FRAMETYPE){return true;}, [&chn, &game](){chn.push(game.getCamera()->background);});
    game.addOnRestart([](FRAMETYPE){return true;}, [&ground, &game](){ground.push(game.getCamera()->background);});
    game.addOnRestart([](FRAMETYPE){return true;}, [&ceiling, &game](){ceiling.push(game.getCamera()->background);});
    game.addOnRestart([](FRAMETYPE){return true;}, [&leftWall, &game](){leftWall.push(game.getCamera()->background);});
    game.addOnRestart([](FRAMETYPE){return true;}, [&rightWall, &game](){rightWall.push(game.getCamera()->background);});
    game.addOnRestart([](FRAMETYPE){return true;}, [&rob, &game](){game.addObserver(&rob);});
    game.getCamera()->setCustomTranslate([&rob]() -> Pixel
    {
        return Pixel(-M_TO_PX(rob.getPosition().x)+disp_data.width/2, 0/*-rob.getPosition().y-PX_TO_M(disp_data.height)*2/3*/);
    }
                                         );
    game.addObserver(&rob);
    game.start(FRAMETYPE::STARTSCREEN);
    std::chrono::steady_clock::time_point current_time;
    current_time=std::chrono::steady_clock::now();
    while(game)
    {
        sysEvents[EVENTTYPE::COLLECTGARBAGE].fire();
        //lua_runlfunction(lua_state, "updatelua");
        game.delayTime(std::chrono::duration_cast<std::chrono::duration<float>>(std::chrono::steady_clock::now()-current_time).count());
        current_time=std::chrono::steady_clock::now();
        game.update();
        game.render();
        al_flip_display();
    }
    rob.pull();
    delete activeBatbot;
    delete activeBullet;
    delete activeMissile;
    lua_close(lua_state);
    resource.cleanup();
    sysGC.cleanup();
    game.end();
    game.destroy();
    al_destroy_display(display);
    printf("End\n");

    return 0;
}
