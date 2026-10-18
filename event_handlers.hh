
#pragma once
#include<iostream>
#include<stdio.h>
#include<algorithm>
class Event;

class IEventHandler
{
    protected:
    virtual void call(Event* event)=0;
    
};


template <typename T, typename E>
class EventHandler: public IEventHandler
{
    public:
    T* Object_T;
    using EventCallback = void (T::*)(E*);
    EventCallback ActionMethod;

    public:
    EventHandler(T *object, EventCallback func)
    {
        Object_T = object;
        ActionMethod = func;

    }

    void call( Event* event)override 
    {
        if(dynamic_cast<E*>(event)) (Object_T->*ActionMethod)(static_cast<E*>(event));
    } 
};

class EventManager
{
    using Event_Handlers_Sub = EventHandler<EventListener, Event>;
    private:
    std::vector<Event_Handlers_Sub> listeners_subscribed;

    public:
    void registerEventHandler(Event_Handlers_Sub* listener);
    
    Event_Handlers_Sub* getEventHandlerAt( int i);

    void notifyEvent();

};