#ifndef WinSequence_h
#define WinSequence_h

#include "../Arduino/Arduino.h"
#include "../Player/Player.h"
#include "../GameState/GameState.h"
#include "../GameLeds/GameLeds.h"
#include "../GameTimer/GameTimer.h"

class WinSequence {

 public:
  WinSequence();
  ~WinSequence();
  void run( Player* player, GameState* gameState, GameLeds* gameLeds, int games_in_memory );

 private:

};
#endif
