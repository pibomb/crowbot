#include "resource.h"

ALLEGRO_EVENT_SOURCE* AllegroEventSource::getEventSource()
{
    return &event_source;
}

void AllegroEventSource::fire(intptr_t data1, intptr_t data2, intptr_t data3, intptr_t data4)
{
    event.type=eventID;
    event.user.data1=data1;
    event.user.data2=data2;
    event.user.data3=data3;
    event.user.data4=data4;
    al_emit_user_event(&event_source, &event, nullptr);
}

void AllegroEventSource::destroy()
{
    al_destroy_user_event_source(&event_source);
}

void AllegroEventSystem::destroy()
{
    for(auto &it : events)
    {
        it.second->destroy();
        delete it.second;
    }
}

bool EventData::validate(EventCondition& other)
{
    if(eventID!=other.eventID || other.options.size()<options.size())
    {
        return false;
    }
    for(int i=0; i<(int)options.size(); i++)
    {
        if(options[i]!=other.options[i] && options[i]!=EVENTOPTIONS::WILDCARD)
        {
            return false;
        }
    }
    return other.checkData(data);
}

void EventHandler::add(EVENTTYPE eventID, std::vector<EVENTOPTIONS> options, std::function<bool(std::vector<int>)> checkData_arg)
{
    eventSequence.push(EventCondition(eventID, options, checkData_arg));
}

void EventHandler::pull(EventSource& eventSource)
{
    if(iters[eventSource.getID()]!=eventSource.handlers.end())
    {
        eventSource.handlers.erase(iters[eventSource.getID()]);
        iters[eventSource.getID()]=eventSource.handlers.end();
    }
}

void EventHandler::push(EventSource& eventSource)
{
    eventSource.handlers.push_front(this);
    iters[eventSource.getID()]=eventSource.handlers.begin();
}

void EventHandler::accept(EventData event)
{
    if(!complete() && event.validate(eventSequence.front()))
    {
        eventSequence.pop();
        if(complete())
        {
            callback();
        }
    }
}

bool EventHandler::complete()
{
    return eventSequence.empty();
}

EVENTTYPE EventSource::getID()
{
    return eventID;
}

void EventSource::fire(std::vector<EVENTOPTIONS> options, std::vector<int> data)
{
    EventData event(eventID, options, data);
    for(auto &it : handlers)
    {
        it->accept(event);
    }
}

void EventSystem::addEventHandler(EventHandler *eventHandler_arg)
{
    handlers.push_front(eventHandler_arg);
}