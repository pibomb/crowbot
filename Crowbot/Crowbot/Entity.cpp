#include "resource.h"

Entity::Entity(const unsigned int& id, const Vec2& position, const int& startHp, Frame *frame_arg):
    ent_pos(position),
    ent_health(startHp),
    ent_id(id),
    frame(frame_arg)
{
    //
}

Entity::~Entity()
{
    //
}

void Entity::transformation()
{
	preset().preTranslate(ent_pos);
}

void Entity::onDraw()
{
    //
}

void Entity::postDraw()
{
    //
}
