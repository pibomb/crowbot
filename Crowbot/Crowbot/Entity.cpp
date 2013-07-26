#include "resource.h"

Entity::Entity(const UINT id, Pixel position, const int startHp):
    ent_pos(position),
    ent_health(startHp),
    ent_id(id)
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
