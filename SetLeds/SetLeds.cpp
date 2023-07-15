#include "SetLeds.h"
#include "../Arduino/Arduino.h"
#include "../TennisConstants/TennisConstants.h"

SetLeds::SetLeds( Player* player1, Player* player2, PinInterface* pinInterface )
    : _player1( player1 ), _player2( player2 ), _pinInterface( pinInterface) {}

SetLeds::~SetLeds(){}

void SetLeds::setScoreBoard( ScoreBoard* scoreBoard ) { _scoreBoard = scoreBoard; }

#define PLAYER_1_ZERO_SETS 0
#define PLAYER_1_ONE_SET   1
#define PLAYER_1_TWO_SETS  2
#define PLAYER_2_ZERO_SETS 0
#define PLAYER_2_ONE_SET   1
#define PLAYER_2_TWO_SETS  2

void SetLeds::updateSets() {
  // std::cout << "inside SetLeds::updateSets()" << std::endl;
  std::cout << "player1 sets: " << _player1->getSets() << std::endl;
  if( !_scoreBoard ) {
    std::cout << "scoreboard is null" << std::endl;
  } else { std::cout << "scoreboard is not null" << std::endl;  }
  switch ( _player1->getSets() ) {

    case PLAYER_1_ZERO_SETS:
        std::cout << "player1 has zero sets" << std::endl;
        if ( _scoreBoard->hasCanvas() ) {
            std::cout << "scoreboard has canvas.  updating..." << std::endl;
            _scoreBoard->update();
        } else {
            _pinInterface->pinDigitalWrite( P1_SETS_LED1, LOW );
            _pinInterface->pinDigitalWrite( P1_SETS_LED2, LOW ); } break;

    case PLAYER_1_ONE_SET:
        std::cout << "player1 has one set" << std::endl;
        if ( _scoreBoard->hasCanvas() ) {
            std::cout << "scoreboard has canvas.  updating..." << std::endl;
            _scoreBoard->update();
        } else {
            _pinInterface->pinDigitalWrite( P1_SETS_LED1, HIGH );
            _pinInterface->pinDigitalWrite( P1_SETS_LED2, LOW ); } break;

    case PLAYER_1_TWO_SETS:
        std::cout << "player1 has two sets" << std::endl;
        if ( _scoreBoard->hasCanvas() ) {
            std::cout << "scoreboard has canvas.  updating..." << std::endl;
            _scoreBoard->update();
        } else {
            _pinInterface->pinDigitalWrite( P1_SETS_LED1, HIGH );
            _pinInterface->pinDigitalWrite( P1_SETS_LED2, HIGH ); } break;
    case 3:
        std::cout << "player1 has three sets" << std::endl;
        if ( _scoreBoard->hasCanvas() ) {
            std::cout << "scoreboard has canvas.  updating..." << std::endl;
            _scoreBoard->update();
        } else {
            _pinInterface->pinDigitalWrite( P1_SETS_LED1, HIGH );
            _pinInterface->pinDigitalWrite( P1_SETS_LED2, HIGH ); } break;
  }

  switch (_player2->getSets()) {
    case PLAYER_2_ZERO_SETS:
        std::cout << "player2 has zero sets" << std::endl;
        if ( _scoreBoard->hasCanvas() ) {
            std::cout << "scoreboard has canvas.  updating..." << std::endl;
            _scoreBoard->update();
        } else {
            _pinInterface->pinDigitalWrite( P2_SETS_LED1, LOW );
            _pinInterface->pinDigitalWrite( P2_SETS_LED2, LOW ); } break;
            
    case PLAYER_2_ONE_SET:
        std::cout << "player2 has one set" << std::endl;
        if ( _scoreBoard->hasCanvas() ) {
            std::cout << "scoreboard has canvas.  updating..." << std::endl;
            _scoreBoard->update();
        } else {
            _pinInterface->pinDigitalWrite( P2_SETS_LED1, HIGH );
            _pinInterface->pinDigitalWrite( P2_SETS_LED2, LOW ); } break;

    case PLAYER_2_TWO_SETS:
        std::cout << "player2 has two sets" << std::endl;
        if ( _scoreBoard->hasCanvas() ) {
            std::cout << "scoreboard has canvas.  updating..." << std::endl;
            _scoreBoard->update();
        } else {
            _pinInterface->pinDigitalWrite( P2_SETS_LED1, HIGH );
            _pinInterface->pinDigitalWrite( P2_SETS_LED2, HIGH ); } break;
    case 3:
        std::cout << "player2 has three sets" << std::endl;
        if ( _scoreBoard->hasCanvas() ) {
            std::cout << "scoreboard has canvas.  updating..." << std::endl;
            _scoreBoard->update();
        } else {
            _pinInterface->pinDigitalWrite( P2_SETS_LED1, HIGH );
            _pinInterface->pinDigitalWrite( P2_SETS_LED2, HIGH ); } break; }}