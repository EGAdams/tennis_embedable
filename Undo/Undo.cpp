#include "Undo.h"

Undo::Undo( Player* player1, Player* player2, PinInterface* pinInterface, GameState* gameState ): 
    _player1( player1 ), _player2( player2 ),
    _gameState( gameState ),
    _pointLeds( player1, player2, pinInterface ),
    _gameLeds( player1, player2, pinInterface ),
    _setLeds( player1, player2, pinInterface ),
    _serveLeds( pinInterface, gameState ),
    _tieLeds( pinInterface ) {
        _logger = new Logger( "Undo" ); };
Undo::~Undo(){
    std::cout << "*** Undo destructor called. ***" << std::endl;
    delete _logger; };

void Undo::memory() {
    _gameState->setP1PointsMem(       _player1->getPoints()); _gameState->setP2PointsMem( _player2->getPoints());
    _gameState->setP1GamesMem(        _player1->getGames());  _gameState->setP2GamesMem(  _player2->getGames());
    _gameState->setP1SetsMem(         _player1->getSets());   _gameState->setP2SetsMem(   _player2->getSets());
    _gameState->setTieBreakMem(       _gameState->getTieBreak());
    _gameState->setSetTieBreakMem(    _gameState->getSetTieBreak());
    _gameState->setPlayer1SetHistory( _player1->getSetHistory());
    _gameState->setPlayer2SetHistory( _player2->getSetHistory()); }

void Undo::setMode1Undo( History* history ) {
    GameState gameState;
    gameState.setPlayer1Points( _player1->getPoints()); gameState.setP1PointsMem( _gameState->getP1PointsMem());
    gameState.setPlayer2Points( _player2->getPoints()); gameState.setP2PointsMem( _gameState->getP2PointsMem());
    gameState.setPlayer1Games( _player1->getGames());  gameState.setP1GamesMem( _gameState->getP1GamesMem());
    gameState.setPlayer2Games( _player2->getGames()); gameState.setP2GamesMem( _gameState->getP2GamesMem());
    gameState.setPlayer1Sets( _player1->getSets()); gameState.setP1SetsMem( _gameState->getP1SetsMem());
    gameState.setPlayer2Sets( _player2->getSets()); gameState.setP2SetsMem( _gameState->getP2SetsMem());
    gameState.setPlayer1Matches( _player1->getMatches()); gameState.setPlayer2Matches( _player2->getMatches());
    // std::cout << "setting serve to " << _gameState->getServe() << std::endl;
    gameState.setServe( _gameState->getServe());
    // std::cout << "setting serve switch to " << _gameState->getServeSwitch() << std::endl;
    gameState.setServeSwitch( _gameState->getServeSwitch());
    // std::cout << "done setting serve and serve switch.  setting undo..." << std::endl;
    gameState.setUndo( _gameState->getUndo());
    // std::cout << "done setting undo.  setting started..." << std::endl;
    gameState.setStarted( _gameState->getStarted());
    gameState.setPointFlash( _gameState->getPointFlash());
    gameState.setRotaryPosition( _gameState->getRotaryPosition());
    gameState.setPrevRotaryPosition( _gameState->getPrevRotaryPosition());
    gameState.setRotaryChange( _gameState->getRotaryChange());
    gameState.setToggle( _gameState->getToggle());
    gameState.setTieLEDsOn( _gameState->getTieLEDsOn());
    // gameState.setPlayerButton( _gameState->getPlayerButton()); // this is breaking the undo
    gameState.setTieBreak( _gameState->getTieBreak());
    gameState.setSetTieBreak( _gameState->getSetTieBreak());
    gameState.setSetTieBreakMem( _gameState->getSetTieBreakMem());
    gameState.setTieBreakOnly( _gameState->getTieBreakOnly());
    gameState.setTieBreakMem( _gameState->getTieBreakMem());
    // std::cout << "setting set histories..." << std::endl;
    gameState.setPlayer1SetHistory( _player1->getSetHistory());
    gameState.setPlayer2SetHistory( _player2->getSetHistory());

    _gameState->setPlayer1SetHistory( _player1->getSetHistory());
    _gameState->setPlayer2SetHistory( _player2->getSetHistory());
    // std::cout << "done setting set histories.  pushing gamestate to history..." << std::endl;
    history->push( gameState ); 
    
    
    // print size of gamestate
    // std::cout << "gamestate size: " << sizeof( gameState ) << std::endl;
    // std::cout << "done pushing gamestate to history." << std::endl; 
}

void Undo::mode1Undo( History* history ) {
    GameTimer::gameDelay( 100 );
    if ( history->size() == 0 ) { return; }
    // std::cout << "inside mode1Undo.  history->size()==" << history->size() << std::endl;
    GameState gameState = ( history->pop());
    _player1->setPoints( gameState.getPlayer1Points());
    _gameState->setP1PointsMem( gameState.getP1PointsMem());
    _player2->setPoints( gameState.getPlayer2Points());
    _gameState->setP2PointsMem( gameState.getP2PointsMem());
    _player1->setGames( gameState.getPlayer1Games());
    _gameState->setP1GamesMem( gameState.getP1GamesMem());
    _player2->setGames( gameState.getPlayer2Games());
    _gameState->setP2GamesMem( gameState.getP2GamesMem());
    _player1->setSets( &gameState, gameState.getPlayer1Sets());
    _gameState->setP1SetsMem( gameState.getP1SetsMem());
    _player2->setSets( &gameState, gameState.getPlayer2Sets());
    _gameState->setP2SetsMem( gameState.getP2SetsMem());
    _player1->setMatches( gameState.getPlayer1Matches());
    _player2->setMatches( gameState.getPlayer2Matches());
    _gameState->setServe( gameState.getServe());
    _gameState->setServeSwitch( gameState.getServeSwitch());
    _gameState->setUndo( gameState.getUndo());
    _gameState->setStarted( gameState.getStarted());
    _gameState->setPointFlash( gameState.getPointFlash());
    _gameState->setRotaryPosition( gameState.getRotaryPosition());
    _gameState->setPrevRotaryPosition( gameState.getPrevRotaryPosition());
    _gameState->setRotaryChange( gameState.getRotaryChange());
    _gameState->setToggle( gameState.getToggle());
    _gameState->setTieLEDsOn( gameState.getTieLEDsOn());
    // _gameState->setPlayerButton( gameState.getPlayerButton()); // this is breaking the undo
    _gameState->setTieBreak( gameState.getTieBreak());
    _gameState->setSetTieBreak( gameState.getSetTieBreak());
    _gameState->setSetTieBreakMem( gameState.getSetTieBreakMem());
    _gameState->setTieBreakOnly( gameState.getTieBreakOnly());
    _gameState->setTieBreakMem( gameState.getTieBreakMem());
    if ( _gameState->getTieLEDsOn() == 1 ) { _gameState->setTieLEDsOn( 1 );  _tieLeds.turnOn(); }
    if ( _gameState->getTieLEDsOn() == 0 ) {  _tieLeds.turnOff(); _gameState->setTieLEDsOn( 0 );  } 
    _logger->logUpdate( "updating leds...", __FUNCTION__ );
    _pointLeds.updatePoints(); _gameLeds.updateGames(); _setLeds.updateSets(); _serveLeds.updateServeLED(); }