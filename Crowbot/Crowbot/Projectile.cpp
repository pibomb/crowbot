#include "resource.h"

void Projectile::set(Vec2 pos_arg, Vec2 acc_arg, Vec2 vel_arg, int fuel_left_arg, float mass_arg)
{
    is_valid=true;
    pro_pos=pos_arg;
    pro_acc=acc_arg;
    pro_vel=vel_arg;
    fuel_left=fuel_left_arg;
    pro_mass=mass_arg;
    max_vel=sqrt(2*(mass_arg*(acc_arg.magnitude()+9.8))/1.1839/10/0.04);
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
                    /*
                    pro_vel.scaleMag(atan2(pro_vel.getY(), pro_vel.getX()), 1.2*pro_vel.magnitude()*0.04*10/2/pro_mass);
                    pro_vel.add(0, 9.8/60.0);
                    */
                    pro_vel+=(pro_acc/60.0);
                }
                else
                {
                    pro_vel.scaleMag(atan2(pro_acc.getY(), pro_acc.getX()), max_vel);
                }
            }
            pro_pos+=pro_vel;
            fuel_left-=100;
            //printf("Dist: %f Fuel: %d Force: %f Energy: %f\n", pro_vel.magnitude(), fuel_left, force(), kenergy());
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

float Projectile::force()
{
    return pro_mass*pro_acc.magnitude();
}

float Projectile::kenergy()
{
    return pro_mass*pro_vel.magnitudeSquared()/2;
}
