#ifndef SetWin_h
#define SetWin_h

#include "../Arduino/Arduino.h"
#include "../Player/Player.h"
#include "../GameState/GameState.h"
#include "../GameTimer/GameTimer.h"
#include "../Undo/Undo.h"
#include "../SetLeds/SetLeds.h"
#include <iostream>

class SetWin {

 public:
  SetWin( Undo* undo, GameState* gameState, SetLeds* setLeds );
  ~SetWin();
  void execute( Player* player );

 private:
     Undo*      _undo; 
     GameState* _gameState; 
     SetLeds*   _setLeds; };
#endif