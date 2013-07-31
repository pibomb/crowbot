#include "resource.h"

void Projectile::set(b2Vec2 pos_arg, b2Vec2 linearVelocity_arg, int fuel_left_arg, float angle_arg)
{
    is_valid=true;
    fuel_left=fuel_left_arg;
    pro_body=resource.createb2Resource();
    pro_body->registerDynamicBox(this, pos_arg, PX_TO_M(16), PX_TO_M(6), 1.0, 0.3);
    //pro_body->getBody()->SetGravityScale(0);
    pro_body->getBody()->SetBullet(true);
    pro_body->getBody()->SetTransform(pro_body->getBody()->GetPosition(), angle_arg);
    pro_body->ApplyLinearImpulseAtCenter(linearVelocity_arg);
    updateTrigger=new EventTriggerHandler(
                                        [this]()
                                        {
                                            this->update();
                                        });
    updateTrigger->push(sysEvents[EVENTTYPE::TIMER]);
    updateTrigger->add(EVENTTYPE::TIMER);
    sysGC.watchProjectile(this);
}

void Projectile::move(b2Vec2 linearVelocity_arg)
{
    pro_body->ApplyLinearImpulseAtCenter(linearVelocity_arg);
}

void Projectile::update()
{
    if(isActive())
    {
        *activeBullet=this;
        //lua_runlfunction(lua_state, "updatebullet", pro_body->getBody()->GetPosition().x, pro_body->getBody()->GetPosition().y);
        if(!is_pixel_onscreen(pro_body->getBody()->GetPosition()))
        {
            destroy();
        }
    }
}

void Projectile::destroy()
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

bool Projectile::isActive()
{
    return is_valid;
}

void Projectile::transformation()
{
    if(isActive())
    {
        preset().preRotate(pro_body->getBody()->GetAngle()).preTranslate(pro_body->getBody()->GetPosition());
    }
}

void Projectile::onDraw()
{
    if(isActive())
    {
        draw_current_frame_centered(0, 0, 0);
    }
}

void Projectile::postDraw()
{
    //
}

DRAWABLETYPE Projectile::getDrawableType()
{
    return DRAWABLETYPE::BULLET;
}

void Projectile::beginCollision(PhysicalDrawable *other)
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

void Projectile::endCollision(PhysicalDrawable *other)
{
    //
}
