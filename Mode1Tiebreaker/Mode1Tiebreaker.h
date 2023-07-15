#ifndef Mode1Tiebreaker_h
#define Mode1Tiebreaker_h
#include "../Arduino/Arduino.h"
#include "../GameLeds/GameLeds.h"
#include "../GameLeds/GameLeds.h"
#include "../GameTimer/GameTimer.h"
#include "../PointLeds/PointLeds.h"
#include "../PinInterface/PinInterface.h"
#include "../Player/Player.h"
#include "../ServeLeds/ServeLeds.h"
#include "../SetLeds/SetLeds.h"
#include "../WatchTimer/WatchTimer.h"
#include "../Mode1Tiebreaker/Mode1Tiebreaker.h"
#include "../WinSequences/WinSequences.h"
#include "../Undo/Undo.h"
#include "../Inputs/Inputs.h"

class Mode1TieBreaker {
 public:
  Mode1TieBreaker(Player* player1,
                  Player* player2,
                  PinInterface* pinInterface,
                  GameState* gameState,
                  History* history);
  ~Mode1TieBreaker();
  void tieBreaker();
  void setTieBreaker();
  void mode1TBButtonFunction();
  void mode1SetTBButtonFunction();
  void tieBreakEnable();
  void setTieBreakEnable();
  void tieLEDsOn();
  void tieLEDsOff();
  void endTieBreak();

  // from mode 1 score
  void mode1TBP1Games();
  void mode1TBP2Games();
  void mode1SetTBP2Games();
  void mode1SetTBP1Games();

  // from mode 1 win sequences
  // void p1TBSetWinSequence();
  // void p1SetWinSequence();
  // void p2TBSetWinSequence();
  // void p2SetWinSequence();

 private:
  Player* _player1;
  Player* _player2;
  PinInterface* _pinInterface;
  GameState* _gameState;
  History* _history;
  PointLeds _pointLeds;
  GameLeds _gameLeds;
  ServeLeds _serveLeds;
  SetLeds _setLeds;
  Mode1WinSequences _mode1WinSequences;
  Undo _undo;
};

#endif
