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

b2Vec2 Entity::getPosition()
{
    return ent_body->getBody()->GetPosition();
}

float Entity::getMass()
{
    return ent_body->getBody()->GetMass();
}

float Entity::getX()
{
    return ent_body->getBody()->GetPosition().x;
}

float Entity::getY()
{
    return ent_body->getBody()->GetPosition().y;
}

void Entity::move(float x, float y)
{
    ent_body->ApplyLinearImpulseAtCenter(b2Vec2(x, y));
}

void Entity::move(b2Vec2 amt)
{
    ent_body->ApplyLinearImpulseAtCenter(amt);
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
