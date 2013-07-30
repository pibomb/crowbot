#ifndef LAYER_H_INCLUDED
#define LAYER_H_INCLUDED

#include "basicresource.h"
#include "Drawable.h"

class Layer : public Drawable
{
private:
    void transformation() override;
    void onDraw() override;
    void postDraw() override;
public:
    Layer():
        Drawable()
    {
        //
    }
};

#endif // LAYER_H_INCLUDED
