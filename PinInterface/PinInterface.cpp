#include "PinInterface.h"
#include <string>

PinInterface::PinInterface( PinState* pinState ) : _pinState( pinState ) {}
PinInterface::~PinInterface() {}

int PinInterface::pinAnalogRead( int pin ) {
    std::string pin_string = std::to_string( pin );
    int pin_value = _pinState->getPinState( pin_string );
    return pin_value; }

int PinInterface::pinDigitalRead( int pin ) {
    int pin_value = _pinState->getPinState( std::to_string( pin ));
    return pin_value; }

void PinInterface::pinAnalogWrite( int pin, int value ) { _pinState->setPinState( std::to_string( pin ), value ); }

void PinInterface::pinDigitalWrite( int pin, int value ) { _pinState->setPinState( std::to_string( pin ), value ); }

std::map<std::string, int> PinInterface::getPinStateMap() { return _pin_map; }
