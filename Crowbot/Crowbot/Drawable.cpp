#include "resource.h"

void Drawable::push(Drawable *other)
{
    other->inner.push_back(this);
    this_position=(--other->inner.end());
    outer=other;
}

void Drawable::pull()
{
    if(outer!=nullptr)
    {
        outer->inner.erase(this_position);
        outer=nullptr;
    }
}

void Drawable::render()
{
    ALLEGRO_TRANSFORM old=*al_get_current_transform();
    if(dirty)
    {
        ALLEGRO_TRANSFORM cur;
        al_copy_transform(&cur, &old);
        transformation();
        al_compose_transform(&cur, &trans);
        al_use_transform(&cur);
        onDraw();
        for(auto &it : inner)
        {
            it->invalidate();
        }
    }
    for(auto &it: inner)
    {
        it->render();
    }
    if(dirty)
    {
        dirty=false;
        postDraw();
    }
    al_use_transform(&old);
}

Drawable& Drawable::preset()
{
    al_identity_transform(&trans);
    return *this;
}

Drawable& Drawable::preScale(float sx, float sy)
{
    al_scale_transform(&trans, sx, sy);
    return *this;
}

Drawable& Drawable::preTranslate(Pixel px)
{
    al_translate_transform(&trans, px.getX(), px.getY());
    return *this;
}

Drawable& Drawable::preTranslate(float x, float y)
{
    al_translate_transform(&trans, x, y);
    return *this;
}

Drawable& Drawable::preRotate(float theta)
{
    al_rotate_transform(&trans, theta);
    return *this;
}

Drawable& Drawable::preAll(float x, float y, float sx, float sy, float theta)
{
    al_build_transform(&trans, x, y, sx, sy, theta);
    return *this;
}

Pixel Drawable::getTransformedTL()
{
    float x=0, y=0;
    al_transform_coordinates(&trans, &x, &y);
    return Pixel(x, y);
}

ALLEGRO_TRANSFORM* Drawable::getTransform()
{
    return &trans;
}

void Drawable::invalidate()
{
    dirty=true;
}

void Drawable::invalidateRegion(const Rect& _area)
{
    const Rect area=_area.transformBy(&trans);
    if(area&rgn)
    {
        dirty=true;
        for(std::list<Drawable*>::iterator it=inner.begin(); it!=inner.end(); ++it)
            (*it)->invalidateRegion(area);
    }
}
