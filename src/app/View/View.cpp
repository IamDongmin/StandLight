#include "View.h"
#include <wiringPi.h>
#include <iostream>

View::View(Led *led)
{
    light = led;
    lightState = LIGHT_OFF;
}

View::~View()
{

}

void View::updateState(std::string strState)
{
    switch (lightState)
    {
        case LIGHT_OFF:
            if (strState == "StateOn") {
                lightState = LIGHT_ON;
            }
        break;

        case LIGHT_ON:
            if (strState == "StateOff") {
                lightState = LIGHT_OFF;
            }
        break;
    }
}


void View::lightView()
{
    switch (lightState)
    {
        case LIGHT_OFF:
            lightOff();
        break;

        case LIGHT_ON:
            lightOn();
        break;
    }
}

void View::lightOn()
{
    static unsigned int prevTime = 0;
    
    if (millis() - prevTime < 300) return;
    prevTime = millis();
    light->Toggle();
    std::cout << "light on\n";
}

void View::lightOff()
{
    light->Off();
    std::cout << "light off\n";
}