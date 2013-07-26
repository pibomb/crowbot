#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED

#include "basicresource.h"
#include "Entity.h"

class Robot : public Entity
{
private:
    std::map<std::string, std::function<void(Robot*, std::vector<int>)>> robotFunctions;
	virtual void onDraw() override;
public:
    Robot(const UINT id, Pixel position, const int startHp):
        Entity(id, position, startHp)
    {
        //
    }
    ~Robot()
    {
        //
    }
    void onKeyPress(int unichar, int keycode, unsigned int modifiers);
    void addFunction(std::string function_name, std::function<void(Robot*, std::vector<int>)> function_arg);
    void executeFunction(std::string function_name, std::vector<int> args=std::vector<int>());
};

#endif // ROBOT_H_INCLUDED
