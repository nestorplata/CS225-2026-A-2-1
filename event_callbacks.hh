#include <iostream>
#include <stdio.h>
#include <list>

typedef void (*callback_function)(void);


class EventListener
{
    public:
        void* contextObject;
        callback_function callbackFunction;

    public:
    EventListener(void* context, callback_function callback)
    : contextObject(context), callbackFunction(callback){};
};

class EventDispatcher
{
    private:
        std::vector<EventListener> listeners;


    public:
        void subscribe(void* context, callback_function callback)
        {
            EventListener listener(context, callback);
            listeners.push_back(listener);
        }

        EventListener* getListenerAt(int index)
        {
            if(index < 0 || index >= listeners.size()) return nullptr;
                return &listeners.at(index);;
        }

        void dispatchEvent()
        {
            for(auto& listener : listeners)
            {
                listener.callbackFunction();
            }
        }



};