/*
 *  class SubjectManager
 *  stringifies the GameState object and writes it to disk
 */
#include "SubjectManager.h"

SubjectManager::SubjectManager() {
    _logger = new Logger( "SubjectManager" );
}
SubjectManager::~SubjectManager() {
    std::cout << "*** SubjectManager destructor called. ***" << std::endl;
    delete _logger;
}

#if defined _WIN32 || defined _WIN64
void SubjectManager::gameStateUpdate( GameState* gameState, Player* player1, Player* player2 ) {
    return;  // short circuit this function for Pi development
    std::string update_path = GAME_STATE_UPDATE_PATH;
    std::string stringifiedGameState( "{" );
    stringifiedGameState += "\"toggle\": \"" + std::to_string( gameState->getToggle() ) + "\",\n";
    stringifiedGameState += "\"started\": \"" + std::to_string( gameState->getStarted() ) + "\",\n";
    stringifiedGameState += "\"rotaryPosition\": \"" + std::to_string( gameState->getRotaryPosition() ) + "\",\n";
    stringifiedGameState += "\"prevRotaryPosition\": \"" + std::to_string( gameState->getPrevRotaryPosition() ) + "\",\n";
    stringifiedGameState += "\"playerButton\": \"" + std::to_string( gameState->getPlayerButton() ) + "\",\n";
    stringifiedGameState += "\"tieBreak\": \"" + std::to_string( gameState->getTieBreak() ) + "\",\n";
    stringifiedGameState += "\"serve\": \"" + std::to_string( gameState->getServe() ) + "\",\n";
    stringifiedGameState += "\"pointFlash\": \"" + std::to_string( gameState->getPointFlash() ) + "\",\n";
    stringifiedGameState += "\"undo\": \"" + std::to_string( gameState->getUndo() ) + "\",\n";
    stringifiedGameState += "\"rotaryChange\": \"" + std::to_string( gameState->getRotaryChange() ) + "\",\n";
    stringifiedGameState += "\"now\": \"" + std::to_string( gameState->getNow() ) + "\",\n";
    stringifiedGameState += "\"previousTime\": \"" + std::to_string( gameState->getPreviousTime() ) + "\",\n";
    stringifiedGameState += "\"tieLEDsOn\": \"" + std::to_string( gameState->getTieLEDsOn() ) + "\",\n";
    stringifiedGameState += "\"buttonDelay\": \"" + std::to_string( gameState->getButtonDelay() ) + "\",\n";
    stringifiedGameState += "\"flashDelay\": \"" + std::to_string( gameState->getFlashDelay() ) + "\",\n";
    stringifiedGameState += "\"gameFlashDelay\": \"" + std::to_string( gameState->getGameFlashDelay() ) + "\",\n";
    stringifiedGameState += "\"gameWinPulseCount\": \" " + std::to_string( gameState->getGameWinPulseCount() ) + "\",\n";
    stringifiedGameState += "\"setTieBreak\": \" " + std::to_string( gameState->getSetTieBreak() ) + "\",\n";
    stringifiedGameState += "\"serveSwitch\": \" " + std::to_string( gameState->getServeSwitch() ) + "\",\n";
    stringifiedGameState += "\"setTieBreakMem\": \" " + std::to_string( gameState->getSetTieBreakMem() ) + "\",\n";
    stringifiedGameState += "\"tieBreakMem\": \" " + std::to_string( gameState->getTieBreakMem() ) + "\",\n";
    stringifiedGameState += "\"p1PointsMem\": \"" + std::to_string( gameState->getP1PointsMem() ) + "\",\n";
    stringifiedGameState += "\"p2PointsMem\": \"" + std::to_string( gameState->getP2PointsMem() ) + "\",\n";
    stringifiedGameState += "\"p1GamesMem\": \"" + std::to_string( gameState->getP1GamesMem() ) + "\",\n";
    stringifiedGameState += "\"p2GamesMem\": \"" + std::to_string( gameState->getP2GamesMem() ) + "\",\n";
    stringifiedGameState += "\"p1SetsMem\": \"" + std::to_string( gameState->getP1SetsMem() ) + "\",\n";
    stringifiedGameState += "\"p2SetsMem\": \"" + std::to_string( gameState->getP2SetsMem() ) + "\",\n";
    stringifiedGameState += "\"tieBreakOnly\": \"" + std::to_string( gameState->getTieBreakOnly() ) + "\",\n";
    _logger->logUpdate( "getting player 1 points from game state [" + std::to_string( player1->getPoints() ) + "]", __FUNCTION__ );
    stringifiedGameState += "\"player_1_points\": \"" + std::to_string( player1->getPoints() ) + "\",\n";
    stringifiedGameState += "\"player_2_points\": \"" + std::to_string( player2->getPoints() ) + "\",\n";
    stringifiedGameState += "\"player_1_sets\": \"" + std::to_string( player1->getSets() ) + "\",\n";
    stringifiedGameState += "\"player_2_sets\": \"" + std::to_string( player2->getSets() ) + "\",\n";
    stringifiedGameState += "\"player_1_games\": \"" + std::to_string( player1->getGames() ) + "\",\n";
    stringifiedGameState += "\"player_2_games\": \"" + std::to_string( player2->getGames() ) + "\"\n";
    stringifiedGameState += "}";

    std::ofstream game_state_file( update_path + "game_state_data.txt" );
    game_state_file << stringifiedGameState;
    game_state_file.close();
}
#else // if NOT _WIN32
    void SubjectManager::gameStateUpdate( GameState* gameState, Player* player1, Player* player2 ){}
#endif
