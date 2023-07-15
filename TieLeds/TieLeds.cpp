#include "TieLeds.h"

TieLeds::TieLeds(PinInterface* pinInterface) : _pinInterface(pinInterface) {}
TieLeds::~TieLeds() {}

void TieLeds::turnOff() {
    _pinInterface->pinDigitalWrite(P1_TIEBREAKER, LOW);
    _pinInterface->pinDigitalWrite(P2_TIEBREAKER, LOW);
}

void TieLeds::turnOn() {
    _pinInterface->pinDigitalWrite(P1_TIEBREAKER, HIGH);
    _pinInterface->pinDigitalWrite(P2_TIEBREAKER, HIGH);
}
