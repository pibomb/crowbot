#include "resource.h"

void Robot::onKeyPress(int unichar, int keycode, unsigned int modifiers)
{
    switch(keycode)
    {
    case ALLEGRO_KEY_W:
    {
        shootProjectile(0, Vec2(0, 0), DEG_TO_RAD(270), 5);
        break;
    }
    case ALLEGRO_KEY_A:
    {
        shootProjectile(0, Vec2(0, 0), DEG_TO_RAD(180), 5);
        break;
    }
    case ALLEGRO_KEY_S:
    {
        shootProjectile(0, Vec2(0, 0), DEG_TO_RAD(90), 5);
        break;
    }
    case ALLEGRO_KEY_D:
    {
        shootProjectile(0, Vec2(0, 0), DEG_TO_RAD(0), 10);
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
        move(-4, 0);
    }
    if(keystates[ALLEGRO_KEY_RIGHT])
    {
        move(4, 0);
    }
    if(keystates[ALLEGRO_KEY_UP])
    {
        move(0, -4);
    }
    if(keystates[ALLEGRO_KEY_DOWN])
    {
        move(0, 4);
    }
}

void Robot::shootProjectile(int id_arg, Vec2 pos_arg, float angle_arg, float speed_arg)
{
    Projectile *proj=new Projectile;
    proj->set(ent_pos+pos_arg, Vec2(cos(angle_arg)*speed_arg, sin(angle_arg)*speed_arg), Vec2(0, 0), 10000, 19.0);
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

void Robot::onDraw()
{
    draw_current_frame(0, 0, 0);
}
