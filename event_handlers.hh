
#pragma once
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include "event_callbacks.hh"
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
    using EventCallback = void(T::*)(const & Event);    
    EventCallback* ActionMethod;
  //  no instance of constructor "EventHandler<T, E>::EventHandler [with T=Tests::EventHandlers::DummyObject, E=Tests::EventHandlers::DummyEvent]" matches the argument list
//test_suite.hh(353, 64): argument types are: (Tests::EventHandlers::DummyObject *, void (Tests::EventHandlers::DummyObject::*)(Tests::EventHandlers::DummyEvent *event))

//no matching function for call to 'EventHandler<Tests::EventHandlers::DummyObject, 
//Tests::EventHandlers::DummyEvent>::EventHandler(Tests::EventHandlers::DummyObject*, 
//void (Tests::EventHandlers::DummyObject::*)(Tests::EventHandlers::DummyEvent*))'

    public:

    EventHandler(T* Obj_Interested, EventCallback * Method)
    : Object_T(Obj_Interested) , ActionMethod(Method){}

    void call( Event* Event) override;
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