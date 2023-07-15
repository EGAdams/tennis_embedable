#ifndef SetLeds_h
#define SetLeds_h

#include "../Arduino/Arduino.h"
#include "../PinInterface/PinInterface.h"
#include "../Player/Player.h"
#include "../ScoreBoard/ScoreBoard.h"

class SetLeds {
 public:
  SetLeds(Player* player1, Player* player2, PinInterface* pinInterface);
  ~SetLeds();
  void updateSets();
  void setScoreBoard( ScoreBoard* scoreBoard );

 private:
  Player*       _player1;
  Player*       _player2;
  PinInterface* _pinInterface;
  ScoreBoard*   _scoreBoard; };
#endif