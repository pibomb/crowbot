#include "resource.h"

Robot::Robot(ENTITYTYPE entity_type_arg, const unsigned int& id_arg, const b2Vec2& pos_arg, const int& startHp, Frame *frame_arg):
    Entity(entity_type_arg, id_arg, startHp, frame_arg),
    facingRight(true),
    touchingGround(0)
{
    ent_body->registerDynamicBox(this, pos_arg, PX_TO_M(120), PX_TO_M(160), 7.85, 0.7);
    ent_body->addGroundSensor(((void*)(static_cast<void(*)(PhysicalDrawable*, PhysicalDrawable*, COLLISIONTYPE)>([](PhysicalDrawable* self, PhysicalDrawable* other, COLLISIONTYPE col_type)
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
                                                                                                                   }))));
    ent_body->getBody()->SetFixedRotation(true);
}

void Robot::onKeyPress(int unichar, int keycode, unsigned int modifiers)
{
    switch(keycode)
    {
    case ALLEGRO_KEY_W:
    {
        shootProjectile(0, b2Vec2(0, 0), DEG_TO_RAD(90), 5);
        break;
    }
    case ALLEGRO_KEY_A:
    {
        facingRight=false;
        shootProjectile(0, b2Vec2(0, 0), DEG_TO_RAD(180), 5);
        break;
    }
    case ALLEGRO_KEY_S:
    {
        shootProjectile(0, b2Vec2(0, 0), DEG_TO_RAD(270), 5);
        break;
    }
    case ALLEGRO_KEY_D:
    {
        facingRight=true;
        shootProjectile(0, b2Vec2(0, 0), DEG_TO_RAD(0), 5);
        break;
    }
    case ALLEGRO_KEY_UP:
    {
        if(touchingGround)
        {
            ent_body->ApplyLinearImpulseAtCenter(b2Vec2(0, ent_body->getBody()->GetMass()*30));
        }
        break;
    }
    case ALLEGRO_KEY_LEFT:
    {
        facingRight=false;
        ent_body->ApplyLinearImpulseAtCenter(b2Vec2(-ent_body->getBody()->GetMass()*2, 0));
        break;
    }
    case ALLEGRO_KEY_RIGHT:
    {
        facingRight=true;
        ent_body->ApplyLinearImpulseAtCenter(b2Vec2(ent_body->getBody()->GetMass()*2, 0));
        break;
    }
    case ALLEGRO_KEY_SPACE:
    {
        if(facingRight)
        {
            shootProjectile(0, b2Vec2(0, 0), DEG_TO_RAD(0), 2000);
        }
        else
        {
            shootProjectile(0, b2Vec2(0, 0), DEG_TO_RAD(0), -2000);
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

void Robot::onTimerKeyState(const std::vector<bool> &keystates)
{
    printf("%d\n", touchingGround);
    if(!touchingGround)
    {
        ent_body->ApplyLinearImpulseAtCenter(b2Vec2(0, -ent_body->getBody()->GetMass()*3));
    }
    if(keystates[ALLEGRO_KEY_LEFT])
    {
        facingRight=false;
        ent_body->ApplyLinearImpulseAtCenter(b2Vec2(-ent_body->getBody()->GetMass()*2/5, 0));
    }
    if(keystates[ALLEGRO_KEY_RIGHT])
    {
        facingRight=true;
        ent_body->ApplyLinearImpulseAtCenter(b2Vec2(ent_body->getBody()->GetMass()*2/5, 0));
    }
    /*
    if(keystates[ALLEGRO_KEY_DOWN])
    {
        ent_body->ApplyLinearImpulseAtCenter(b2Vec2(0, -100));
    }
    */
}

void Robot::shootProjectile(int id_arg, b2Vec2 pos_arg, float angle_arg, float linearVelocity_arg)
{
    Bullet *proj=new Bullet;
    b2Vec2 linearVelocity(cos(angle_arg)*linearVelocity_arg, sin(angle_arg)*linearVelocity_arg);
    ent_body->ApplyLinearImpulseAtCenter(-linearVelocity);
    if(facingRight)
    {
        proj->set(b2Vec2(getPosition().x+PX_TO_M(140)/2, getPosition().y)+pos_arg, linearVelocity, 10000, DEG_TO_RAD(0));
    }
    else
    {
        proj->set(b2Vec2(getPosition().x-PX_TO_M(140)/2, getPosition().y)+pos_arg, linearVelocity, 10000, DEG_TO_RAD(180));
    }
    proj->push(frame->getCamera()->foreground);
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
