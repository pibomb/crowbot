#ifndef GARBAGECOLLECTION_H_INCLUDED
#define GARBAGECOLLECTION_H_INCLUDED

#include "basicresource.h"
#include "Event.h"

class Projectile;

class GarbageCollection
{
private:
    std::list<Projectile*> projectileGC;
public:
    GarbageCollection()
    {
        //
    }
    ~GarbageCollection()
    {
        //
    }
    void initialize();
    void cleanup();
    void watchProjectile(Projectile *projectile_arg);
    void collectGarbage();
};

#endif // GARBAGECOLLECTION_H_INCLUDED
