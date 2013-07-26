#include "resource.h"

void Robot::onKeyPress(int unichar, int keycode, unsigned int modifiers)
{
    switch(keycode)
    {
    case ALLEGRO_KEY_SPACE:
    {
        Projectile *proj=new Projectile();
        proj->set(ent_pos, Pixel(0, 5));
        proj->push(frame);
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

void Robot::shootProjectile(int id_arg, Pixel pos_arg, float angle_arg, float speed_arg)
{
    Projectile *proj=new Projectile();
    proj->set(ent_pos+pos_arg, Pixel(cos(angle_arg)*speed_arg, sin(angle_arg)*speed_arg));
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
    al_draw_bitmap(resource.getImage(IMAGETYPE::INVALID), 0, 0, 0);
}
