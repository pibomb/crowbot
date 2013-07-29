#include "resource.h"

Entity::Entity(ENTITYTYPE entity_type_arg, const unsigned int& id, const Vec2& position, const int& startHp, Frame *frame_arg):
    Animated(resource.getData(entity_type_arg)),
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
    draw_current_frame(0, 0, 0);
}

void Entity::postDraw()
{
    //
}
