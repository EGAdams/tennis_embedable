#include "PointLeds.h"

PointLeds::PointLeds( Player* player1,
    Player* player2,
    PinInterface* pinInterface )
    : _player1( player1 ), _player2( player2 ), _pinInterface( pinInterface ) {}

PointLeds::PointLeds( Player* player1,
    Player* player2,
    ScoreBoard* scoreBoard )
    : _player1( player1 ), _player2( player2 ), _scoreBoard(   scoreBoard   ) {}


PointLeds::~PointLeds() {}

void PointLeds::setScoreBoard( ScoreBoard* scoreBoard ) { 
    std::cout << "*** setting _scoreBoard in PointLeds object ... ***" << std::endl;
    _scoreBoard = scoreBoard; }

void PointLeds::updatePoints() {
    // std::cout << "calling _scoreBoard->update() from inside PointLeds... " << std::endl;
    _scoreBoard->update();
    // std::cout << "done calling _scoreBoard->update()... \n\n" << std::endl;
    return;
    
    switch ( _player1->getPoints()) {
    case 0:
        // draw "00"
        break;
    case 1:
        // draw "10"
        break;
    case 2:
        // draw "15"
        break;
    case 3:
        // draw "30"
        break;
    case 4:
        // draw "40"
        break;
    case 5:
        // draw "40"
        break;

    case 99:
        // draw "Ad"
        break;

    case 100:
        // draw "blank"
        break;
    }

    switch ( _player2->getPoints() ) {
    case 0:
        // draw "00"
        break;
    case 1:
        // draw "10"
        break;
    case 2:
        // draw "15"
        break;
    case 3:
        // draw "30"
        break;
    case 4:
        // draw "40"
        break;
    case 5:
        // draw "40"
        break;
    case 99:
        // draw "Ad"
        break;

    case 100:
        // draw "blank"
        break;
    }
}

void PointLeds::updateTBPoints() {
    // update tie breaker points
}
