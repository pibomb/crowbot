#include "resource.h"

void Projectile::set(b2Vec2 pos_arg, b2Vec2 linearVelocity_arg, int fuel_left_arg)
{
    is_valid=true;
    fuel_left=fuel_left_arg;

    b2BodyDef bodyDef;
    bodyDef.type=b2_dynamicBody;
    bodyDef.position=pos_arg;
    pro_body=world.CreateBody(&bodyDef);
    b2FixtureDef fixtureDef;
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(PX_TO_M(50.0), PX_TO_M(40.0));
    fixtureDef.shape=&dynamicBox;
    fixtureDef.density=1.0f;
    fixtureDef.friction=0.3f;
    pro_body->CreateFixture(&fixtureDef);
    pro_body->SetBullet(true);
    pro_body->SetGravityScale(0);
    //pro_body->ApplyLinearImpulse(linearVelocity_arg, pro_body->GetWorldCenter());
    b2Vec2 impulse = b2Vec2(5.0, 5.0);
    b2Vec2 bodyCenter = pro_body->GetWorldCenter();
    pro_body->ApplyLinearImpulse(impulse, bodyCenter);
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
    if(isActive())
    {
        pro_pos=pro_body->GetPosition();
        if(!is_pixel_onscreen(pro_pos))
        {
            is_valid=false;
            pull();
        }
    }
}

void Projectile::transformation()
{
    if(isActive())
    {
        preset().preTranslate(pro_pos).preRotate(pro_body->GetAngle());
    }
}

void Projectile::onDraw()
{
    if(isActive())
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
