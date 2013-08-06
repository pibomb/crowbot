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
	EventTriggerHandler *updateTrigger;
    Entity *parent;
	int hits_left;
	int fuel_left;
	bool is_valid;
	virtual void transformation() override;
	virtual void onDraw() override;
	virtual void postDraw() override;
    virtual void setAttributes(b2Vec2 pos_arg, uint16 categoryBits, uint16 maskBits, b2Vec2 linearVelocity_arg, int fuel_left_arg, float angle_arg)=0;
public:
    Projectile(Rect region_arg, PROJECTILETYPE projectile_type_arg);
    virtual ~Projectile()
    {
        //
    }
    void set(Entity *parent_arg, b2Vec2 pos_arg, uint16 categoryBits, uint16 maskBits, b2Vec2 linearVelocity_arg, int fuel_left_arg, float angle_arg);
    bool isActive();
    bool canHit();
    virtual void beginDestroy();
    virtual void move(b2Vec2 linearVelocity_arg)=0;
    virtual void update()=0;
    virtual void destroy()=0;
};

#endif // PROJECTILE_H_INCLUDED
