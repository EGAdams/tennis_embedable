#ifndef PointLeds_h
#define PointLeds_h

#include "../GameState/GameState.h"
#include "../PinInterface/PinInterface.h"
#include "../Player/Player.h"
#include "../Arduino/Arduino.h"
#include "../ScoreBoard/ScoreBoard.h"

class PointLeds {
 public:
  PointLeds(Player* player1, Player* player2, PinInterface* pinInterface );
  PointLeds(Player* player1, Player* player2, ScoreBoard*   scoreBoard   );
  ~PointLeds();
  void updatePoints();
  void updateTBPoints();
  void setScoreBoard( ScoreBoard* scoreBoard );

 private:
  Player* _player1;
  Player* _player2;
  PinInterface* _pinInterface;
  ScoreBoard* _scoreBoard;
};

#endif