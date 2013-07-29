#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include "basicresource.h"
#include "Animated.h"
#include "Pixel.h"
#include "Event.h"
#include "ResourceSystem.h"

class Projectile : public Animated
{
private:
    PROJECTILETYPE projectile_type;
	Pixel pro_vel;
	Pixel pro_acc;
	Pixel pro_pos;
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
        pro_vel(Pixel(0, 0)),
        pro_acc(Pixel(0, 0)),
        pro_pos(Pixel(0, 0)),
        updateTrigger(nullptr),
        fuel_left(10000),
        max_vel(40.0),
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
    void set(Pixel pos_arg, Pixel acc_arg, Pixel vel_arg);
    void update();
    bool isActive();
};

#endif // PROJECTILE_H_INCLUDED
