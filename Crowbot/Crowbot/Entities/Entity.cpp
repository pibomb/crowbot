#include "resource.h"

Entity::Entity(ENTITYTYPE entity_type_arg, const unsigned int& id, const int& startHp, Frame *frame_arg):
    PhysicalAnimated(resource.getData(entity_type_arg)),
    ent_body(resource.createb2Resource()),
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
	preset();
}

void Entity::postDraw()
{
    //
}
