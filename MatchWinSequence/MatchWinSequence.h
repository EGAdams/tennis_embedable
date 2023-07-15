#ifndef MatchWinSequence_h
#define MatchWinSequence_h

#include "../Arduino/Arduino.h"
#include "../TennisConstants/TennisConstants.h"
#include "../Player/Player.h"
#include "../GameState/GameState.h"
#include "../GameLeds/GameLeds.h"
#include "../GameTimer/GameTimer.h"
#include "../SetLeds/SetLeds.h"

class MatchWinSequence {

 public:
  MatchWinSequence();
  ~MatchWinSequence();
  void run( Player* player, GameState* gameState, GameLeds* gameLeds, SetLeds* setLeds );

 private:

};
#endif
