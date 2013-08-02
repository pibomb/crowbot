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

void Entity::beginDestroy()
{
    pull();
    if(ent_body)
    {
        resource.destroyb2Resource(ent_body);
    }
    destroy();
    sysGC.watchEntity(this);
}

bool Entity::isDeletable()
{
    return collisions==0;
}

void Entity::transformation()
{
    preset().preTranslate(getPosition());
}

void Entity::onDraw()
{
    draw_current_frame_centered(0, 0, 0);
}

void Entity::postDraw()
{
    //
}
