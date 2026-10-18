#include "event_handlers.hh"
#include "event.hh"




    void EventManager::registerEventHandler(IEventHandler* listener)
    {
        listeners_subscribed.push_back(listener);
    };

    IEventHandler* EventManager::getEventHandlerAt( int i)
    {
        if(i>0 && i<(int)sizeof(listeners_subscribed)/sizeof(IEventHandler*))
        {
            return listeners_subscribed.at(i);
        }
        return nullptr;
    }
    
    void EventManager::notifyEvent(Event* event)
    {
        for (auto listener : listeners_subscribed)
        {
            listener->call(event);
        }
    };
