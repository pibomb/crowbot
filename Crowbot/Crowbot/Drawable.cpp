#include "resource.h"

Drawable::Drawable():
    drawable_is_dirty(true),
    drawable_rgn(Rect(-1000000000, -1000000000, 1000000000, 1000000000)),
    drawable_outer(nullptr)
{
    preset();
    postset();
}

Drawable::Drawable(Rect drawable_rgn_arg):
    drawable_is_dirty(true),
    drawable_rgn(drawable_rgn_arg),
    drawable_outer(nullptr)
{
    preset();
    postset();
}

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
    if(drawable_is_dirty)
    {
        drawable_is_dirty=false;
        ALLEGRO_TRANSFORM old=*al_get_current_transform();
        transformation();
        ALLEGRO_TRANSFORM cur;
        getFinalTransform(&cur, &old);
        al_use_transform(&cur);
        onDraw();
        for(auto &it : inner)
        {
            it->render();
        }
        postDraw();
        al_use_transform(&old);
    }
    /*
    else
    {
        for(auto &it : inner)
        {
            it->render();
        }
    }
    */
}

void Drawable::render(const Rect& world_area)
{
    if(drawable_is_dirty)
    {
        drawable_is_dirty=false;
        ALLEGRO_TRANSFORM old=*al_get_current_transform();
        transformation();
        ALLEGRO_TRANSFORM cur;
        getFinalTransform(&cur, &old);
        al_use_transform(&cur);
        onDraw();
        for(auto &it : inner)
        {
            it->render(world_area);
        }
        postDraw();
        al_use_transform(&old);
    }
    /*
    else
    {
        for(auto &it : inner)
        {
            it->render(world_area);
        }
    }
    */
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

void Drawable::getFinalTransform(ALLEGRO_TRANSFORM *transform_arg, const ALLEGRO_TRANSFORM *original_transform_arg)
{
    al_copy_transform(transform_arg, &drawable_pre_trans);
    if(original_transform_arg)
    {
        al_compose_transform(transform_arg, original_transform_arg);
    }
    al_compose_transform(transform_arg, &drawable_post_trans);
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
    for(auto &it : inner)
    {
        it->invalidate();
    }
}

void Drawable::invalidate(const Rect& world_area)
{
    ALLEGRO_TRANSFORM old=*al_get_current_transform();
    transformation();
    ALLEGRO_TRANSFORM cur;
    getFinalTransform(&cur, &old);
    const Rect transformed_local_area=drawable_rgn.transformBy(&cur);
    if(transformed_local_area&world_area)
    {
        drawable_is_dirty=true;
        al_use_transform(&cur);
        for(auto &it : inner)
        {
            it->invalidate(world_area);
        }
        al_use_transform(&old);
    }
}
