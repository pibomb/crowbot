#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED

#include "basicresource.h"
#include "Entity.h"
#include "Observer.h"

class Robot : public Entity, public Observer
{
private:
    std::map<std::string, std::function<void(Robot*, std::vector<int>)>> robotFunctions;
	virtual void onDraw() override;
public:
    Robot(const UINT id, Pixel position, const int startHp, Frame *frame_arg):
        Entity(id, position, startHp, frame_arg)
    {
        //
    }
    ~Robot()
    {
        //
    }
    void onKeyPress(int unichar, int keycode, unsigned int modifiers);
    void onTimerKeyState(const std::vector<bool> &keystates);
    void shootProjectile(int id_arg, Pixel pos_arg, float angle_arg, float speed_arg);
    void addFunction(std::string function_name, std::function<void(Robot*, std::vector<int>)> function_arg);
    void executeFunction(std::string function_name, std::vector<int> args=std::vector<int>());
};

#endif // ROBOT_H_INCLUDED
