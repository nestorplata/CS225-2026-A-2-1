#pragma once
#include <iostream>
#include <stdio.h>
#include <list>

typedef void (*CallbackFunction)(void *ctx, Event *evt);

class EventListener
{
    public:
        void* contextObject;
        CallbackFunction callbackFunction;

    public:
    EventListener()  : contextObject(nullptr), callbackFunction(NULL){};

    EventListener(void* context, CallbackFunction callback)
    : contextObject(context), callbackFunction(callback){};
};

class EventDispatcher
{
    private:
        std::vector<EventListener> listeners;


    public:
        void subscribe(void* context, CallbackFunction callback)
        {
            EventListener listener(context, callback);
            listeners.push_back(listener);
        }

        EventListener* getListenerAt(int index)
        {
            if(index < 0 || index >= listeners.size()) return nullptr;
                return &listeners.at(index);;
        }

        void dispatchEvent(Event* event)
        {
            for(auto& listener : listeners)
            {
                listener.callbackFunction(listener.contextObject, event);
            }
        }



};