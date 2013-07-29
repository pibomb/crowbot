#include "resource.h"

void Projectile::set(Pixel pos_arg, Pixel vel_arg)
{
    is_valid=true;
    pro_pos=pos_arg;
    pro_vel=vel_arg;
    updateTrigger=new EventTriggerHandler(
                                        [this]()
                                        {
                                            this->update();
                                        });
    updateTrigger->push(sysEvents[EVENTTYPE::TIMER]);
    updateTrigger->add(EVENTTYPE::TIMER);
    sysGC.watchProjectile(this);
}

void Projectile::update()
{
    if(is_valid)
    {
        if(!is_pixel_onscreen(pro_pos))
        {
            is_valid=false;
            pro_vel.setAll(0, 0);
            pull();
        }
        else
        {
            pro_pos+=pro_vel;
        }
    }
}

void Projectile::transformation()
{
    preset().preTranslate(pro_pos);
}

void Projectile::onDraw()
{
    if(is_valid)
    {
        draw_current_frame(0, 0, 0);
    }
}

void Projectile::postDraw()
{
    //
}

bool Projectile::isActive()
{
    return is_valid;
}
