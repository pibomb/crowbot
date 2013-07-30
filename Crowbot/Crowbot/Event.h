#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include "basicresource.h"

class EventSource;

class AllegroEventSource
{
private:
    ALLEGRO_EVENT_SOURCE event_source;
    ALLEGRO_EVENT event;
    int eventID;
public:
    ALLEGRO_EVENT_SOURCE* getEventSource();
    void fire(intptr_t data1=0, intptr_t data2=0, intptr_t data3=0, intptr_t data4=0);
    void destroy();
    AllegroEventSource(int eventID_arg):
        eventID(eventID_arg)
    {
        al_init_user_event_source(&event_source);
    }
    virtual ~AllegroEventSource()
    {
        //
    }
};

class AllegroEventSystem
{
private:
    std::map<int, AllegroEventSource*> events;
public:
    void destroy();
    AllegroEventSource& operator[] (int eventID_arg)
    {
        if(!events[eventID_arg])
        {
            events[eventID_arg]=new AllegroEventSource(eventID_arg);
        }
        return *events[eventID_arg];
    }
};

class EventCondition;

class EventData
{
public:
    EVENTTYPE eventID;
    std::vector<EVENTOPTIONS> options;
    std::vector<int> data;
    bool validate(EventCondition& other);
    EventData(EVENTTYPE eventID_arg, std::vector<EVENTOPTIONS> options_arg, std::vector<int> data_arg):
        eventID(eventID_arg),
        options(options_arg),
        data(data_arg)
    {
        //
    }
};

class EventCondition
{
public:
    EVENTTYPE eventID;
    std::vector<EVENTOPTIONS> options;
    std::function<bool(std::vector<int>)> checkData;
    EventCondition(EVENTTYPE eventID_arg, std::vector<EVENTOPTIONS> options_arg, std::function<bool(std::vector<int>)> checkData_arg):
        eventID(eventID_arg),
        options(options_arg),
        checkData(checkData_arg)
    {
        //
    }
};

class EventHandler
{
protected:
    std::map<EVENTTYPE, std::list<EventHandler*>::iterator> iters;
    std::queue<EventCondition> eventSequence;
    std::function<void()> callback;
public:
    EventHandler(std::function<void()> callback_arg):
        callback(callback_arg)
    {
        //
    }
    virtual ~EventHandler()
    {
        //
    }
    void setCallback(std::function<void()> callback_arg);
    void add(EVENTTYPE eventID, std::vector<EVENTOPTIONS> options=std::vector<EVENTOPTIONS>(), std::function<bool(std::vector<int>)> checkData_arg=[](std::vector<int>){return true;});
    void pull(EventSource& eventSource);
    void push(EventSource& eventSource);
    virtual void accept(EventData& event);
    void destroy();
    bool complete();
};

class EventTriggerHandler : public EventHandler
{
public:
    EventTriggerHandler(std::function<void()> callback_arg):
        EventHandler(callback_arg)
    {
        //
    }
    ~EventTriggerHandler()
    {
        //
    }
    void accept(EventData& event) override;
};

class EventSource
{
private:
    EVENTTYPE eventID;
public:
    std::list<EventHandler*> handlers;
    EVENTTYPE getID();
    void fire(std::vector<EVENTOPTIONS> options=std::vector<EVENTOPTIONS>(), std::vector<int> data=std::vector<int>());
    EventSource(EVENTTYPE eventID_arg):
        eventID(eventID_arg)
    {
        //
    }
    virtual ~EventSource()
    {
        //
    }
};

class EventSystem
{
private:
    std::map<EVENTTYPE, EventSource*> events;
    std::list<EventHandler*> handlers;
public:
    void addEventHandler(EventHandler *eventHandler_arg);
    EventSource& operator[] (EVENTTYPE eventID_arg)
    {
        if(!events[eventID_arg])
        {
            events[eventID_arg]=new EventSource(eventID_arg);
        }
        return *events[eventID_arg];
    }
    ~EventSystem()
    {
        for(auto &it : handlers)
        {
            delete it;
        }
    }
};

#endif // EVENT_H_INCLUDED
