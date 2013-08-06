#include "resource.h"

Bullet::Bullet(PROJECTILETYPE projectile_type_arg):
    Projectile(Rect(0, 0, 16, 6), projectile_type_arg)
{
    //
}

DRAWABLETYPE Bullet::getDrawableType()
{
    return DRAWABLETYPE::BULLET;
}

void Bullet::move(b2Vec2 linearVelocity_arg)
{
    obj_body->ApplyLinearImpulseAtCenter(linearVelocity_arg);
}

void Bullet::update()
{
    if(isActive())
    {
        *activeBullet=this;
        //lua_runlfunction(lua_state, "updatebullet", obj_body->getBody()->GetPosition().x, obj_body->getBody()->GetPosition().y);
        /*
        if(!is_pixel_onscreen(obj_body->getBody()->GetPosition()))
        {
            beginDestroy();
        }
        */
    }
}

void Bullet::destroy()
{
    //
}

void Bullet::setAttributes(b2Vec2 pos_arg, uint16 categoryBits, uint16 maskBits, b2Vec2 linearVelocity_arg, int fuel_left_arg, float angle_arg)
{
    obj_body->registerDynamicBox(this, pos_arg, categoryBits, maskBits, PX_TO_M(16), PX_TO_M(6), 1.0, 0.3);
    //obj_body->getBody()->SetGravityScale(0);
    obj_body->getBody()->SetBullet(true);
    obj_body->getBody()->SetTransform(obj_body->getBody()->GetPosition(), DEG_TO_RAD(360)-angle_arg);
    obj_body->ApplyLinearImpulseAtCenter(linearVelocity_arg);
    hits_left=1;
}

void Bullet::beginCollision(PhysicalDrawable *other)
{
    beginDestroy();
}

void Bullet::endCollision(PhysicalDrawable *other)
{
    //
}
