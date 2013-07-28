#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include "basicresource.h"
#include "Drawable.h"
#include "Pixel.h"
#include "Event.h"

class Projectile : public Drawable
{
private:
	Pixel pro_vel;
	Pixel pro_pos;
	EventTriggerHandler *updateTrigger;
	int reserved;
	bool is_valid;
	void transformation() override;
	void onDraw() override;
	void postDraw() override;
public:
    Projectile():
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
