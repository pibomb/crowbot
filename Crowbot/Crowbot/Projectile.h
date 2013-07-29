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
	Pixel pro_pos;
	EventTriggerHandler *updateTrigger;
	int reserved;
	bool is_valid;
	void transformation() override;
	void onDraw() override;
	void postDraw() override;
public:
    Projectile(PROJECTILETYPE projectile_type_arg=PROJECTILETYPE::BULLET):
        Animated(resource.getData(projectile_type_arg)),
        projectile_type(projectile_type_arg),
        pro_vel(Pixel(0, 0)),
        pro_pos(Pixel(0, 0)),
        updateTrigger(nullptr),
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
    void set(Pixel pos_arg, Pixel vel_arg);
    void update();
    bool isActive();
};

#endif // PROJECTILE_H_INCLUDED
