#ifndef __VIEW_H__
#define __VIEW_H__

#include <string>
#include "Led.h"

enum {LIGHT_OFF, LIGHT_ON};

class View
{
private:
    int lightState;
    Led *light;

public:
    View(Led *led);
    virtual ~View();
    void lightView();
    void updateState(std::string strState);
    void lightOn();
    void lightOff();
};

#endif /* __VIEW_H__ */