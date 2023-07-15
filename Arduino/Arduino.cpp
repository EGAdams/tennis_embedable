

#include "Arduino.h"

ArduinoObject::ArduinoObject() {}
ArduinoObject::~ArduinoObject() {}
void ArduinoObject::gameDelay(int timeToDelay) {
  std::cout << "Sleeping for " << timeToDelay << " milliseconds" << std::endl;
}
int ArduinoObject::gameMillis() {
  std::cout << "gameMillis() called..." << std::endl;
  return 1000;
}

void ArduinoObject::logUpdate(std::string message) {
  std::cout << message << std::endl;
}
