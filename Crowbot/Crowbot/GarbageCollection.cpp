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
    for(auto &it : projectileGC)
    {
        delete it;
    }
}

void GarbageCollection::watchProjectile(Projectile *projectile_arg)
{
    projectileGC.push_front(projectile_arg);
}

void GarbageCollection::collectGarbage()
{
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
