#include "resource.h"

Entity::Entity(Rect region_arg, ENTITYTYPE entity_type_arg, const unsigned int& id, const int& max_health_arg, Frame *frame_arg):
    PhysicalAnimated(region_arg, resource.getData(entity_type_arg)),
    ent_health(max_health_arg),
    ent_max_health(max_health_arg),
    ent_id(id),
    is_destroying(false),
    frame(frame_arg)
{
    //
}

Entity::~Entity()
{
    //
}

Frame* Entity::getFrame()
{
    return frame;
}

b2Vec2 Entity::getPosition()
{
    return obj_body->getBody()->GetPosition();
}

float Entity::getMass()
{
    return obj_body->getBody()->GetMass();
}

float Entity::getX()
{
    return obj_body->getBody()->GetPosition().x;
}

float Entity::getY()
{
    return obj_body->getBody()->GetPosition().y;
}

void Entity::move(float x, float y)
{
    obj_body->ApplyLinearImpulseAtCenter(b2Vec2(x, y));
}

void Entity::move(b2Vec2 amt)
{
    obj_body->ApplyLinearImpulseAtCenter(amt);
}

void Entity::beginDestroy()
{
    if(!is_destroying)
    {
        is_destroying=true;
        pull();
        if(obj_body)
        {
            resource.destroyb2Resource(obj_body);
        }
        destroy();
        sysGC.watchEntity(this);
    }
}

bool Entity::isDeletable()
{
    return collisions==0;
}

void Entity::transformation()
{
    postset().postTranslate(getPosition());
}

void Entity::onDraw()
{
    draw_current_frame_centered(0, 0, 0);
}

void Entity::postDraw()
{
    ALLEGRO_BITMAP *hp_bar_bmp=resource.getImage(IMAGETYPE::HP_BAR);
    Rect region=get_current_region(acd.sequence[acd.current_sequence].start+current_count);
    al_draw_bitmap_region(hp_bar_bmp, 0, 0, al_get_bitmap_width(hp_bar_bmp)*((float)ent_health/ent_max_health), al_get_bitmap_height(hp_bar_bmp), -region.getWidth()/2, -al_get_bitmap_height(hp_bar_bmp)-region.getHeight()/2, 0);
    Rect(-region.getWidth()/2, -al_get_bitmap_height(hp_bar_bmp)-region.getHeight()/2, al_get_bitmap_width(hp_bar_bmp)-region.getWidth()/2, -region.getHeight()/2).drawBoundingBox(AL_COL_BLACK, 2);
}
