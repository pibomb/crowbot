#ifndef COUNTER_H_INCLUDED
#define COUNTER_H_INCLUDED

#include "basicresource.h"
#include "Drawable.h"

class Counter : public Drawable
{
private:
    std::function<std::string()> getVal;
    ALLEGRO_BITMAP *background;
    Pixel pos;
    void transformation() override;
    void onDraw() override;
    void postDraw() override;
public:
    Counter(float x_arg, float y_arg, std::function<std::string()> getVal_arg, ALLEGRO_BITMAP *background_arg);
    virtual ~Counter()
    {
        //
    }
};

#endif // COUNTER_H_INCLUDED
