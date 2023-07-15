#ifndef SET_HISTORY_TEXT_H
#define SET_HISTORY_TEXT_H

#include <string>
#include <map>
#include "../GameState/GameState.h"
#include "../TennisConstants/TennisConstants.h"

class SetHistoryText {
 public:
    SetHistoryText( GameState* gameState );
    ~SetHistoryText();
    std::string getSetHistoryText( int player );
    std::string _buildString(      int player );

 private: 
    GameState* _gameState; };
#endif