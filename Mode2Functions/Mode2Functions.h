#ifndef Mode2Functions_h
#define Mode2Functions_h
#include <string>
#include "../GameLeds/GameLeds.h"
#include "../GameState/GameState.h"
#include "../GameTimer/GameTimer.h"
#include "../PointLeds/PointLeds.h"
#include "../Player/Player.h"
#include "../SetLeds/SetLeds.h"
#include "../Arduino/Arduino.h"
#include "../TennisConstants/TennisConstants.h"
#include "../Player/Player.h"

class Mode2Functions {
 public:
  Mode2Functions(Player* player1,
                 Player* player2,
                 PinInterface* pinInterface,
                 GameState* gameState);
  ~Mode2Functions();
  void m2Loop();
  void m2PlayerButtons(int playerButton);

 private:
  Player* _player1;
  Player* _player2;
  GameState* _gameState;
  PointLeds _pointLeds;
  GameLeds _gameLeds;
  SetLeds _setLeds;
};

#endif
