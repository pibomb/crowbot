#include "resource.h"

Batbot::Batbot(ENTITYTYPE entity_type_arg, const unsigned int& id_arg, const b2Vec2& pos_arg, const int& startHp, Frame *frame_arg):
    Entity(Rect(0, 0, 100, 34), entity_type_arg, id_arg, startHp, frame_arg)
{
    obj_body->registerDynamicBox(this, pos_arg, PHYSICAL_ENEMY, PHYSICAL_ALL&~PHYSICAL_ENEMY, PX_TO_M(100), PX_TO_M(34), 7.85, 0.2);
    obj_body->getBody()->SetFixedRotation(true);
    obj_body->getBody()->SetGravityScale(0);
    updateTrigger=new EventTriggerHandler(
                                        [this]()
                                        {
                                            this->update();
                                        });
    updateTrigger->push(sysEvents[EVENTTYPE::TIMER]);
    updateTrigger->add(EVENTTYPE::TIMER);
}

Batbot::~Batbot()
{
    //
}

void Batbot::update()
{
    if(isAlive())
    {
        *activeBatbot=this;
        //obj_body->ApplyLinearImpulseAtCenter(b2Vec2(-obj_body->getBody()->GetMass()/15, -obj_body->getBody()->GetMass()/15));
        lua_runlfunction(lua_state, "updatebatbot");
    }
    else
    {
        beginDestroy();
    }
}

void Batbot::shootProjectile(b2Vec2 pos_arg, float angle_arg, float linearVelocity_arg)
{
    make_bullet(this, getPosition()+pos_arg, PHYSICAL_ENEMY, PHYSICAL_ALL&~PHYSICAL_ENEMY, angle_arg, linearVelocity_arg);
}

void Batbot::destroy()
{
    if(updateTrigger)
    {
        sysGC.watchEventHandler(updateTrigger);
    }
}

DRAWABLETYPE Batbot::getDrawableType()
{
    return DRAWABLETYPE::BATBOT;
}

void Batbot::beginCollision(PhysicalDrawable *other)
{
    switch(other->getDrawableType())
    {
    case DRAWABLETYPE::BULLET:
    {
        if(static_cast<Bullet*>(other)->canHit())
        {
            setHp(-2);
        }
        break;
    }
    default:
    {
        break;
    }
    }
}

void Batbot::endCollision(PhysicalDrawable *other)
{
    //
}
