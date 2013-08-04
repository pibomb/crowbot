#include "resource.h"

void Drawable::push(Drawable *other)
{
    other->inner.push_back(this);
    drawable_this_position=(--other->inner.end());
    drawable_outer=other;
}

void Drawable::pull()
{
    if(drawable_outer)
    {
        drawable_outer->inner.erase(drawable_this_position);
        drawable_outer=nullptr;
    }
}

void Drawable::decompose()
{
    for(auto &it : inner)
    {
        it->drawable_outer=nullptr;
        it->decompose();
    }
    inner.clear();
}

void Drawable::render()
{
    ALLEGRO_TRANSFORM old=*al_get_current_transform();
    if(drawable_is_dirty)
    {
        drawable_is_dirty=false;
        ALLEGRO_TRANSFORM cur;
        transformation();
        al_copy_transform(&cur, &drawable_pre_trans);
        al_compose_transform(&cur, &old);
        al_compose_transform(&cur, &drawable_post_trans);
        al_use_transform(&cur);
        onDraw();
        for(auto &it : inner)
        {
            it->invalidate();
            it->render();
        }
        postDraw();
    }
    else
    {
        for(auto &it : inner)
        {
            it->render();
        }
    }
    al_use_transform(&old);
}

Drawable& Drawable::preset()
{
    al_identity_transform(&drawable_pre_trans);
    return *this;
}

Drawable& Drawable::postset()
{
    al_identity_transform(&drawable_post_trans);
    return *this;
}

Drawable& Drawable::preScale(float sx, float sy)
{
    al_scale_transform(&drawable_pre_trans, sx, sy);
    return *this;
}

Drawable& Drawable::postScale(float sx, float sy)
{
    al_scale_transform(&drawable_post_trans, sx, sy);
    return *this;
}

Drawable& Drawable::preTranslate(Pixel px)
{
    al_translate_transform(&drawable_pre_trans, px.getX(), px.getY());
    return *this;
}

Drawable& Drawable::postTranslate(Pixel px)
{
    al_translate_transform(&drawable_post_trans, px.getX(), px.getY());
    return *this;
}

Drawable& Drawable::preTranslate(Vec2 px)
{
    al_translate_transform(&drawable_pre_trans, px.getX(), px.getY());
    return *this;
}

Drawable& Drawable::postTranslate(Vec2 px)
{
    al_translate_transform(&drawable_post_trans, px.getX(), px.getY());
    return *this;
}

Drawable& Drawable::preTranslate(b2Vec2 px)
{
    al_translate_transform(&drawable_pre_trans, M_TO_PX(px.x), -M_TO_PX(px.y));
    return *this;
}

Drawable& Drawable::postTranslate(b2Vec2 px)
{
    al_translate_transform(&drawable_post_trans, M_TO_PX(px.x), -M_TO_PX(px.y));
    return *this;
}

Drawable& Drawable::preTranslate(float x, float y)
{
    al_translate_transform(&drawable_pre_trans, x, y);
    return *this;
}

Drawable& Drawable::postTranslate(float x, float y)
{
    al_translate_transform(&drawable_post_trans, x, y);
    return *this;
}

Drawable& Drawable::preRotate(float theta)
{
    al_rotate_transform(&drawable_pre_trans, theta);
    return *this;
}

Drawable& Drawable::postRotate(float theta)
{
    al_rotate_transform(&drawable_post_trans, theta);
    return *this;
}

Drawable& Drawable::preAll(float x, float y, float sx, float sy, float theta)
{
    al_build_transform(&drawable_pre_trans, x, y, sx, sy, theta);
    return *this;
}

Drawable& Drawable::postAll(float x, float y, float sx, float sy, float theta)
{
    al_build_transform(&drawable_post_trans, x, y, sx, sy, theta);
    return *this;
}

Pixel Drawable::getTransformedTL()
{
    float x=0, y=0;
    al_transform_coordinates(&drawable_pre_trans, &x, &y);
    return Pixel(x, y);
}

ALLEGRO_TRANSFORM* Drawable::getPreTransform()
{
    return &drawable_pre_trans;
}

ALLEGRO_TRANSFORM* Drawable::getPostTransform()
{
    return &drawable_post_trans;
}

void Drawable::invalidate()
{
    drawable_is_dirty=true;
}

void Drawable::invalidateRegion(const Rect& _area)
{
    const Rect area=_area.transformBy(&drawable_pre_trans).transformBy(&drawable_post_trans);
    if(area&drawable_rgn)
    {
        drawable_is_dirty=true;
        for(auto &it : inner)
        {
            it->invalidateRegion(area);
        }
    }
}
