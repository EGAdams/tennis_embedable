#include "WinSequence.h"
#include <iostream>

/* TODO: seriously consider changing the filename to match the class name.
already cost us .5 hour */

WinSequence::WinSequence()  {}
WinSequence::~WinSequence() {}

void WinSequence::run( Player* player, GameState* gameState, GameLeds* gameLeds, int games_in_memory ) {
	#if defined _WIN32 || defined _WIN64
    	std::cout << "games_in_memory: " << games_in_memory << std::endl;
	#endif
    for ( int blink_sequence_count = 0; blink_sequence_count < LOOP_GAME_LAMP_WIN; blink_sequence_count++ ) {
        for ( int current_lamp = 0; current_lamp < NUMBER_OF_GAME_LAMPS; current_lamp++ ) {
            #if defined _WIN32 || defined _WIN64
                std::cout << "current_lamp: " << current_lamp << std::endl;
                std::cout << "games_in_memory: " << games_in_memory << std::endl;
            #endif
            player->setGames( 99 );
            gameLeds->updateGames();  // UpdateGames();
            GameTimer::gameDelay( gameState->getGameFlashDelay() /* flashDelay */ );
            player->setGames( current_lamp );
            gameLeds->updateGames();  // UpdateGames();
            GameTimer::gameDelay( gameState->getGameFlashDelay() /* flashDelay */ );
        }
        player->setGames( games_in_memory );
        gameLeds->updateGames();
        #if defined _WIN32 || defined _WIN64
            std::cout << "set games to " << games_in_memory << std::endl;
            std::cout << "done running win sequence. " << std::endl;
        #endif
    } // end LOOP_GAME_LAMP_WIN loop
}
