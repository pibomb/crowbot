#ifndef OBSERVER_H_INCLUDED
#define OBSERVER_H_INCLUDED

#include "basicresource.h"

class Observer
{
private:
public:
    virtual void onKeyPress(int unichar, int keycode, unsigned int modifiers)=0;
    virtual void onTimerKeyState(const std::vector<bool> &keystates)=0;
};

#endif // OBSERVER_H_INCLUDED
