#include "resource.h"

void Projectile::set(Vec2 pos_arg, Vec2 acc_arg, Vec2 vel_arg, int fuel_left_arg, float max_vel_arg)
{
    is_valid=true;
    pro_pos=pos_arg;
    pro_acc=acc_arg;
    pro_vel=vel_arg;
    fuel_left=fuel_left_arg;
    max_vel=max_vel_arg;
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
            float dist=pro_vel.magnitude();
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
            fuel_left-=log(pro_vel.magnitude())*128;
            //printf("Dist: %f Fuel: %d\n", pro_vel.magnitude(), fuel_left);
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
