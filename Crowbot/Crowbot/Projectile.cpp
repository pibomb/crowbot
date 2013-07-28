#include "resource.h"

void Projectile::set(Pixel pos_arg, Pixel vel_arg)
{
    is_valid=true;
    pro_pos=pos_arg;
    pro_vel=vel_arg;
    EventTriggerHandler *evtrig=new EventTriggerHandler([this]()
                                           {
                                               this->update();
                                           });
    sysEvents.addEventHandler(evtrig);
    evtrig->push(sysEvents[EVENTTYPE::TIMER]);
    evtrig->add(EVENTTYPE::TIMER);
    sysGC.watchProjectile(this);
}

void Projectile::update()
{
    if(!is_pixel_onscreen(pro_pos))
    {
        is_valid=false;
        pull();
    }
    else
    {
        pro_pos+=pro_vel;
    }
}

void Projectile::transformation()
{
    preset().preTranslate(pro_pos);
}

void Projectile::onDraw()
{
    //
}

void Projectile::postDraw()
{
    if(is_valid)
    {
        Rect(0, 0, 50, 50).render(AL_COL_RED);
    }
    else
    {
        pro_vel=Pixel(0, 0);
    }
}

bool Projectile::isActive()
{
    return is_valid;
}
