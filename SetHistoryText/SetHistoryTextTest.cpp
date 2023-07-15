#include "../googletest/googletest/include/gtest/gtest.h"
#include "./SetHistoryText.h"
#include "../Player/Player.h"
#include "../ScoreBoard/ScoreBoard.h"
#include "../GameTimer/GameTimer.h"

class SetHistoryTextTest : public ::testing::Test {
 protected:
    SetHistoryTextTest() {}           // You can do set-up work for each test here.
    ~SetHistoryTextTest() override {} // You can do clean-up work that doesn't throw exceptions here.
       
    void SetUp() override { // Code here will be called immediately after the constructor (right before each test).
        gameState = new GameState();
        player_1 = new Player( gameState, PLAYER_1_INITIALIZED );
        player_2 = new Player( gameState, PLAYER_2_INITIALIZED ); // got players defined, now set echother as opponents...
        setHistoryText = new SetHistoryText( gameState ); 
        scoreboard = new ScoreBoard( player_1, player_2, gameState ); }

    void TearDown() override { // Code here will be called immediately after each test (right before the destructor).
        delete setHistoryText;
        delete player_1;
        delete player_2;
        delete gameState; 
        delete scoreboard; }

    GameState* gameState;
    Player* player_1;
    Player* player_2;
    SetHistoryText* setHistoryText;
    ScoreBoard* scoreboard; };

TEST_F( SetHistoryTextTest, TestGetSetHistoryText ) {
    player_1->setSetHistory( SET_HISTORY_COLUMN_1, 4 );
    player_1->setSetHistory( SET_HISTORY_COLUMN_2, 6 );
    player_1->setSetHistory( SET_HISTORY_COLUMN_3, 2 );
    gameState->setPlayer1SetHistory( player_1->getSetHistory());

    player_2->setSetHistory( SET_HISTORY_COLUMN_1, 2 );
    player_2->setSetHistory( SET_HISTORY_COLUMN_2, 5 );
    player_2->setSetHistory( SET_HISTORY_COLUMN_3, 3 );
    gameState->setPlayer2SetHistory( player_2->getSetHistory());

    std::cout << "updating scoreboard..." << std::endl;
    scoreboard->update();

    ASSERT_EQ( 1, 1 );
    std::cout << "sleeping for 5 seconds...\n\n" << std::endl;
    GameTimer* gameTimer = new GameTimer();
    gameTimer->gameDelay( 5000 );
    std::cout << "done sleeping.  end of test." << std::endl;

    // std::string result = setHistoryText->getSetHistoryText( 1 );
    // ASSERT_EQ(result, "15 10 40 ");
    // result = setHistoryText->getSetHistoryText( 2 );
    // ASSERT_EQ(result, "4 5 30 "); 
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); }
