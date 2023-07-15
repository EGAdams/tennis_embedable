
#ifndef WebLiquidCrystal_h
#define WebLiquidCrystal_h

#include "../Arduino/Arduino.h"
#include "../Player/Player.h"

class WebLiquidCrystal {
 public:
  WebLiquidCrystal();
  ~WebLiquidCrystal();
  void init();
  void backlight();
  void setCursor(int firstPosition, int secondPosition);
  //   void print(std::string text);

 private:
};

#endif
