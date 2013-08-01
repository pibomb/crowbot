#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include "basicresource.h"
#include "Animated.h"
#include "Physics.h"
#include "Event.h"
#include "ResourceSystem.h"

class Projectile : public PhysicalAnimated
{
protected:
    PROJECTILETYPE projectile_type;
    b2Resource *pro_body;
	EventTriggerHandler *updateTrigger;
	int reserved;
	int fuel_left;
	bool is_valid;
	void transformation() override;
	void onDraw() override;
	void postDraw() override;
    virtual void setAttributes(b2Vec2 pos_arg, b2Vec2 linearVelocity_arg, int fuel_left_arg, float angle_arg)=0;
public:
    Projectile(PROJECTILETYPE projectile_type_arg):
        PhysicalAnimated(resource.getData(projectile_type_arg)),
        projectile_type(projectile_type_arg),
        pro_body(nullptr),
        updateTrigger(nullptr),
        fuel_left(0),
        is_valid(false)
    {
        //
    }
    virtual ~Projectile()
    {
        //
    }
    void set(b2Vec2 pos_arg, b2Vec2 linearVelocity_arg, int fuel_left_arg, float angle_arg);
    bool isActive();
    DRAWABLETYPE getDrawableType() override;
    virtual void move(b2Vec2 linearVelocity_arg)=0;
    virtual void update()=0;
    virtual void destroy()=0;
};

#endif // PROJECTILE_H_INCLUDED
