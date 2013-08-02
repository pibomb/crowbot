#include "resource.h"

void GarbageCollection::initialize()
{
    EventTriggerHandler *evtrig=new EventTriggerHandler([this]()
                                           {
                                               this->collectGarbage();
                                           });
    sysEvents.addEventHandler(evtrig);
    evtrig->push(sysEvents[EVENTTYPE::COLLECTGARBAGE]);
    evtrig->add(EVENTTYPE::COLLECTGARBAGE);
}

void GarbageCollection::cleanup()
{
    for(auto &it : entityGC)
    {
        delete it;
    }
    for(auto &it : buttonGC)
    {
        delete it;
    }
    for(auto &it : eventHandlerGC)
    {
        delete it;
    }
    for(auto &it : b2BodyGC)
    {
        world.DestroyBody(it);
    }
    for(auto &it : projectileGC)
    {
        delete it;
    }
}

void GarbageCollection::watchEntity(Entity *entity_arg)
{
    entityGC.push_front(entity_arg);
}

void GarbageCollection::watchButton(Button *button_arg)
{
    buttonGC.push_front(button_arg);
}

void GarbageCollection::watchEventHandler(EventHandler *handler_arg)
{
    eventHandlerGC.push_front(handler_arg);
}

void GarbageCollection::watchb2Body(b2Body *body_arg)
{
    b2BodyGC.push_front(body_arg);
}

void GarbageCollection::watchProjectile(Projectile *projectile_arg)
{
    projectileGC.push_front(projectile_arg);
}

void GarbageCollection::collectGarbage()
{
    for(auto it=entityGC.begin(); it!=entityGC.end();)
    {
        if(((*it)->isDeletable()))
        {
            delete *it;
            it=entityGC.erase(it);
        }
        else
        {
            it++;
        }
    }
    for(auto &it : buttonGC)
    {
        it->pull();
        delete it;
    }
    buttonGC.clear();
    for(auto &it : eventHandlerGC)
    {
        it->destroy();
        delete it;
    }
    eventHandlerGC.clear();
    for(auto &it : b2BodyGC)
    {
        world.DestroyBody(it);
    }
    b2BodyGC.clear();
    for(auto it=projectileGC.begin(); it!=projectileGC.end();)
    {
        if(!((*it)->isActive()))
        {
            delete *it;
            it=projectileGC.erase(it);
        }
        else
        {
            it++;
        }
    }
}
