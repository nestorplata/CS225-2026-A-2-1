
#pragma once
#include<iostream>
#include<stdio.h>
#include<vector>
class Event;

class IEventHandler
{
    public:
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
    EventHandler(T *object, EventCallback func) : Object_T(object), ActionMethod(func){ }

    void call( Event* event)override 
    {
        if(dynamic_cast<E*>(event)) (Object_T->*ActionMethod)(static_cast<E*>(event));
    } 
   
};

class EventManager
{
    private:
    std::vector<IEventHandler*> listeners_subscribed;

    

    public:
    void registerEventHandler(IEventHandler* listener);
    
    IEventHandler* getEventHandlerAt( int i);
    
    void notifyEvent(Event* event);
};