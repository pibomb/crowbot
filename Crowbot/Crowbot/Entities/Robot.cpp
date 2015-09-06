#include "resource.h"

Robot::Robot(ENTITYTYPE entity_type_arg, const unsigned int& id_arg, const b2Vec2& pos_arg, const int& startHp, Frame *frame_arg):
    Entity(Rect(0, 0, 120, 160), entity_type_arg, id_arg, startHp, frame_arg),
    facingRight(true),
    touchingGround(0)
{
    obj_body->registerDynamicBox(this, pos_arg, PHYSICAL_PLAYER, PHYSICAL_ALL&~PHYSICAL_PLAYER, PX_TO_M(120), PX_TO_M(160), 7.85, 0.7);
    obj_body->addGroundSensor(((void*)(static_cast<void(*)(PhysicalDrawable*, PhysicalDrawable*, COLLISIONTYPE)>([](PhysicalDrawable* self, PhysicalDrawable* other, COLLISIONTYPE col_type)
                                                                                                                   {
    switch(col_type)
    {
    case COLLISIONTYPE::BEGIN:
    {
       static_cast<Robot*>(self)->touchingGround++;
       break;
    }
    case COLLISIONTYPE::END:
    {
       static_cast<Robot*>(self)->touchingGround--;
       break;
    }
    default:
    {
       break;
    }
    }
                                                                                                                   }))),
    PHYSICAL_PLAYER,
    PHYSICAL_ALL&~PHYSICAL_PLAYER
    );
    obj_body->getBody()->SetFixedRotation(true);
}

void Robot::onKeyPress(int unichar, int keycode, unsigned int modifiers)
{
    switch(keycode)
    {
    case ALLEGRO_KEY_C:
    {
        QueryCallback qc;
        b2AABB aabb;
        aabb.lowerBound=getPosition()-b2Vec2(PX_TO_M(200), PX_TO_M(200));
        aabb.upperBound=getPosition()+b2Vec2(PX_TO_M(200), PX_TO_M(200));
        world.QueryAABB(&qc, aabb);
        std::cout<<"****Begin"<<std::endl;
        for(auto &it : qc.foundBodies)
        {
            switch(static_cast<PhysicalDrawable*>(it->GetUserData())->getDrawableType())
            {
        case DRAWABLETYPE::ROBOT:
            {
                std::cout<<"Robot"<<std::endl;
                break;
            }
        case DRAWABLETYPE::BATBOT:
            {
                std::cout<<"Batbot"<<std::endl;
                break;
            }
        case DRAWABLETYPE::CHAIN:
            {
                std::cout<<"Chain"<<std::endl;
                break;
            }
        case DRAWABLETYPE::BOX:
            {
                std::cout<<"Box"<<std::endl;
                break;
            }
        case DRAWABLETYPE::BULLET:
            {
                std::cout<<"Bullet"<<std::endl;
                break;
            }
        case DRAWABLETYPE::MISSILE:
            {
                std::cout<<"Missile"<<std::endl;
                break;
            }
        default:
            {
                std::cout<<"Default"<<std::endl;
                break;
            }
            }
        }
        std::cout<<"****End"<<std::endl;
        break;
    }
    case ALLEGRO_KEY_Z:
    {
        if(facingRight)
        {
            for(int i=270; i<450; i+=10)
            {
                shootBullet(b2Vec2(0, PX_TO_M((i-270)/10-9)*6), DEG_TO_RAD(i), 5);
            }
        }
        else
        {
            for(int i=90; i<=270; i+=10)
            {
                shootBullet(b2Vec2(0, PX_TO_M(-(i-90)/10+9)*6), DEG_TO_RAD(i), 5);
            }
        }
        break;
    }
    case ALLEGRO_KEY_X:
    {
        if(facingRight)
        {
            for(int i=270; i<450; i+=10)
            {
                shootBullet(b2Vec2(0, -(i-270)/10+9), DEG_TO_RAD(i), 5);
            }
        }
        else
        {
            for(int i=90; i<=270; i+=10)
            {
                shootBullet(b2Vec2(0, (i-90)/10-9), DEG_TO_RAD(i), 5);
            }
        }
        break;
    }
    case ALLEGRO_KEY_W:
    {
        if(touchingGround)
        {
            obj_body->ApplyLinearImpulseAtCenter(b2Vec2(0, obj_body->getBody()->GetMass()*30));
        }
        break;
    }
    case ALLEGRO_KEY_A:
    {
        facingRight=false;
        obj_body->ApplyLinearImpulseAtCenter(b2Vec2(-obj_body->getBody()->GetMass()*2, 0));
        break;
    }
    case ALLEGRO_KEY_D:
    {
        facingRight=true;
        obj_body->ApplyLinearImpulseAtCenter(b2Vec2(obj_body->getBody()->GetMass()*2, 0));
        break;
    }
    case ALLEGRO_KEY_Q:
    {
        shootMissile(b2Vec2(0, 0), b2Vec2(-5, 2), 10000);
        shootMissile(b2Vec2(0, 0), b2Vec2(-5, 0), 10000);
        shootMissile(b2Vec2(0, 0), b2Vec2(-5, -2), 10000);

        break;
    }
    case ALLEGRO_KEY_E:
    {
        shootMissile(b2Vec2(0, 0), b2Vec2(5, 2), 10000);
        shootMissile(b2Vec2(0, 0), b2Vec2(5, 0), 10000);
        shootMissile(b2Vec2(0, 0), b2Vec2(5, -2), 10000);

        break;
    }
    case ALLEGRO_KEY_LCTRL:
    {
        if(facingRight)
        {
            shootMissile(b2Vec2(0, 0), b2Vec2(5, 0), 10000);
        }
        else
        {
            shootMissile(b2Vec2(0, 0), b2Vec2(-5, 0), 10000);
        }
    }
    case ALLEGRO_KEY_SPACE:
    {
        if(facingRight)
        {
            shootBullet(b2Vec2(0, 0), DEG_TO_RAD(0), 2000);
        }
        else
        {
            shootBullet(b2Vec2(0, 0), DEG_TO_RAD(180), 2000);
        }
        break;
    }
    default:
    {
        break;
    }
    }
}

void Robot::onKeyRelease(int unichar, int keycode, unsigned int modifiers)
{
    switch(keycode)
    {
    default:
    {
        break;
    }
    }
}

void Robot::onMouseClick(int x_pos, int y_pos)
{
    float angle=atan2(-y_pos-M_TO_PX(getPosition().y), x_pos-disp_data.width/2);
    shootBullet(b2Vec2(0, 0), angle, 5);
    if(fabs(angle)>DEG_TO_RAD(90))
    {
        facingRight=false;
    }
    else
    {
        facingRight=true;
    }
}

void Robot::onTimerKeyState(const std::vector<bool> &keystates)
{
    if(!touchingGround)
    {
        obj_body->ApplyLinearImpulseAtCenter(b2Vec2(0, -obj_body->getBody()->GetMass()*3));
    }
    if(keystates[ALLEGRO_KEY_A])
    {
        facingRight=false;
        obj_body->ApplyLinearImpulseAtCenter(b2Vec2(-obj_body->getBody()->GetMass()*2/5, 0));
    }
    if(keystates[ALLEGRO_KEY_D])
    {
        facingRight=true;
        obj_body->ApplyLinearImpulseAtCenter(b2Vec2(obj_body->getBody()->GetMass()*2/5, 0));
    }
    if(keystates[ALLEGRO_KEY_V])
    {
        if(facingRight)
        {
            shootBullet(b2Vec2(PX_TO_M(5), PX_TO_M(15)), DEG_TO_RAD(0), 5);
            shootBullet(b2Vec2(PX_TO_M(10), PX_TO_M(0)), DEG_TO_RAD(0), 5);
            shootBullet(b2Vec2(PX_TO_M(0), PX_TO_M(-15)), DEG_TO_RAD(0), 5);
        }
        else
        {
            shootBullet(b2Vec2(-PX_TO_M(5), PX_TO_M(15)), DEG_TO_RAD(180), 5);
            shootBullet(b2Vec2(-PX_TO_M(10), PX_TO_M(0)), DEG_TO_RAD(180), 5);
            shootBullet(b2Vec2(-PX_TO_M(0), PX_TO_M(-15)), DEG_TO_RAD(180), 5);
        }
    }
    /*
    if(keystates[ALLEGRO_KEY_DOWN])
    {
        obj_body->ApplyLinearImpulseAtCenter(b2Vec2(0, -100));
    }
    */
}

void Robot::shootBullet(b2Vec2 pos_arg, float angle_arg, float linearVelocity_arg)
{
    make_bullet(this, getPosition()+pos_arg, PHYSICAL_PLAYER, PHYSICAL_ALL&~PHYSICAL_PLAYER, angle_arg, linearVelocity_arg);
}

void Robot::shootMissile(b2Vec2 pos_arg, b2Vec2 linearVelocity_arg, float fuel_arg)
{
    make_missile(this, getPosition()+pos_arg, PHYSICAL_PLAYER, PHYSICAL_ALL&~PHYSICAL_PLAYER, linearVelocity_arg, fuel_arg);
}

void Robot::addFunction(std::string function_name, std::function<void(Robot*, std::vector<int>)> function_arg)
{
    robotFunctions[function_name]=function_arg;
}

void Robot::executeFunction(std::string function_name, std::vector<int> args)
{
    auto it=robotFunctions.find(function_name);
    if(it!=robotFunctions.end())
    {
        it->second(this, args);
    }
}

void Robot::onDraw()
{
    if(facingRight)
    {
        draw_current_frame_centered(0, 0, 0);
    }
    else
    {
        draw_current_frame_centered(0, 0, ALLEGRO_FLIP_HORIZONTAL);
    }
}

void Robot::destroy()
{
    //
}

DRAWABLETYPE Robot::getDrawableType()
{
    return DRAWABLETYPE::ROBOT;
}

void Robot::beginCollision(PhysicalDrawable *other)
{
    switch(other->getDrawableType())
    {
    case DRAWABLETYPE::BULLET:
    {
        if(static_cast<Bullet*>(other)->canHit())
        {
            setHp(-1);
        }
        break;
    }
    default:
    {
        break;
    }
    }
}

void Robot::endCollision(PhysicalDrawable *other)
{
    switch(other->getDrawableType())
    {
    default:
    {
        break;
    }
    }
}
