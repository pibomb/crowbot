#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED

#include "basicresource.h"
#include "Entity.h"
#include "Observer.h"

class Robot : public Entity, public Observer
{
private:
    bool facingRight;
    std::map<std::string, std::function<void(Robot*, std::vector<int>)>> robotFunctions;
	void onDraw() override;
public:
    int touchingGround;
    Robot(ENTITYTYPE entity_type_arg, const unsigned int& id_arg, const b2Vec2& pos_arg, const int& startHp, Frame *frame_arg);
    ~Robot()
    {
        //
    }
    void shootProjectile(b2Vec2 pos_arg, float angle_arg, float linearVelocity_arg);
    void addFunction(std::string function_name, std::function<void(Robot*, std::vector<int>)> function_arg);
    void executeFunction(std::string function_name, std::vector<int> args=std::vector<int>());
    void onKeyPress(int unichar, int keycode, unsigned int modifiers) override;
    void onKeyRelease(int unichar, int keycode, unsigned int modifiers) override;
    void onMouseClick(int x_pos, int y_pos) override;
    void onTimerKeyState(const std::vector<bool> &keystates) override;
    void destroy() override;
    DRAWABLETYPE getDrawableType() override;
	void beginCollision(PhysicalDrawable *other) override;
	void endCollision(PhysicalDrawable *other) override;
};

#endif // ROBOT_H_INCLUDED
