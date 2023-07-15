#ifndef PININTERFACE_H
#define PININTERFACE_H

#include "../PinState/PinState.h"
#include "../Arduino/Arduino.h"
#include <map>

class PinInterface {
  public:
    PinInterface(PinState* pinState);
    ~PinInterface();
    void pinAnalogWrite(int pin, int value);
    void pinDigitalWrite(int pin, int value);
    int pinAnalogRead(int pin);
    int pinDigitalRead(int pin);
    std::map<std::string, int> getPinStateMap();

  private:
    std::map<std::string, int> _pin_map;
    PinState* _pinState;
};

#endif
