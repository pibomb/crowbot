#ifndef MISSILE_H_INCLUDED
#define MISSILE_H_INCLUDED

#include "basicresource.h"
#include "Projectile.h"

class Missile : public Projectile
{
private:
    void transformation() override;
    void setAttributes(b2Vec2 pos_arg, uint16 categoryBits, uint16 maskBits, b2Vec2 linearVelocity_arg, int fuel_left_arg, float angle_arg) override;
public:
    Missile(PROJECTILETYPE projectile_type_arg=PROJECTILETYPE::MISSILE);
    DRAWABLETYPE getDrawableType() override;
    void move(b2Vec2 linearVelocity_arg) override;
    void update() override;
    void destroy() override;
	virtual void beginCollision(PhysicalDrawable *other) override;
	virtual void endCollision(PhysicalDrawable *other) override;
};

#endif // MISSILE_H_INCLUDED
