#ifndef DRAWABLE_H_INCLUDED
#define DRAWABLE_H_INCLUDED

#include "basicresource.h"
#include "Physics.h"

class Drawable
{
protected:
    bool drawable_is_dirty;
    ALLEGRO_TRANSFORM drawable_trans;
    Rect drawable_rgn;
    Drawable *drawable_outer;
    std::list<Drawable*>::iterator drawable_this_position;
public:
    std::list<Drawable*> inner;
    Drawable():
        drawable_is_dirty(true),
        drawable_rgn(Rect(-10000, -10000, 10000, 10000)),
        drawable_outer(nullptr)
    {
        preset();
    }
    Drawable(Rect drawable_rgn_arg):
        drawable_is_dirty(true),
        drawable_rgn(drawable_rgn_arg),
        drawable_outer(nullptr)
    {
        preset();
    }
    virtual ~Drawable()
    {
        //
    }
    void push(Drawable *other);
    void pull();
    void render();
    Drawable& preset();
    Drawable& preScale(float sx, float sy);
    Drawable& preTranslate(Pixel px);
    Drawable& preTranslate(Vec2 px);
    Drawable& preTranslate(float x, float y);
    Drawable& preRotate(float theta);
    Drawable& preAll(float x, float y, float sx, float sy, float theta);
    Pixel getTransformedTL();
    ALLEGRO_TRANSFORM* getTransform();
    void invalidate();
    void invalidateRegion(const Rect& _area);
    virtual void transformation()=0;
    virtual void onDraw()=0;
    virtual void postDraw()=0;
};

#endif // DRAWABLE_H_INCLUDED vim: set ts=4 sw=4 et:
