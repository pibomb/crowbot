#include "resource.h"

Missile::Missile(PROJECTILETYPE projectile_type_arg):
    Projectile(Rect(0, 0, 48, 12), projectile_type_arg)
{
    //
}

DRAWABLETYPE Missile::getDrawableType()
{
    return DRAWABLETYPE::MISSILE;
}

void Missile::move(b2Vec2 linearVelocity_arg)
{
    obj_body->ApplyLinearImpulseAtCenter(linearVelocity_arg);
}

void Missile::update()
{
    if(isActive())
    {
        if(fuel_left<=0)
        {
            beginDestroy();
        }
        else
        {
            *activeMissile=this;
            obj_body->ApplyLinearImpulseAtCenter(b2Vec2(0.1, 0.01));
            fuel_left-=100;
        }
        //lua_runlfunction(lua_state, "updatemissile", obj_body->getBody()->GetPosition().x, obj_body->getBody()->GetPosition().y);
        /*
        if(!is_pixel_onscreen(obj_body->getBody()->GetPosition()))
        {
            beginDestroy();
        }
        */
    }
}

void Missile::destroy()
{
    //
}

void Missile::transformation()
{
    if(isActive())
    {
        b2Vec2 linearVelocity=obj_body->getBody()->GetLinearVelocity();
        preset().preRotate(DEG_TO_RAD(360)-atan2(linearVelocity.y, linearVelocity.x));
        postset().postTranslate(obj_body->getBody()->GetPosition());
    }
}

void Missile::setAttributes(b2Vec2 pos_arg, uint16 categoryBits, uint16 maskBits, b2Vec2 linearVelocity_arg, int fuel_left_arg, float angle_arg)
{
    obj_body->registerDynamicBox(this, pos_arg, categoryBits, maskBits, PX_TO_M(16), PX_TO_M(6), 1.0, 0.3);
    obj_body->getBody()->SetGravityScale(0);
    obj_body->getBody()->SetBullet(true);
    obj_body->getBody()->SetTransform(obj_body->getBody()->GetPosition(), DEG_TO_RAD(360)-angle_arg);
    obj_body->ApplyLinearImpulseAtCenter(linearVelocity_arg);
    hits_left=1;
}

void Missile::beginCollision(PhysicalDrawable *other)
{
    //beginDestroy();
}

void Missile::endCollision(PhysicalDrawable *other)
{
    //
}
