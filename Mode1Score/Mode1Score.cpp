#include "Mode1Score.h"

Mode1Score::Mode1Score( Player* player1,
    Player* player2,
    PinInterface* pinInterface,
    GameState* gameState,
    History* history )
    : _player1( player1 ),
    _player2( player2 ),
    _gameState( gameState ),
    _history( history ),
    _mode1TieBreaker( player1, player2, pinInterface, gameState, history ),
    _pointLeds( player1, player2, pinInterface ),
    _gameLeds( player1, player2, pinInterface ),
    _setLeds( player1, player2, pinInterface ),
    _mode1WinSequences( player1, player2, pinInterface, gameState ),
    _undo( player1, player2, pinInterface, gameState ) {}
Mode1Score::~Mode1Score() {}

void Mode1Score::setScoreBoard( ScoreBoard* scoreBoard ) { 
    _pointLeds.setScoreBoard(         scoreBoard ); 
    _gameLeds.setScoreBoard(          scoreBoard ); 
    _mode1WinSequences.setScoreBoard( scoreBoard ); 
    _setLeds.setScoreBoard(           scoreBoard ); }

void Mode1Score::_resetGame() {
     GameTimer::gameDelay( UPDATE_DISPLAY_DELAY );
    _player1->setPoints( 0 );
    _player2->setPoints( 0 );
    _gameState->setServeSwitch( 1 );
    _gameState->setServe( 0 );
    _pointLeds.updatePoints(); }

void Mode1Score::mode1P1Score() {
    if ( _player1->getPoints() >= 3 ) {
        if ( _player1->getPoints() == _player2->getPoints()) {
            // Tie, Back to Deuce
            _player1->setPoints( 3 );
            _player2->setPoints( 3 );
        } else if ( _player1->getPoints() > 3 && ( _player1->getPoints() - _player2->getPoints()) > 1 ) {
            // Game win Scenario
            _player1->setGames( _player1->getGames() + 1 );
            _undo.memory();
            _pointLeds.updatePoints();
            mode1P1Games(); }
        if ( _player1->getPoints() == 4 ) {
            _gameState->setPointFlash( 1 );
            _gameState->setPreviousTime( GameTimer::gameMillis());
            _gameState->setToggle( 0 ); }}
    _pointLeds.updatePoints(); }

void Mode1Score::mode1P2Score() {
    if ( _player2->getPoints() >= 3 ) {
        if ( _player2->getPoints() == _player1->getPoints()) {  // Tie, Back to Deuce
            _player1->setPoints( 3 );
            _player2->setPoints( 3 );    // Game win Scenario Below
        } else if ( _player2->getPoints() > 3 && ( _player2->getPoints() - _player1->getPoints()) > 1 ) {                                // Game win Scenario
            // Game win Scenario
            _player2->setGames( _player2->getGames() + 1 );
            _undo.memory();
            _pointLeds.updatePoints();
            mode1P2Games(); }
        if ( _player2->getPoints() == 4 ) {
            _gameState->setPointFlash( 1 );
            _gameState->setPreviousTime( GameTimer::gameMillis());
            _gameState->setToggle( 0 ); }}
    _pointLeds.updatePoints(); }

/////////////////////////////////////// MODE 1 GAMES //////////////////////////////////////////////
void Mode1Score::mode1P1Games() {
    _gameLeds.updateGames();
    _gameState->setServeSwitch( _gameState->getServeSwitch() + 1 );
    if ( _player1->getGames() >= GAMES_TO_WIN_SET ) {
        if ( _player1->getGames() == GAMES_TO_WIN_SET && _player2->getGames() == GAMES_TO_WIN_SET ) {
            _gameState->setTieBreak( 1 );
            _mode1TieBreaker.tieBreakEnable(); }

        if ( _gameState->getTieBreak() == 0 ) {
            std::cout << "*** tie break is zero.  checking if p1 games - p2 games > 1... ***" << std::endl;
            if( !_player1 || !_player2 ) { std::cout << "*** ERROR: player1 or player2 is NULL.  exiting... ***" << std::endl; exit( 1 ); }
            std::cout << "*** player1 games: " << _player1->getGames() << " player2 games: " << _player2->getGames() << std::endl;
            if (( _player1->getGames() - _player2->getGames()) > 1 ) {
                std::cout << "*** setting sets for player 1... ***" << std::endl;
                _player1->setSets( _gameState, _player1->getSets() + 1 ); // <-------------<< Increment Player Sets
                _setLeds.updateSets();
                if ( _player1->getSets() == _player2->getSets()) {        // <-------------<< Set Tie Break
                    std::cout << "*** calling p1TBSetWinSequence() ***" << std::endl;
                    _mode1WinSequences.p1TBSetWinSequence();
                    _gameState->setSetTieBreak( 1 );
                    _mode1TieBreaker.setTieBreakEnable();
                } else if ( _player1->getSets() == SETS_TO_WIN_MATCH ) {
                    std::cout << "*** calling p1MatchWinSequence() ***" << std::endl;
                    _mode1WinSequences.p1MatchWinSequence();             // <-------------<< Match Win
                    _gameState->stopGameRunning();
                } else {                                                 // <-------------<< Set Win
                    std::cout << "*** /// calling p1SetWinSequence() point gap is 2 /// ***" << std::endl;
                    _gameState->setPlayer1SetHistory( _player1->getSetHistory());
                    _gameState->setPlayer2SetHistory( _player2->getSetHistory());
                    _gameState->setCurrentSet( _gameState->getCurrentSet() + 1 );
                    _mode1WinSequences.p1SetWinSequence();
                    _setLeds.updateSets();
                    GameTimer::gameDelay( _gameState->getWinDelay());
                    _resetGame(); }
                    std::cout << "*** setting games to 0 ***" << std::endl;
                    _player1->setGames( 0 );
                    _player2->setGames( 0 );
            } else {    // no set win, no match win, no tie break. just a regular game win.
                std::cout << "*** calling p1GameWinSequence() ***" << std::endl;
                _gameState->setPlayer1SetHistory( _player1->getSetHistory());
                _gameState->setPlayer2SetHistory( _player2->getSetHistory());
                _mode1WinSequences.p1GameWinSequence();  // sets player points to zero
                _gameLeds.updateGames();
                _resetGame();
            }}
    } else {
        std::cout << "*** calling p1GameWinSequence() ***" << std::endl;
        _gameState->setPlayer1SetHistory( _player1->getSetHistory());
        _gameState->setPlayer2SetHistory( _player2->getSetHistory());
        _mode1WinSequences.p1GameWinSequence();
        _gameLeds.updateGames();
        _resetGame(); }}

void Mode1Score::mode1P2Games() {
    // std::cout << "inside mode1P2Games().  updtating game leds..." << std::endl;
    _gameLeds.updateGames();
    // std::cout << "inside mode1P2Games().  setting serve switch..." << std::endl;
    _gameState->setServeSwitch( _gameState->getServeSwitch() + 1 );
    // std::cout << "serve switch set to: " << _gameState->getServeSwitch() << std::endl;
    if ( _player2->getGames()  >= GAMES_TO_WIN_SET ) {
        if ( _player2->getGames()  == GAMES_TO_WIN_SET && _player1->getGames() == GAMES_TO_WIN_SET ) {
            _gameState->setTieBreak( 1 );
            std::cout << "*** calling tieBreakEnable() from inside Mode1Score::mode1P2Games()... ***" << std::endl;
            _mode1TieBreaker.tieBreakEnable();
        }
        if ( _gameState->getTieBreak() == 0 ) {
            if (( _player2->getGames() - _player1->getGames()) > 1 ) {
                _player2->setSets( _gameState, _player2->getSets() + 1 ); // Increment Sets!
                _setLeds.updateSets();
                if ( _player2->getSets() == _player1->getSets()) {
                    _mode1WinSequences.p2TBSetWinSequence();
                    _gameState->setSetTieBreak( 1 );
                    _mode1TieBreaker.setTieBreakEnable();
                }
                else if ( _player2->getSets() == SETS_TO_WIN_MATCH ) {
                    _mode1WinSequences.p2MatchWinSequence();
                    _gameState->stopGameRunning();
                }  else {
                    std::cout << "** inside mode1P2Games().  calling p2SetWinSequence()... ***" << std::endl;
                    _player2->setGames( _player2->getGames() );
                    _gameState->setPlayer1SetHistory( _player1->getSetHistory());
                    _gameState->setPlayer2SetHistory( _player2->getSetHistory());
                    _gameState->setCurrentSet( _gameState->getCurrentSet() + 1 );
                    _mode1WinSequences.p2SetWinSequence();
                    _setLeds.updateSets();
                    GameTimer::gameDelay( _gameState->getWinDelay());
                    _resetGame();
                    std::cout << "*** setting games to 0 ***" << std::endl;
                    _player1->setGames( 0 );
                    _player2->setGames( 0 ); }}

                std::cout << "inside mode1P2Games().  setting games to 0..." << std::endl;
                _player1->setGames( 0 );
                _player2->setGames( 0 );
            } else {
                std::cout << "inside mode1P2Games().  calling p2GameWinSequence()..." << std::endl;
                _gameState->setPlayer1SetHistory( _player1->getSetHistory());
                _gameState->setPlayer2SetHistory( _player2->getSetHistory());
                _gameState->setCurrentSet( _gameState->getCurrentSet() + 1 );
                _mode1WinSequences.p2GameWinSequence();
                _gameLeds.updateGames();
                _resetGame(); }
    } else {
        _mode1WinSequences.p2GameWinSequence();  // sets player points to zero
        _gameState->setPlayer1SetHistory( _player1->getSetHistory());
        _gameState->setPlayer2SetHistory( _player2->getSetHistory());
        _gameLeds.updateGames();
        _resetGame(); }}
////////////////////////////////// END MODE 1 GAMES ///////////////////////////////////////////////

void Mode1Score::mode1TBP1Games() {
    _gameLeds.updateGames();
    _gameState->setServeSwitch( _gameState->getServeSwitch() + 1 );
    GameTimer::gameDelay( UPDATE_DISPLAY_DELAY );
    if ( _player1->getGames() == 15 ) {
        _player1->setSets( _gameState, _player1->getSets() + 1 );

        if ( _player2->getSets() == _player1->getSets()) {
            _mode1TieBreaker.endTieBreak();
            _mode1WinSequences.p1TBSetWinSequence();
            _gameState->setSetTieBreak( 1 );
            _mode1TieBreaker.setTieBreakEnable();
        }
        else {
            _player1->setGames( _player1->getGames() );
            _gameState->setPlayer1SetHistory( _player1->getSetHistory());
            _gameState->setPlayer2SetHistory( _player2->getSetHistory());
            _gameState->setCurrentSet( _gameState->getCurrentSet() + 1 );
            _mode1WinSequences.p1SetWinSequence();
            _mode1TieBreaker.endTieBreak();
        }}
    if ( _player1->getGames() >= 10 &&
        ( _player1->getGames() - _player2->getGames()) > 1 ) {
        _player1->setSets( _gameState, _player1->getSets() + 1 );
        if ( _player2->getSets() == _player1->getSets()) {
            _mode1TieBreaker.endTieBreak();
            _mode1WinSequences.p1TBSetWinSequence();
            _gameState->setSetTieBreak( 1 );
            _mode1TieBreaker.setTieBreakEnable();
        }
        else {
            _player1->setGames( _player1->getGames() );
            _gameState->setPlayer1SetHistory( _player1->getSetHistory());
            _gameState->setPlayer2SetHistory( _player2->getSetHistory());
            _gameState->setCurrentSet( _gameState->getCurrentSet() + 1 );
            _mode1WinSequences.p1SetWinSequence();
            _mode1TieBreaker.endTieBreak();
        }}}

void Mode1Score::mode1SetTBP1Games() {
    _gameLeds.updateGames();
    GameTimer::gameDelay( UPDATE_DISPLAY_DELAY );
    if ( _player1->getGames() == 7 ) {
        _player1->setSets( _gameState, _player1->getSets() + 1 );
        _setLeds.updateSets();
        GameTimer::gameDelay( UPDATE_DISPLAY_DELAY );
        _mode1WinSequences.p1SetTBWinSequence();
        _mode1TieBreaker.tieLEDsOff();
        _mode1WinSequences.p1MatchWinSequence();
        _gameState->stopGameRunning(); }
    _gameState->setServeSwitch( _gameState->getServeSwitch() + 1 ); }

void Mode1Score::mode1TBP2Games() {
    _gameLeds.updateGames();
    _gameState->setServeSwitch( _gameState->getServeSwitch() + 1 );
    GameTimer::gameDelay( UPDATE_DISPLAY_DELAY );
    if ( _player2->getGames() == 15 ) {
        _player2->setSets( _gameState, _player2->getSets() + 1 );
        if ( _player2->getSets() == _player1->getSets()) {
            _mode1TieBreaker.endTieBreak();
            _mode1WinSequences.p2TBSetWinSequence();
            _gameState->setSetTieBreak( 1 );
            _mode1TieBreaker.setTieBreakEnable();
        } else {
            _player1->setGames( _player1->getGames() );
            _gameState->setPlayer1SetHistory( _player1->getSetHistory());
            _gameState->setPlayer2SetHistory( _player2->getSetHistory());
            _gameState->setCurrentSet( _gameState->getCurrentSet() + 1 );
            _mode1WinSequences.p2SetWinSequence();
            _mode1TieBreaker.endTieBreak(); }}
    if ( _player2->getGames() >= 10 &&
        ( _player2->getGames() - _player1->getGames()) > 1 ) {
        _player2->setSets( _gameState, _player2->getSets() + 1 );
        if ( _player2->getSets() == _player1->getSets()) {
            _mode1TieBreaker.endTieBreak();
            _mode1WinSequences.p2TBSetWinSequence();
            _gameState->setSetTieBreak( 1 );
            _mode1TieBreaker.setTieBreakEnable();
        } else {
            _player1->setGames( _player1->getGames() );
            _gameState->setPlayer1SetHistory( _player1->getSetHistory());  // set set history, set++
            _gameState->setPlayer2SetHistory( _player2->getSetHistory());
            _gameState->setCurrentSet( _gameState->getCurrentSet() + 1 );
            _mode1WinSequences.p2SetWinSequence();
            _mode1TieBreaker.endTieBreak(); }}}

void Mode1Score::mode1SetTBP2Games() {
    _gameLeds.updateGames();
    GameTimer::gameDelay( UPDATE_DISPLAY_DELAY );
    if ( _player2->getGames() == 7 ) {
        _player2->setSets( _gameState, _player2->getSets() + 1 );
        _setLeds.updateSets();
        GameTimer::gameDelay( UPDATE_DISPLAY_DELAY );
        _mode1WinSequences.p2SetTBWinSequence();
        _mode1TieBreaker.tieLEDsOff();
        _mode1WinSequences.p2MatchWinSequence(); 
        _gameState->stopGameRunning(); }
    _gameState->setServeSwitch( _gameState->getServeSwitch() + 1 ); }