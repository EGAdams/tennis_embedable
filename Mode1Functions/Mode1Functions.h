#ifndef MODE_1_FUNCTIONS_h
#define MODE_1_FUNCTIONS_h

#include "../Arduino/Arduino.h"
#include "../TennisConstants/TennisConstants.h"
#include "../GameState/GameState.h"
#include "../GameTimer/GameTimer.h"
#include "../Mode1Score/Mode1Score.h"
#include "../PointLeds/PointLeds.h"
#include "../PinInterface/PinInterface.h"
#include "../Undo/Undo.h"

class History;

#define PLAYER_ONE_SERVE 0
#define PLAYER_TWO_SERVE 1

class Mode1Functions {
 public:
    Mode1Functions(Player* player1,
                    Player* player2,
                    PinInterface* pinInterface,
                    GameState* gameState,
                    History* history);
    ~Mode1Functions();
    void mode1ButtonFunction();
    void mode1ServeFunction();
    void pointFlash();
    void setScoreBoard( ScoreBoard* scoreBoard );

 private:
    Player*    _player1;
    Player*    _player2;
    GameState* _gameState;
    History*   _history;
    Undo       _undo;
    PointLeds  _pointLeds;
    Mode1Score _mode1Score;
    ServeLeds  _serveLeds;
    ScoreBoard* _scoreBoard;
};

#endif