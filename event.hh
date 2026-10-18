#pragma once
#include <iostream>
#include <stdio.h>

class Event {
public:
    Event() {};
    virtual ~Event() {}; 

    void trigger();
    
private:
     //virtual void handleEvent();
};

