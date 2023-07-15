#include "Mode1Tiebreaker.h"

Mode1TieBreaker::Mode1TieBreaker( Player* player1,
    Player* player2,
    PinInterface* pinInterface,
    GameState* gameState,
    History* history )
    : _player1( player1 ),
    _player2( player2 ),
    _pinInterface( pinInterface ),
    _gameState( gameState ),
    _history( history ),
    _pointLeds( player1, player2, pinInterface ),
    _gameLeds( player1, player2, pinInterface ),
    _serveLeds( pinInterface, gameState ),
    _setLeds( player1, player2, pinInterface ),
    _mode1WinSequences( player1, player2, pinInterface, gameState ),
    _undo( player1, player2, pinInterface, gameState ) {}

Mode1TieBreaker::~Mode1TieBreaker() {}

void Mode1TieBreaker::tieLEDsOn() {
    _gameState->setTieLEDsOn( 1 );
    _pinInterface->pinDigitalWrite( P1_TIEBREAKER, HIGH );
    _pinInterface->pinDigitalWrite( P2_TIEBREAKER, HIGH ); }

void Mode1TieBreaker::tieLEDsOff() {
    _gameState->setTieLEDsOn( 0 );
    _pinInterface->pinDigitalWrite( P1_TIEBREAKER, LOW );
    _pinInterface->pinDigitalWrite( P2_TIEBREAKER, LOW ); }

void Mode1TieBreaker::mode1TBButtonFunction() {
    switch ( _gameState->getPlayerButton() ) {
    case 0:
        break;

    case 1:
        GameTimer::gameDelay( _gameState->getButtonDelay());
        _undo.setMode1Undo( _history );                  // SetMode1Undo();
        _player1->setGames( _player1->getGames() + 1 );  // p1Games++;
        mode1TBP1Games();                              // Mode1TBP1Games();
        break;

    case 2:
        GameTimer::gameDelay( _gameState->getButtonDelay());
        _undo.mode1Undo( _history );
        break;

    case 3:
        GameTimer::gameDelay( _gameState->getButtonDelay());
        _undo.setMode1Undo( _history );
        _player2->setGames( _player2->getGames() + 1 );
        mode1TBP2Games();
        break;

    case 4:
        GameTimer::gameDelay( _gameState->getButtonDelay());
        _undo.mode1Undo( _history );
        break;
    }
    _gameState->setPlayerButton( 0 );
}

void Mode1TieBreaker::tieBreaker() { _undo.memory(); mode1TBButtonFunction(); }

void Mode1TieBreaker::mode1SetTBButtonFunction() {
    switch ( _gameState->getPlayerButton()) {
    case 0:
        break;

    case 1:
        GameTimer::gameDelay( _gameState->getButtonDelay());
        _undo.setMode1Undo( _history );
        _player1->setGames( _player1->getGames() + 1 );
        mode1SetTBP1Games();
        break;

    case 2:
        GameTimer::gameDelay( _gameState->getButtonDelay());
        _undo.mode1Undo( _history );
        break;

    case 3:
        GameTimer::gameDelay( _gameState->getButtonDelay());
        _undo.setMode1Undo( _history );
        _player2->setGames( _player2->getGames() + 1 );
        mode1SetTBP2Games();
        break;

    case 4:
        GameTimer::gameDelay(
            _gameState
            ->getButtonDelay());
        _undo.mode1Undo( _history );
        break;
    }
    _gameState->setPlayerButton( 0 );
}

void Mode1TieBreaker::setTieBreaker() { _undo.memory(); mode1SetTBButtonFunction(); }

void Mode1TieBreaker::tieBreakEnable() {
    std::cout << "*** tieBreakEnable() called. ***" << std::endl;
    _player1->setPoints( 5 );
    _player2->setPoints( 5 );
    // std::cout << "*** calling _pointLeds.updatePoints() from inside tieBreakEnable()... ***" << std::endl;
    _pointLeds.updatePoints();
    std::cout << "*** after update points in tie breaker!!! *** " << std::endl;
    _gameState->setServeSwitch( 1 );
    _gameState->setServe( 0 );
    _serveLeds.serveSwitch();
    if ( _gameState->getTieLEDsOn() == 0 ) { tieLEDsOn(); }
    _player1->setGames( 6 );
    _player2->setGames( 6 );
    _gameLeds.updateGames();
    Inputs _inputs( _player1, _player2, _pinInterface, _gameState );
    WatchTimer _watchTimer;
    for ( int currentPulseCount = 0; currentPulseCount < TIE_PULSE_COUNT; currentPulseCount++ ) {
        tieLEDsOff();
        if ( _watchTimer.watchInputDelay( TIE_BREAK_BLINK_DELAY, &_inputs, TIE_BREAK_WATCH_INTERVAL ) > 0 ) { return; }
        tieLEDsOn();
        if ( _watchTimer.watchInputDelay( TIE_BREAK_BLINK_DELAY, &_inputs, TIE_BREAK_WATCH_INTERVAL ) > 0 ) { return; }}
    _player1->setGames( 0 );
    _player2->setGames( 0 );
    _gameLeds.updateGames();
    GameTimer::gameDelay( UPDATE_DISPLAY_DELAY );
    tieLEDsOn(); } // not coming on?

void Mode1TieBreaker::setTieBreakEnable() {
    _player1->setPoints( 4 );
    _player2->setPoints( 4 );
    _pointLeds.updatePoints();
    _gameState->setServeSwitch( 1 );
    _gameState->setServe( 0 );
    _serveLeds.serveSwitch();
    Inputs _inputs( _player1, _player2, _pinInterface, _gameState );
    WatchTimer _watchTimer;
    for ( int currentPulseCount = 0; currentPulseCount < TIE_PULSE_COUNT; currentPulseCount++ ) {
        tieLEDsOff();
        if ( _watchTimer.watchInputDelay( TIE_BREAK_BLINK_DELAY, &_inputs, TIE_BREAK_WATCH_INTERVAL ) > 0 ) { return; }
        tieLEDsOn();
        if ( _watchTimer.watchInputDelay( TIE_BREAK_BLINK_DELAY, &_inputs, TIE_BREAK_WATCH_INTERVAL ) > 0 ) { return; }}
    if ( _gameState->getTieLEDsOn() == 0 ) { tieLEDsOn(); }
    _player1->setGames( 0 );
    _player2->setGames( 0 );
    _gameLeds.updateGames();
    GameTimer::gameDelay( UPDATE_DISPLAY_DELAY  ); }

void Mode1TieBreaker::endTieBreak() {
    tieLEDsOff();
    _player1->setPoints( 0 );
    _player2->setPoints( 0 );
    _player1->setGames( 0 );
    _player2->setGames( 0 );
    _pointLeds.updatePoints();
    _gameLeds.updateGames();
    _gameState->setTieBreak( 0 );
    _gameState->setSetTieBreak( 0 ); }

void Mode1TieBreaker::mode1TBP1Games() {
    _gameLeds.updateGames();  // UpdateGames();
    _gameState->setServeSwitch( _gameState->getServeSwitch() + 1 );
    GameTimer::gameDelay( UPDATE_DISPLAY_DELAY );

    if ( _player1->getGames() == 15 ) {
        _player1->setSets( _gameState, _player1->getSets() + 1 );;

        if ( _player2->getSets() == _player1->getSets()) {
            endTieBreak();
            _mode1WinSequences.p1TBSetWinSequence();
            _gameState->setSetTieBreak( 1 );          
            setTieBreakEnable();                     
        } else {
            _mode1WinSequences.p1SetWinSequence();  
            endTieBreak(); }}
    if ( _player1->getGames() >= 10 && ( _player1->getGames() - _player2->getGames() ) > 1 ) {
        _player1->setSets( _gameState, _player1->getSets() + 1 );
        if ( _player2->getSets() == _player1->getSets()) {
            endTieBreak();                         
            _mode1WinSequences.p1TBSetWinSequence(); 
            _gameState->setSetTieBreak( 1 );           
            setTieBreakEnable();                    
        } else {
            _mode1WinSequences.p1SetWinSequence();  
            endTieBreak(); }}}

void Mode1TieBreaker::mode1TBP2Games() {
    _gameLeds.updateGames();
    _gameState->setServeSwitch( _gameState->getServeSwitch() + 1 );
    GameTimer::gameDelay( UPDATE_DISPLAY_DELAY );

    if ( _player2->getGames() == 15 ) {
        _player1->setSetHistory( _gameState->getCurrentSet(), _player1->getGames());
        _player2->setSetHistory( _gameState->getCurrentSet(), _player2->getGames());
        _gameState->setCurrentSet( _gameState->getCurrentSet() + 1 );
        _player2->setSets( _gameState, _player2->getSets() + 1 );
        if ( _player2->getSets() == _player1->getSets() ) {
            endTieBreak();                        
            _mode1WinSequences.p2TBSetWinSequence(); 
            _gameState->setSetTieBreak( 1 );
            setTieBreakEnable();
        } else {
            _mode1WinSequences.p2SetWinSequence();
            endTieBreak(); }}
    if ( _player2->getGames() >= 10 && ( _player2->getGames() - _player1->getGames() ) > 1 ) {
        _player1->setSetHistory( _gameState->getCurrentSet(), _player1->getGames());
        _player2->setSetHistory( _gameState->getCurrentSet(), _player2->getGames());
        _gameState->setCurrentSet( _gameState->getCurrentSet() + 1 );
        _player2->setSets( _gameState, _player2->getSets() + 1 );
        if ( _player2->getSets() == _player1->getSets() ) {
            endTieBreak();
            _mode1WinSequences.p2TBSetWinSequence();
            _gameState->setSetTieBreak( 1 );
            setTieBreakEnable();
        } else {
            _mode1WinSequences.p2SetWinSequence();
            endTieBreak();
        }}}

void Mode1TieBreaker::mode1SetTBP2Games() {
    _gameLeds.updateGames();
    GameTimer::gameDelay( UPDATE_DISPLAY_DELAY );
    if ( _player2->getGames() == 7 ) {
        _player1->setSetHistory( _gameState->getCurrentSet(), _player1->getGames());
        _player2->setSetHistory( _gameState->getCurrentSet(), _player2->getGames());
        _gameState->setCurrentSet( _gameState->getCurrentSet() + 1 );
        _player2->setSets( _gameState, _player2->getSets() + 1 );
        // _setLeds.updateSets();
        // GameTimer::gameDelay( UPDATE_DISPLAY_DELAY );
        _mode1WinSequences.p2SetTBWinSequence();
        tieLEDsOff();
        _mode1WinSequences.p2MatchWinSequence(); 
        _gameState->stopGameRunning(); }
    _gameState->setServeSwitch( _gameState->getServeSwitch() + 1 ); }

void Mode1TieBreaker::mode1SetTBP1Games() {
    _gameLeds.updateGames();
    GameTimer::gameDelay( UPDATE_DISPLAY_DELAY );
    if ( _player1->getGames() == 7 ) {
        _player1->setSetHistory( _gameState->getCurrentSet(), _player1->getGames());
        _player2->setSetHistory( _gameState->getCurrentSet(), _player2->getGames());
        _gameState->setCurrentSet( _gameState->getCurrentSet() + 1 );
        _player1->setSets( _gameState, _player1->getSets() + 1 );
        // _setLeds.updateSets();                // blinking one to many
        // GameTimer::gameDelay( UPDATE_DISPLAY_DELAY );
        _mode1WinSequences.p1SetTBWinSequence();
        tieLEDsOff();
        _mode1WinSequences.p1MatchWinSequence(); 
        _gameState->stopGameRunning(); }
    _gameState->setServeSwitch( _gameState->getServeSwitch() + 1 ); }