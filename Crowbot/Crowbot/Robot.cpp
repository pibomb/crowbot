#include "resource.h"

Robot::Robot(ENTITYTYPE entity_type_arg, const unsigned int& id_arg, const b2Vec2& pos_arg, const int& startHp, Frame *frame_arg):
    Entity(entity_type_arg, id_arg, startHp, frame_arg)
{
    ent_body->registerDynamicBox(this, pos_arg, PX_TO_M(120), PX_TO_M(160), 5.0, 0.5);
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
        shootProjectile(0, b2Vec2(0, 0), DEG_TO_RAD(0), 5);
        break;
    }
    default:
    {
        break;
    }
    }
}

void Robot::onTimerKeyState(const std::vector<bool> &keystates)
{
    if(keystates[ALLEGRO_KEY_LEFT])
    {
        ent_body->ApplyLinearImpulseAtCenter(b2Vec2(-100, 0));
    }
    if(keystates[ALLEGRO_KEY_RIGHT])
    {
        ent_body->ApplyLinearImpulseAtCenter(b2Vec2(100, 0));
    }
    if(keystates[ALLEGRO_KEY_UP])
    {
        ent_body->ApplyLinearImpulseAtCenter(b2Vec2(0, 100));
    }
    if(keystates[ALLEGRO_KEY_DOWN])
    {
        ent_body->ApplyLinearImpulseAtCenter(b2Vec2(0, -100));
    }
}

void Robot::shootProjectile(int id_arg, b2Vec2 pos_arg, float angle_arg, float linearVelocity_arg)
{
    Projectile *proj=new Projectile;
    proj->set(getPosition()+pos_arg, b2Vec2(cos(angle_arg)*linearVelocity_arg, sin(angle_arg)*linearVelocity_arg), 10000);
    proj->push(frame);
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

void Robot::transformation()
{
    preset().preTranslate(getPosition());
}

void Robot::onDraw()
{
    draw_current_frame_centered(0, 0, 0);
}

DRAWABLETYPE Robot::getDrawableType()
{
    return DRAWABLETYPE::ROBOT;
}

void Robot::beginCollision(PhysicalDrawable *other)
{
    //
}

void Robot::endCollision(PhysicalDrawable *other)
{
    //
}
