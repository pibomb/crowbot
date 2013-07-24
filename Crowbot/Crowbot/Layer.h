#ifndef LAYER_H_INCLUDED
#define LAYER_H_INCLUDED

#include "basicresource.h"
#include "Drawable.h"

class Layer : public Drawable
{
public:
    void transformation();
    void onDraw();
    void postDraw();
    Layer():
        Drawable()
    {
        //
    }
};

#endif // LAYER_H_INCLUDED
