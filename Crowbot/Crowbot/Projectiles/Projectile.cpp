#include "resource.h"

void Projectile::set(Entity *parent_arg, b2Vec2 pos_arg, b2Vec2 linearVelocity_arg, int fuel_left_arg, float angle_arg)
{
    is_valid=true;
    fuel_left=fuel_left_arg;
    pro_body=resource.createb2Resource();
    parent=parent_arg;
    setAttributes(pos_arg, linearVelocity_arg, fuel_left_arg, angle_arg);
    updateTrigger=new EventTriggerHandler(
                                        [this]()
                                        {
                                            this->update();
                                        });
    updateTrigger->push(sysEvents[EVENTTYPE::TIMER]);
    updateTrigger->add(EVENTTYPE::TIMER);
    sysGC.watchProjectile(this);
}

bool Projectile::isActive()
{
    return is_valid;
}

bool Projectile::canHit()
{
    if(hits_left>0)
    {
        hits_left--;
        return true;
    }
    return false;
}

void Projectile::transformation()
{
    if(isActive())
    {
        preset().preRotate(pro_body->getBody()->GetAngle());
        postset().postTranslate(pro_body->getBody()->GetPosition());
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

void Projectile::beginDestroy()
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
        destroy();
    }
}
