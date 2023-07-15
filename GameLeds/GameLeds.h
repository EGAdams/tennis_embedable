#ifndef GAME_LED_HEADER_H
#define GAME_LED_HEADER_H

#include "../PinInterface/PinInterface.h"
#include "../Player/Player.h"
#include "../Arduino/Arduino.h"
#include "../TennisConstants/TennisConstants.h"
#include "../ScoreBoard/ScoreBoard.h"
#include "../GameLedTranslator/GameLedTranslator.h"

class GameLeds {
 public:
  GameLeds(Player* player1, Player* player2, PinInterface* pinInterface);
  ~GameLeds();
  void updateGames();
  void setScoreBoard( ScoreBoard* scoreBoard );

 private:
  Player*            _player1;
  Player*            _player2;
  PinInterface*      _pinInterface;
  ScoreBoard*        _scoreBoard;
  GameLedTranslator* _gameLedTranslator;
};

#endif