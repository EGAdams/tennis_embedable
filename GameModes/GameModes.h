#ifndef GAME_MODES_h
#define GAME_MODES_h
#include "../Arduino/Arduino.h"
#include "../GameLeds/GameLeds.h"
#include "../GameState/GameState.h"
#include "../GameTimer/GameTimer.h"
#include "../Inputs/Inputs.h"
// #include "IniReader.h"
#include "../Logger/Logger.h"
#include "../Mode1Functions/Mode1Functions.h"
#include "../Mode1Tiebreaker/Mode1Tiebreaker.h"
#include "../Mode2Functions/Mode2Functions.h"
#include "../PointLeds/PointLeds.h"
#include "../PinInterface/PinInterface.h"
#include "../Player/Player.h"
#include "../ServeLeds/ServeLeds.h"
#include "../SetLeds/SetLeds.h"
#include "../Undo/Undo.h"
#include "../WatchTimer/WatchTimer.h"
#include "../BatteryTest/BatteryTest.h"

class History;

#if defined _WIN32 || defined _WIN64
    #include <iostream>
#endif
class GameModes {
 public:
  GameModes(Player* player1,
            Player* player2,
            PinInterface* pinInterface,
            GameState* gameState,
            History* history);
  ~GameModes();
  void gameStart();
  void testStart();
  void mode1();
  void mode2();
  void mode4();
  void noCode();
  void setGameMode(int rotaryPosition);
  void setScoreBoards( ScoreBoard* scoreBoard );

 private:
  Player* _player1;
  Player* _player2;
  PinInterface* _pinInterface;
  GameState* _gameState;
  History* _history;
  PointLeds _pointLeds;
  GameLeds _gameLeds;
  SetLeds _setLeds;
  Inputs _inputs;
  Undo _undo;
  ServeLeds _serveLeds;
  Mode1TieBreaker _mode1TieBreaker;
  Mode1Functions _mode1Functions;
  Mode2Functions _mode2Functions;
  //   IniReader _iniReader;
  Logger* _logger;
};

#endif
