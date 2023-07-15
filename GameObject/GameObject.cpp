#include "GameObject.h"
#include <csignal>
#include <chrono>
#include <thread>
#include <iostream>

GameObject::GameObject( Player* player1,
    Player* player2,
    PinState* pinState,
    PinInterface* pinInterface,
    GameState* gameState,
    GameTimer* gameTimer,
    Inputs* gameInputs,
    GameModes* gameModes,
    ScoreBoard* scoreBoard,
    WebLiquidCrystal* lcd ) {
    _player1 = player1;
    _player2 = player2;
    _pinState = pinState;
    _pinInterface = pinInterface;
    _gameState = gameState;
    _gameTimer = gameTimer;
    _gameInputs = gameInputs;
    _gameModes = gameModes;
    _scoreBoard = scoreBoard;
    _webLiquidCrystal = lcd;
}

GameObject::GameObject( GameState* gameState ) : _gameState( gameState ) {
    std::cout << "Constructing GameObject..." << std::endl;
    _webLiquidCrystal = new WebLiquidCrystal();
    _gameTimer = new GameTimer();
    std::cout << "constructing players... " << std::endl;
    _player1 = new Player( _gameState, PLAYER_1_INITIALIZED ); 
    _player2 = new Player( _gameState, PLAYER_2_INITIALIZED ); // got players defined, now set echother as opponents...
    _player2->setOpponent( _player1 ); _player1->setOpponent( _player2 );
    _pinState = new PinState( _pin_map );
    _pinInterface = new PinInterface( _pinState );
    std::cout << "constructing history object..." << std::endl;
    _history = new History();
    std::cout << "constructing gamestate object..." << std::endl;
    _gameInputs = new Inputs( _player1, _player2, _pinInterface, _gameState );
    _gameModes =  new GameModes( _player1, _player2, _pinInterface, _gameState, _history );
    std::cout << "constructing scoreboard object..." << std::endl;
    _scoreBoard = new ScoreBoard( _player1, _player2, _gameState );
    _gameModes->setScoreBoards( _scoreBoard );
    _subjectManager = new SubjectManager();
    _logger = new Logger( "GameObject" );
    std::cout << "GameObject constructed." << std::endl;
}

GameObject::~GameObject() {};
void GameObject::_signalHandler( int signal ) { GameObject::gSignalStatus = signal; }
volatile int GameObject::gSignalStatus = 0;

void GameObject::loopGame() {
        // std::cout << "reading reset from loopGame()..." << std::endl;
        // _gameInputs->readReset();
        // std::cout << "reading rotary from loopGame()..." << std::endl;
        std::cout << "*** //////////// starting another loop.  current set is: " << _gameState->getCurrentSet() << " ////////////////// ***" << std::endl;
        int rotaryValue = 1; // int rotaryValue = _gameInputs->readRotary(); TODO: actually read rotary
        // std::cout << "rotaryValue: " << rotaryValue << ".  setting game mode to " << rotaryValue << "." << std::endl;
        _gameModes->setGameMode( rotaryValue );  // mode1() called here <--- entry point !! --------------<<
        std::cout << "delaying for " << GAME_LOOP_DELAY << " milliseconds..." << std::endl;
        GameTimer::gameDelay( GAME_LOOP_DELAY );
        // std::cout << "updating game state..." << std::endl;
        _subjectManager->gameStateUpdate( _gameState, _player1, _player2 );
        std::cout << "end of loopGame().\n" << std::endl; }

GameState* GameObject::getGameState() { return _gameState; }

void GameObject::playerScore( int playerNumber ) {  // sets the gamestate player button
    _gameState->setCurrentAction( "Updating state after player " + std::to_string( playerNumber ) + " scored." );
    // std::cout << "GameObject::playerScore( " << playerNumber << " )" << std::endl;
    // std::cout << "updating game state...  setting player button to " << playerNumber << " ..." << std::endl;
    // int current_player_button = _gameState->getPlayerButton();
    // std::cout << "current_player_button: " << current_player_button << std::endl;
    _gameState->setPlayerButton( playerNumber ); 
    // current_player_button = _gameState->getPlayerButton();
    // std::cout << "current_player_button: " << current_player_button << std::endl;
}

PinInterface* GameObject::getPinInterface() { return _pinInterface; }

ScoreBoard* GameObject::getScoreBoard() { return _scoreBoard; }

void GameObject::start() {}