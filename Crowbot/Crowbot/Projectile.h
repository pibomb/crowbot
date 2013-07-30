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
    b2Vec2 pro_pos;
    b2Body *pro_body;
	EventTriggerHandler *updateTrigger;
	int reserved;
	int fuel_left;
	bool is_valid;
	void transformation() override;
	void onDraw() override;
	void postDraw() override;
public:
    Projectile(PROJECTILETYPE projectile_type_arg=PROJECTILETYPE::BULLET):
        Animated(resource.getData(projectile_type_arg)),
        projectile_type(projectile_type_arg),
        pro_pos(b2Vec2(0.0, 0.0)),
        pro_body(nullptr),
        updateTrigger(nullptr),
        fuel_left(0),
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
        if(pro_body)
        {
            world.DestroyBody(pro_body);
        }
    }
    void set(b2Vec2 pos_arg, b2Vec2 linearVelocity_arg, int fuel_left_arg);
    void update();
    bool isActive();
};

#endif // PROJECTILE_H_INCLUDED
