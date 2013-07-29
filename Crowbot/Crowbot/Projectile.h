#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include "basicresource.h"
#include "Animated.h"
#include "Physics.h"
#include "Event.h"
#include "ResourceSystem.h"

class Projectile : public Animated
{
private:
    PROJECTILETYPE projectile_type;
	Vec2 pro_vel;
	Vec2 pro_acc;
	Vec2 pro_pos;
	EventTriggerHandler *updateTrigger;
	int reserved;
	int fuel_left;
	float max_vel;
	bool is_valid;
	void transformation() override;
	void onDraw() override;
	void postDraw() override;
public:
    Projectile(PROJECTILETYPE projectile_type_arg=PROJECTILETYPE::BULLET):
        Animated(resource.getData(projectile_type_arg)),
        projectile_type(projectile_type_arg),
        pro_vel(Vec2(0, 0)),
        pro_acc(Vec2(0, 0)),
        pro_pos(Vec2(0, 0)),
        updateTrigger(nullptr),
        fuel_left(0),
        max_vel(0.0),
        is_valid(false)
    {
        //
    }
    ~Projectile()
    {
        if(updateTrigger)
        {
            updateTrigger->destroy();
            delete updateTrigger;
        }
    }
    void set(Vec2 pos_arg, Vec2 acc_arg, Vec2 vel_arg, int fuel_left_arg, float max_vel_arg);
    void update();
    bool isActive();
};

#endif // PROJECTILE_H_INCLUDED
