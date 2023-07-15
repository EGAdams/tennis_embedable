#ifndef PINSTATE_H
#define PINSTATE_H

#include "../Arduino/Arduino.h"
#include <map>
#include <fstream>
#include "../TranslateConstant/TranslateConstant.h"

class PinState {
public:
    PinState( std::map< std::string, int > pinMap );
    ~PinState();
    void setPinState( std::string pin, int state );
    int getPinState( std::string pin );
    void clear();
    std::map<std::string, int> getMap();

private:
    std::map< std::string, int > _pin_map;
    TranslateConstant _translateConstant;
};

#endif
