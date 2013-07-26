#include "resource.h"

void Robot::onKeyPress(int unichar, int keycode, unsigned int modifiers)
{
    switch(keycode)
    {
    case ALLEGRO_KEY_LEFT:
    {
        move(-4, 0);
        break;
    }
    case ALLEGRO_KEY_RIGHT:
    {
        move(4, 0);
        break;
    }
    }
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
