// -*- mode: c++; c-basic-offset: 2; indent-tabs-mode: nil; -*-
// The main tennis game entry point.
// This code is public domain
// (but note, that the led-matrix library this depends on is GPL v2)

#include "../include/led-matrix.h"
#include "../include/graphics.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <csignal>
#include <map>
#include "FontLoader/FontLoader.h"
#include "TextDrawer/TextDrawer.h"
#include "NumberDrawer/NumberDrawer.h"
#include "ScoreBoard/ScoreBoard.h"
#include "GameObject/GameObject.h"

using namespace rgb_matrix;

int main( int argc, char *argv[]) {
    int loop_count = 0;
    #define MAX_LOOP_COUNT 350
    #define A_SPACE        13
    #define FOUR_SPACE     14
    #define THREE_SPACE    15
    #define SCORE_DELAY    .15
    
    std::cout << "creating GameObject..." << std::endl;
    GameState*  gameState  = new GameState();  // make this 1st!!! cost me 3 days of debugging
    GameObject* gameObject = new GameObject( gameState );
    std::cout << "done creating game object.  sleeping...\n\n\n\n\n" << std::endl;
    sleep( 1 );
    std::cout << "done sleeping.  calling gameObject->loopGame()..." << std::endl;
    gameObject->loopGame();

    std::cout << "done calling loopGame().  sleeping...\n\n\n\n\n" << std::endl;
    sleep( 1 );

    int randomPlayer = 1;
    std::signal( SIGINT, GameObject::_signalHandler );
    /*/// Begin Game Loop ///*/ while ( gameState->gameRunning() && GameObject::gSignalStatus != SIGINT ) { 
        if ( loop_count >  MAX_LOOP_COUNT ) { gameState->stopGameRunning(); }
        sleep( SCORE_DELAY );
        randomPlayer = rand() % 2 + 1; // generate random player between 1 and 2
        std::cout << "\n*** Player " << randomPlayer << " scored ***\n" << std::endl;
        gameObject->playerScore( randomPlayer );  // flip the player score flag
        sleep( SCORE_DELAY );
        gameObject->loopGame();  // handle the player score flag
        loop_count++;
        std::cout << "player 1 points: " << gameState->getPlayer1Points();
        std::cout << "  player 2 points: " << gameState->getPlayer2Points() << std::endl;
        std::cout << "player 1 games:  "  << gameState->getPlayer1Games();
        std::cout << "  player 2 games:  "  << gameState->getPlayer2Games()  << std::endl;
        std::cout << "player 1 sets:   "   << gameState->getPlayer1Sets();
        std::cout << "  player 2 sets:   "   << gameState->getPlayer2Sets();
        std::cout << "     current set: "     << gameState->getCurrentSet()      << std::endl;
        std::map<int, int> _player1_set_history = gameState->getPlayer1SetHistory();
        // std::cout << "player1_set_history[ 1 ]: " << _player1_set_history[ 1 ] << std::endl;
        // std::cout << "player1_set_history[ 2 ]: " << _player1_set_history[ 2 ] << std::endl;
        // std::cout << "player1_set_history[ 3 ]: " << _player1_set_history[ 3 ] << std::endl;
        std::map<int, int> _player2_set_history = gameState->getPlayer2SetHistory();
        // std::cout << "player2_set_history[ 1 ]: " << _player2_set_history[ 1 ] << std::endl;
        // std::cout << "player2_set_history[ 2 ]: " << _player2_set_history[ 2 ] << std::endl;
        // std::cout << "player2_set_history[ 3 ]: " << _player2_set_history[ 3 ] << std::endl;
        // getchar(); // wait for user input
        std::cout << "end of game loop.  loop_count: " << loop_count << std::endl;
    } ///////// End Game Loop /////////
    std::cout << "game loop exited.  loop_count: " << loop_count << std::endl;
    if ( loop_count > MAX_LOOP_COUNT ) {
        // sleep for 5 seconds
        std::cout << "sleeping for 5 seconds..." << std::endl;
        sleep( 120 );
        std::cout << "MAX_LOOP_COUNT reached.  Exiting...\n\n\n\n\n" << std::endl; }
    return 0; }