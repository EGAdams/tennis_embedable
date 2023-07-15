#include "MatchWinSequence.h"
#include <iostream>

MatchWinSequence::MatchWinSequence()  {}
MatchWinSequence::~MatchWinSequence() {}

void MatchWinSequence::run( Player* player, GameState* gameState, GameLeds* gameLeds, SetLeds* setLeds ) {
    std::cout << "//////////////////////// MatchWinSequence::run() ////////////////////////" << std::endl;
    GameTimer::gameDelay( MATCH_WIN_FLASH_DELAY );
    for ( int blink_sequence_count = 0; blink_sequence_count < LOOP_MATCH_LAMP_WIN; blink_sequence_count++ ) {
        for ( int current_lamp = 0; current_lamp < NUMBER_OF_GAME_LAMPS; current_lamp++ ) {
            player->setGames( 6 );
            gameLeds->updateGames();
            GameTimer::gameDelay( MATCH_WIN_FLASH_DELAY );
            player->setGames( current_lamp );
            gameLeds->updateGames();
            GameTimer::gameDelay( MATCH_WIN_FLASH_DELAY ); }
        GameTimer::gameDelay( MATCH_WIN_FLASH_DELAY ); }} // end LOOP_MATCH_LAMP_WIN loop  // end run().
