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
    Robot(ENTITYTYPE entity_type_arg, const unsigned int& id, const Vec2& position, const int& startHp, Frame *frame_arg):
        Entity(entity_type_arg, id, position, startHp, frame_arg)
    {
        //
    }
    ~Robot()
    {
        //
    }
    void onKeyPress(int unichar, int keycode, unsigned int modifiers);
    void onTimerKeyState(const std::vector<bool> &keystates);
    void shootProjectile(int id_arg, b2Vec2 pos_arg, float angle_arg, float linearVelocity_arg);
    void addFunction(std::string function_name, std::function<void(Robot*, std::vector<int>)> function_arg);
    void executeFunction(std::string function_name, std::vector<int> args=std::vector<int>());
    DRAWABLETYPE getDrawableType();
	virtual void beginCollision(PhysicalDrawable *other) override;
	virtual void endCollision(PhysicalDrawable *other) override;
};

#endif // ROBOT_H_INCLUDED
