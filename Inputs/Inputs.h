#ifndef Inputs_h
#define Inputs_h

#include "../Arduino/Arduino.h"
#include "../GameState/GameState.h"
#include "../GameTimer/GameTimer.h"
#include "../PinInterface/PinInterface.h"
#include "../Inputs/Inputs.h"
#include "../Logger/Logger.h"
#include "../Reset/Reset.h"

class Inputs {
 public:
  Inputs(Player* player1,
         Player* player2,
         PinInterface* pinInterface,
         GameState* gameState);
  ~Inputs();
  void readReset();
  void readUndoButton();
  int readRotary();
  void readPlayerButtons();

 private:
  Player* _player1;
  Player* _player2;
  PinInterface* _pinInterface;
  GameState* _gameState;
  Reset _reset;
  Logger* _logger;
};

#endif
