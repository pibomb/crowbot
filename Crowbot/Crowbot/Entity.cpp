#include "resource.h"

Entity::Entity(const UINT& id, Pixel& position, const UINT& startHp) : ent_id(id), ent_pos(position), ent_health(startHp)
{
}

void Entity::transformation()
{
	preset().preTranslate(Pixel(ent_pos.getX(), ent_pos.getY()));
}

void Entity::onDraw()
{
}

void Entity::postDraw()
{
}