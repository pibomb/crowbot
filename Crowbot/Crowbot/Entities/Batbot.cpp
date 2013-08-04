#include "resource.h"

Batbot::Batbot(ENTITYTYPE entity_type_arg, const unsigned int& id_arg, const b2Vec2& pos_arg, const int& startHp, Frame *frame_arg):
    Entity(entity_type_arg, id_arg, startHp, frame_arg)
{
    ent_body->registerDynamicBox(this, pos_arg, PX_TO_M(100), PX_TO_M(34), 7.85, 0.2);
    ent_body->getBody()->SetFixedRotation(true);
    ent_body->getBody()->SetGravityScale(0);
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
    static int totalcount=0;
    static int totaltotal=0;
    if(totaltotal<300 && ++totalcount>300)
    {
        make_batbot(0, b2Vec2(PX_TO_M(2000), -PX_TO_M(200)), 0, frame)->push(frame->getCamera()->midground);
        totalcount=0;
        totaltotal++;
        printf("%d\n", totaltotal);
    }
    *activeBatbot=this;
    //ent_body->ApplyLinearImpulseAtCenter(b2Vec2(-ent_body->getBody()->GetMass()/15, -ent_body->getBody()->GetMass()/15));
    lua_runlfunction(lua_state, "updatebatbot");
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
        beginDestroy();
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
