#ifndef GARBAGECOLLECTION_H_INCLUDED
#define GARBAGECOLLECTION_H_INCLUDED

#include "basicresource.h"
#include "Event.h"

class Projectile;

class GarbageCollection
{
private:
    std::list<Button*> buttonGC;
    std::list<EventHandler*> eventHandlerGC;
    std::list<b2Body*> b2BodyGC;
    std::list<Entity*> entityGC;
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
    void watchButton(Button *button_arg);
    void watchEventHandler(EventHandler *handler_arg);
    void watchb2Body(b2Body *body_arg);
    void watchEntity(Entity *entity_arg);
    void watchProjectile(Projectile *projectile_arg);
    void collectGarbage();
};

#endif // GARBAGECOLLECTION_H_INCLUDED
