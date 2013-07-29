#include "resource.h"

void Projectile::set(Pixel pos_arg, Pixel acc_arg, Pixel vel_arg)
{
    is_valid=true;
    pro_pos=pos_arg;
    pro_acc=acc_arg;
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
            float dist=pro_vel.getDist();
            if(dist!=max_vel)
            {
                if(dist<max_vel)
                {
                    pro_vel+=pro_acc;
                }
                else
                {
                    float theta=atan2(pro_acc.getY(), pro_acc.getX());
                    pro_acc.setAll(0, 0);
                    if(theta<0)
                    {
                        theta+=180.0;
                    }
                    pro_vel.setAll(sin(M_PI/2-theta)*max_vel, sin(theta)*max_vel);
                }
            }
            pro_pos+=pro_vel;
            fuel_left-=sqrt(pro_vel.getDist())*80;
            printf("Dist: %f Fuel: %d\n", pro_vel.getDist(), fuel_left);
            if(fuel_left<=0.0)
            {
                is_valid=false;
                pro_vel.setAll(0, 0);
                pull();
            }
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
