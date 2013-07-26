#include "resource.h"

Entity::Entity(const UINT id, Pixel position, const int startHp, Frame *frame_arg):
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
