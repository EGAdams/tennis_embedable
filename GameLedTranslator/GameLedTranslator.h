#ifndef GAME_LED_TRANSLATOR_HEADER_H
#define GAME_LED_TRANSLATOR_HEADER_H

#include "../PinInterface/PinInterface.h"
#include "../Player/Player.h"
#include "../Arduino/Arduino.h"
#include "../TennisConstants/TennisConstants.h"
#include "../ScoreBoard/ScoreBoard.h"

class GameLedTranslator {
 public:
  GameLedTranslator( Player* player1, Player* player2, PinInterface* pinInterface );
  ~GameLedTranslator();
  void drawGameLeds();
  void setScoreBoard( ScoreBoard* scoreBoard );

 private:
  Player* _player1;
  Player* _player2;
  PinInterface* _pinInterface;
  ScoreBoard* _scoreBoard;
};

#endif
