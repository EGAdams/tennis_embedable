#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../Player/Player.h"
#include <string>
#include <iostream>
#include <map>

class GameState {
 public:
    GameState();
    ~GameState();
    void stopGameRunning();
    int gameRunning();
    void setSetHistory(  std::map< int, int > set_history  ); std::map< int, int > getSetHistory();
    void setGameHistory( std::map< int, int > game_history ); std::map< int, int > getGameHistory();
    void setCurrentAction(std::string currentAction        ); std::string getCurrentAction();
    void setCurrentSet( int current_set );                int getCurrentSet();
    void setWinDelay( int winDelay);                      int getWinDelay();
    void setPointFlash( int pointFlash);                  int getPointFlash();
    void setServe( int serve );                           int getServe();
    void setTieBreak( int tieBreak );                     int getTieBreak();
    void setTieLEDsOn( int tieLEDsOn );                   int getTieLEDsOn();
    void setServeSwitch( int serveSwitch);                int getServeSwitch();
    void setPlayerButton( int playerButton );             int getPlayerButton();
    void setUndo( int undo);                              int getUndo();
    void setStarted( int started);                        int getStarted();
    void setSetTieBreak( int setTieBreak );               int getSetTieBreak();
    void setRotaryChange( int rotaryChange );             int getRotaryChange();
    void setPreviousTime(unsigned long previousTime );    int getRotaryPosition();
    void setRotaryPosition( int rotaryPosition );         int getPrevRotaryPosition();
    void setPrevRotaryPosition( int prevRotaryPosition ); unsigned long getPreviousTime();
    void setFreezePlayerButton( int freezePlayerButton ); int getFreezePlayerButton();
    void setP1PointsMem( int p1PointsMem );               int getP1PointsMem();
    void setP2PointsMem( int p2PointsMem );               int getP2PointsMem();
    void setP1GamesMem( int p1GamesMem );                 int getP1GamesMem();
    void setP2GamesMem( int p2GamesMem );                 int getP2GamesMem();
    void setP1SetsMem( int p1SetsMem );                   int getP1SetsMem();
    void setP2SetsMem( int p2SetsMem );                   int getP2SetsMem();
    void setNow(unsigned long now);                       unsigned long getNow();
    void setToggle( int toggle );                         int getToggle();
    void setTieBreakOnly( int tieBreakOnly);              int getTieBreakOnly();
    void setButtonDelay( int buttonDelay);                int getButtonDelay();
    void setFlashDelay(unsigned long flashDelay);         unsigned long getFlashDelay();
    void setGameWinPulseCount( int gameWinPulseCount);    int getGameWinPulseCount();
    void setTieBreakMem( int tieBreakMem );               int getTieBreakMem();
    void setSetTieBreakMem( int setTieBreakMem );         int getSetTieBreakMem();
    void setGameFlashDelay( int gameFlashDelay);          int getGameFlashDelay();
    void setPlayer1Points( int player1Points );           int getPlayer1Points();  
    void setPlayer2Points( int player2Points );           int getPlayer2Points();
    void setPlayer1Games( int player1Games );             int getPlayer1Games();
    void setPlayer2Games( int player2Games );             int getPlayer2Games();
    void setPlayer1Sets( int player1Sets );               int getPlayer1Sets();
    void setPlayer2Sets( int player2Sets );               int getPlayer2Sets();
    void setPlayer1Matches( int player1Matches );         int getPlayer1Matches();
    void setPlayer2Matches( int player2Matches );         int getPlayer2Matches();
    void setPlayer1SetHistory( std::map< int, int> _player1_set_history ); std::map< int, int> getPlayer1SetHistory(); 
    void setPlayer2SetHistory( std::map< int, int> _player2_set_history ); std::map< int, int> getPlayer2SetHistory();
   
 private:
    int _current_set;
    int _player1_points;  int _player2_points;
    int _player1_games;   int _player2_games;
    int _player1_sets;    int _player2_sets;
    int _player1_matches; int _player2_matches;
    int _pointFlash;
    int _serve;
    int _tieBreak;
    int _setTieBreak;
    int _tieLEDsOn;
    int _started;
    int _serveSwitch;
    int _playerButton;
    int _undo;
    int _rotaryPosition;
    int _prevRotaryPosition;
    int _rotaryChange;
    unsigned long _now;
    unsigned long _previousTime;
    int _freezePlayerButton;
    int _p1PointsMem; int _p2PointsMem;
    int _p1GamesMem;  int _p2GamesMem;
    int _p1SetsMem;   int _p2SetsMem;
    int _toggle;
    int _tieBreakOnly;
    int _winDelay;
    int _buttonDelay;
    unsigned long _flashDelay;
    int _gameFlashDelay;
    int _gameWinPulseCount;
    int _setTieBreakMem;
    int _tieBreakMem;
    int _gameRunning;
    std::string _currentAction;
    std::map< int, int> _player1_set_history;
    std::map< int, int> _player2_set_history; };
#endif