#ifndef DRAWABLE_H_INCLUDED
#define DRAWABLE_H_INCLUDED

#include "basicresource.h"
#include "Pixel.h"

class Vec2;

class Drawable
{
protected:
    bool drawable_is_dirty;
    ALLEGRO_TRANSFORM drawable_pre_trans;
    ALLEGRO_TRANSFORM drawable_post_trans;
    Rect drawable_rgn;
    Drawable *drawable_outer;
    std::list<Drawable*>::iterator drawable_this_position;
    virtual void transformation()=0;
    virtual void onDraw()=0;
    virtual void postDraw()=0;
public:
    std::list<Drawable*> inner;
    Drawable():
        drawable_is_dirty(true),
        drawable_rgn(Rect(-10000, -10000, 10000, 10000)),
        drawable_outer(nullptr)
    {
        preset();
        postset();
    }
    Drawable(Rect drawable_rgn_arg):
        drawable_is_dirty(true),
        drawable_rgn(drawable_rgn_arg),
        drawable_outer(nullptr)
    {
        preset();
        postset();
    }
    virtual ~Drawable()
    {
        //
    }
    void push(Drawable *other);
    void pull();
    void decompose();
    void render();
    Drawable& preset();
    Drawable& postset();
    Drawable& preScale(float sx, float sy);
    Drawable& postScale(float sx, float sy);
    Drawable& preTranslate(Pixel px);
    Drawable& postTranslate(Pixel px);
    Drawable& preTranslate(Vec2 px);
    Drawable& postTranslate(Vec2 px);
    Drawable& preTranslate(b2Vec2 px);
    Drawable& postTranslate(b2Vec2 px);
    Drawable& preTranslate(float x, float y);
    Drawable& postTranslate(float x, float y);
    Drawable& preRotate(float theta);
    Drawable& postRotate(float theta);
    Drawable& preAll(float x, float y, float sx, float sy, float theta);
    Drawable& postAll(float x, float y, float sx, float sy, float theta);
    Pixel getTransformedTL();
    ALLEGRO_TRANSFORM* getPreTransform();
    ALLEGRO_TRANSFORM* getPostTransform();
    void invalidate();
    void invalidateRegion(const Rect& _area);
};

class PhysicalDrawable : public Drawable
{
public:
    int collisions;
    PhysicalDrawable(int collisions_arg=0):
        Drawable(),
        collisions(collisions_arg)
    {
        //
    }
    PhysicalDrawable(Rect drawable_rgn_arg, int collisions_arg=0):
        Drawable(drawable_rgn_arg),
        collisions(collisions_arg)
    {
        //
    }
    virtual ~PhysicalDrawable()
    {
        //
    }
    virtual DRAWABLETYPE getDrawableType()=0;
    virtual void beginCollision(PhysicalDrawable *other)=0;
    virtual void endCollision(PhysicalDrawable *other)=0;
};

#endif // DRAWABLE_H_INCLUDED vim: set ts=4 sw=4 et:
