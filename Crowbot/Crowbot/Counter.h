#ifndef COUNTER_H_INCLUDED
#define COUNTER_H_INCLUDED

#include "basicresource.h"
#include "Drawable.h"

class Counter : public Drawable
{
private:
    std::function<std::string()> getVal;
    ALLEGRO_BITMAP *background;
public:
    void transformation();
    void onDraw();
    void postDraw();
    Counter(std::function<std::string()> getVal_arg, ALLEGRO_BITMAP *background_arg):
        getVal(getVal_arg),
        background(background_arg)
    {
        //
    }
    virtual ~Counter()
    {
        //
    }
};

#endif // COUNTER_H_INCLUDED
