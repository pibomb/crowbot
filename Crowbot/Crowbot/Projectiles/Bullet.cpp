#include "resource.h"

void Bullet::move(b2Vec2 linearVelocity_arg)
{
    pro_body->ApplyLinearImpulseAtCenter(linearVelocity_arg);
}

void Bullet::update()
{
    if(isActive())
    {
        *activeBullet=this;
        //lua_runlfunction(lua_state, "updatebullet", pro_body->getBody()->GetPosition().x, pro_body->getBody()->GetPosition().y);
        /*
        if(!is_pixel_onscreen(pro_body->getBody()->GetPosition()))
        {
            destroy();
        }
        */
    }
}

void Bullet::destroy()
{
    if(isActive())
    {
        is_valid=false;
        pull();
        if(updateTrigger)
        {
            sysGC.watchEventHandler(updateTrigger);
        }
        if(pro_body)
        {
            resource.destroyb2Resource(pro_body);
        }
    }
}

void Bullet::setAttributes(b2Vec2 pos_arg, b2Vec2 linearVelocity_arg, int fuel_left_arg, float angle_arg)
{
    pro_body->registerDynamicBox(this, pos_arg, PX_TO_M(16), PX_TO_M(6), 1.0, 0.3);
    //pro_body->getBody()->SetGravityScale(0);
    pro_body->getBody()->SetBullet(true);
    pro_body->getBody()->SetTransform(pro_body->getBody()->GetPosition(), angle_arg);
    pro_body->ApplyLinearImpulseAtCenter(linearVelocity_arg);
}

void Bullet::beginCollision(PhysicalDrawable *other)
{
    switch(other->getDrawableType())
    {
    case DRAWABLETYPE::ROBOT:
    case DRAWABLETYPE::CHAIN:
    case DRAWABLETYPE::BOX:
    {
        destroy();
        break;
    }
    default:
    {
        break;
    }
    }
}

void Bullet::endCollision(PhysicalDrawable *other)
{
    //
}
