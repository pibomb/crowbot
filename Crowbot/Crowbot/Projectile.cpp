#include "resource.h"

void Projectile::set(b2Vec2 pos_arg, b2Vec2 linearVelocity_arg, int fuel_left_arg)
{
    is_valid=true;
    fuel_left=fuel_left_arg;
    pro_body=resource.createb2Resource();
    pro_body->registerDynamicBox(this, pos_arg, PX_TO_M(15), PX_TO_M(5), 1.0, 0.3);
    pro_body->getBody()->SetBullet(true);
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

void Projectile::update()
{
    if(isActive())
    {
        if(!is_pixel_onscreen(pro_body->getBody()->GetPosition()))
        {
            destroy();
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
        preset().preTranslate(pro_body->getBody()->GetPosition()).preRotate(pro_body->getBody()->GetAngle());
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
    if(other->getDrawableType()==DRAWABLETYPE::BULLET)
    {
        destroy();
    }
}

void Projectile::endCollision(PhysicalDrawable *other)
{
    //
}
