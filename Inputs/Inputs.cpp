#include "Inputs.h"
#include "../Arduino/Arduino.h"
#include "../TennisConstants/TennisConstants.h"
#include <string>
#include <iostream>

Inputs::Inputs( Player* player1,
    Player* player2,
    PinInterface* pinInterface,
    GameState* gameState )
    : _player1( player1 ),
    _player2( player2 ),
    _pinInterface( pinInterface ),
    _gameState( gameState ),
    _reset( player1, player2, pinInterface, gameState ) {
    _logger = new Logger( "Inputs" ); }
Inputs::~Inputs() {
    std::cout << "*** Inputs destructor called. ***" << std::endl;
    delete _logger; }

void Inputs::readReset() {
    if ( _pinInterface->pinDigitalRead( RESET ) == LOW ) {
        if ( SIMULATION == 0 ) { while ( _pinInterface->pinDigitalRead( RESET ) == LOW ) { GameTimer::gameDelay( 25 ); }}  // Wait for the button to be released
        _reset.resetScoreboard(); }}

void Inputs::readUndoButton() {
    return; // DISABLED
    if ( _pinInterface->pinDigitalRead( UNDO ) == LOW ) {
        if ( SIMULATION == 0 ) { 
            while ( _pinInterface->pinDigitalRead( UNDO ) == LOW ) { 
                GameTimer::gameDelay( 25 ); 
            }
        } // Wait for the button to be released
        _gameState->setUndo( 1 ); 
    }
}

int Inputs::readRotary() {  // TODO: make this one read.
    _gameState->setRotaryPosition( 0 );  // int rotaryPosition = 0;
    int rotaryAnalogValue = _pinInterface->pinAnalogRead( ROTARY );
    #if defined _WIN32 || defined _WIN64
        std::cout << "rotary analog value: " << rotaryAnalogValue << std::endl;
    #endif
    if ( rotaryAnalogValue <= 100 ) { _gameState->setRotaryPosition( 1 ); }
    if ( rotaryAnalogValue >= 350 && rotaryAnalogValue <= 450 ) { _gameState->setRotaryPosition( 2 ); }
    if ( rotaryAnalogValue >= 550 && rotaryAnalogValue <= 700 ) { _gameState->setRotaryPosition( 3 ); }
    if ( rotaryAnalogValue >= 750 && rotaryAnalogValue <= 800 ) { _gameState->setRotaryPosition( 4 ); }
    if ( rotaryAnalogValue >= 850 && rotaryAnalogValue <= 1000 ) { _gameState->setRotaryPosition( 5 ); }
    if ( _gameState->getRotaryPosition() != _gameState->getPrevRotaryPosition() ) {
        _gameState->setRotaryChange( 1 );
        _gameState->setPrevRotaryPosition( _gameState->getRotaryPosition() );
        _reset.refresh();  // set rotaryChange to false and reset the scoreboard
    }
    return _gameState->getRotaryPosition(); }

void Inputs::readPlayerButtons() {
    return; // DISABLED
    int anlgPlyrBtnVal = _pinInterface->pinAnalogRead( PLAYER_BUTTONS );
    std::cout << "\n\n\n\n\nplayer button read: " << anlgPlyrBtnVal << std::endl;
    if ( anlgPlyrBtnVal <= 1000 ) {  // if one of the player buttons is pressed...
        GameTimer::gameDelay( 20 );
        if ( anlgPlyrBtnVal <= 50 ) {                                _gameState->setPlayerButton( 1 ); }
        else if ( anlgPlyrBtnVal >= 350 && anlgPlyrBtnVal <= 400 ) { _gameState->setPlayerButton( 2 ); }
        else if ( anlgPlyrBtnVal >= 550 && anlgPlyrBtnVal <= 650 ) { _gameState->setPlayerButton( 3 ); }
        else if ( anlgPlyrBtnVal >= 750 && anlgPlyrBtnVal <= 800 ) { _gameState->setPlayerButton( 4 ); }
        #if defined _WIN32 || defined _WIN64
            std::cout << "player button: " << _gameState->getPlayerButton() << std::endl;
            // _logger->logUpdate( "set player button to [" + std::to_string( _gameState->getPlayerButton()) + "]" , __FUNCTION__ );
        #else
            while ( _pinInterface->pinAnalogRead( PLAYER_BUTTONS ) <= 1000 ) { GameTimer::gameDelay( 20 ); }
        #endif
    }}
