#ifndef Player_h
#define Player_h
#include <map>
#include "../GameState/GameState.h"
#include "../TennisConstants/TennisConstants.h"
class GameState;
class Player {
 public:
    Player( GameState* gameState, int player_number );
    ~Player();
    
    void setOpponent(    Player* opponent                 ); Player* getOpponent();
    void setPoints(      int points                       ); int getPoints();
    void setGames(       int games                        ); int getGames();
    void setMatches(     int matches                      ); int getMatches();
    void setMode(        int mode                         ); int getMode();
    void setSetting(     int setting                      ); int getSetting();
    void setSet(         int set_number,   int set_value  ); int getSet(  int set_number  );
    void setGame(        int game_number,  int game_value ); int getGame( int game_number );
    void setSets(        GameState* state, int sets       ); int getSets();
    void setSetHistory(  int set, int score               ); std::map< int, int> getSetHistory();
    void setGameHistory( int game, int score              ); std::map< int, int> getGameHistory();
    int incrementSetting();
    int number(); // only set during construction

 private:
    GameState* _gameState;
    int _playerNumber;
    Player* _opponent;
    int _points;
    int _games;
    int _sets;
    int _matches;
    int _mode;
    int _setting;
    std::map<int, int> _set_history;
    std::map<int, int> _game_history; };
#endif