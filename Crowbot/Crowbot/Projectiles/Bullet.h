#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "basicresource.h"
#include "Projectile.h"

class Bullet : public Projectile
{
private:
    void setAttributes(b2Vec2 pos_arg, b2Vec2 linearVelocity_arg, int fuel_left_arg, float angle_arg) override;
public:
    Bullet(PROJECTILETYPE projectile_type_arg=PROJECTILETYPE::BULLET):
        Projectile(projectile_type_arg)
    {
        //
    }
    void move(b2Vec2 linearVelocity_arg) override;
    void update() override;
    void destroy() override;
	virtual void beginCollision(PhysicalDrawable *other) override;
	virtual void endCollision(PhysicalDrawable *other) override;
};

#endif // BULLET_H_INCLUDED
