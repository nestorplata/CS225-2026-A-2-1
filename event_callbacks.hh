#pragma once
#include <iostream>
#include <stdio.h>
#include <list>
#include <vector>
class Event;

typedef void (*CallbackFunction)(void *ctx, Event *evt);

class Event;
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
        void subscribe(void* context, CallbackFunction callback);

        EventListener* getListenerAt(int index);

        void dispatchEvent(Event* event);
        



};