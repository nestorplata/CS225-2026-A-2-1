#include<iostream>
#include<stdio.h>
#include<algorithm>

class Event;

class IEventHandler
{
    protected:
    virtual void call(Event& event)=0;
    

    
};


template <typename T, typename E>
class EventHandler: public IEventHandler
{
    public:
    T Object_T;

    using EventCallback = void(T::*)(const E&);
    EventCallback ActionMethod; 

    public:
    EventHandler(T* Obj_Interested,EventCallback Method)
    : Object_T(Obj_Interested) , ActionMethod(Method){}

    void call( Event& Event) override;
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