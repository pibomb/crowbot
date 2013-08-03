#ifndef BATBOT_H_INCLUDED
#define BATBOT_H_INCLUDED

#include "basicresource.h"
#include "Entity.h"

class EventTriggerHandler;

class Batbot : public Entity
{
private:
    EventTriggerHandler *updateTrigger;
public:
    Batbot(ENTITYTYPE entity_type_arg, const unsigned int& id_arg, const b2Vec2& pos_arg, const int& startHp, Frame *frame_arg);
    ~Batbot();
    void update();
    void destroy() override;
    DRAWABLETYPE getDrawableType() override;
	void beginCollision(PhysicalDrawable *other) override;
	void endCollision(PhysicalDrawable *other) override;
};

#endif // BATBOT_H_INCLUDED
