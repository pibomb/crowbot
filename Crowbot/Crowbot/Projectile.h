#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include "basicresource.h"
#include "Animated.h"
#include "Physics.h"
#include "Event.h"
#include "ResourceSystem.h"

class Projectile : public PhysicalAnimated
{
private:
    PROJECTILETYPE projectile_type;
    b2Resource *pro_body;
	EventTriggerHandler *updateTrigger;
	int reserved;
	int fuel_left;
	bool is_valid;
	void transformation() override;
	void onDraw() override;
	void postDraw() override;
public:
    Projectile(PROJECTILETYPE projectile_type_arg=PROJECTILETYPE::BULLET):
        PhysicalAnimated(resource.getData(projectile_type_arg)),
        projectile_type(projectile_type_arg),
        pro_body(nullptr),
        updateTrigger(nullptr),
        fuel_left(0),
        is_valid(false)
    {
        //
    }
    ~Projectile()
    {
        //
    }
    void set(b2Vec2 pos_arg, b2Vec2 linearVelocity_arg, int fuel_left_arg);
    void move(b2Vec2 linearVelocity_arg);
    void update();
    void destroy();
    bool isActive();
    DRAWABLETYPE getDrawableType() override;
	virtual void beginCollision(PhysicalDrawable *other) override;
	virtual void endCollision(PhysicalDrawable *other) override;
};

#endif // PROJECTILE_H_INCLUDED
