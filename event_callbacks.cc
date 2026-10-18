#include "event_callbacks.hh"
#include "event.hh"

void EventDispatcher:: subscribe(void* context, CallbackFunction callback)
        {
            EventListener listener(context, callback);
            listeners.push_back(listener);
        }

        EventListener* EventDispatcher:: getListenerAt(int index)
        {
            if(index < 0 || index >= (int)listeners.size()) return nullptr;
                return &listeners.at(index);;
        }

        void EventDispatcher:: dispatchEvent(Event* event)
        {
            for(auto& listener : listeners)
            {
                listener.callbackFunction(listener.contextObject, event);
            }
        }