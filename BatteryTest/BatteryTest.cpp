#include "BatteryTest.h"

BatteryTest::BatteryTest( Player* player1, Player* player2, PinInterface* pinInterface,  PointLeds* pointLeds, Inputs* inputs ):
    _player1( player1 ),
    _player2( player2 ),
    _pinInterface( pinInterface ),
    _pointLeds( pointLeds ),
    _inputs( inputs ) {}
BatteryTest::~BatteryTest() {}

void BatteryTest::execute() {
    while ( 1 ) {
        turnLedsOn( P1_POINTS_LED1, P1_POINTS_LED2, P1_POINTS_LED3, P1_POINTS_LED4, P2_POINTS_LED2, P2_POINTS_LED3 );
        if ( _watchTimer.watchInputDelay( BATTERY_TEST_DELAY, _inputs, WATCH_INTERVAL ) > 0 ) { return; };
        turnLedsOff();
        if ( flashLeds( P1_POINTS_LED1, P1_POINTS_LED2, P1_POINTS_LED3, P1_POINTS_LED4, P2_POINTS_LED2, P2_POINTS_LED3 ) > 0 ) { return; };

        turnLedsOn( P2_POINTS_LED1, P2_POINTS_LED4, P1_SERVE, P2_SERVE, P1_GAMES_LED0, P2_GAMES_LED0 );
        if ( _watchTimer.watchInputDelay( BATTERY_TEST_DELAY, _inputs, WATCH_INTERVAL ) > 0 ) { return; };
        turnLedsOff();
        if ( flashLeds(  P2_POINTS_LED1, P2_POINTS_LED4, P1_SERVE, P2_SERVE, P1_GAMES_LED0, P2_GAMES_LED0 ) > 0 ) { return; };

        turnLedsOn( P1_GAMES_LED1, P2_GAMES_LED1, P1_GAMES_LED2, P2_GAMES_LED2, P1_GAMES_LED3, P2_GAMES_LED3 );
        if ( _watchTimer.watchInputDelay( BATTERY_TEST_DELAY, _inputs, WATCH_INTERVAL ) > 0 ) { return; };
        turnLedsOff();
        if ( flashLeds( P1_GAMES_LED1, P2_GAMES_LED1, P1_GAMES_LED2, P2_GAMES_LED2, P1_GAMES_LED3, P2_GAMES_LED3 ) > 0 ) { return; };

        turnLedsOn( P1_GAMES_LED4, P2_GAMES_LED4, P1_GAMES_LED5, P2_GAMES_LED5, P1_GAMES_LED6, P2_GAMES_LED6 );
        if ( _watchTimer.watchInputDelay( BATTERY_TEST_DELAY, _inputs, WATCH_INTERVAL ) > 0 ) { return; };
        turnLedsOff();
        if ( flashLeds( P1_GAMES_LED4, P2_GAMES_LED4, P1_GAMES_LED5, P2_GAMES_LED5, P1_GAMES_LED6, P2_GAMES_LED6 ) > 0 ) { return; };

        turnLedsOn( P1_TIEBREAKER, P2_TIEBREAKER, P1_SETS_LED1, P2_SETS_LED1, P1_SETS_LED2, P2_SETS_LED2 );
        if ( _watchTimer.watchInputDelay( BATTERY_TEST_DELAY, _inputs, WATCH_INTERVAL ) > 0 ) { return; };
        turnLedsOff();
        if ( flashLeds( P1_TIEBREAKER, P2_TIEBREAKER, P1_SETS_LED1, P2_SETS_LED1, P1_SETS_LED2, P2_SETS_LED2 ) > 0 ) { return; };
        }

    } // end while( 1 )

void BatteryTest::turnLedsOn( int ledOne, int ledTwo, int ledThree, int ledFour, int ledFive, int ledSix ) {
    _pinInterface->pinDigitalWrite( ledOne,   HIGH );
    _pinInterface->pinDigitalWrite( ledTwo,   HIGH );
    _pinInterface->pinDigitalWrite( ledThree, HIGH );
    _pinInterface->pinDigitalWrite( ledFour,  HIGH );
    _pinInterface->pinDigitalWrite( ledFive,  HIGH );
    _pinInterface->pinDigitalWrite( ledSix,   HIGH ); }

int BatteryTest::flashLeds( int ledOne, int ledTwo, int ledThree, int ledFour, int ledFive, int ledSix ) {
    for ( int i = 0; i < BATTERY_TEST_FLASH_COUNT + 1; i++ ) {
        turnLedsOff();
        if ( _watchTimer.watchInputDelay( BATTERY_TEST_BLINK_DELAY, _inputs, WATCH_INTERVAL ) > 0 ) { return 1; }
        turnLedsOn( ledOne, ledTwo, ledThree, ledFour, ledFive, ledSix );
        if ( _watchTimer.watchInputDelay( BATTERY_TEST_BLINK_DELAY, _inputs, WATCH_INTERVAL ) > 0 ) { return 1; }}
    turnLedsOff();
    return 0; }

void BatteryTest::turnLedsOff() {
    _player1->setPoints( 100 );
    _player2->setPoints( 100 );
    _pointLeds->updatePoints();     // player 1 lamps off                                 // player 2 lamps off
    _pinInterface->pinDigitalWrite( P1_SERVE, LOW      ); _pinInterface->pinDigitalWrite( P2_SERVE,      LOW );
    _pinInterface->pinDigitalWrite( P1_GAMES_LED0, LOW ); _pinInterface->pinDigitalWrite( P2_GAMES_LED0, LOW );
    _pinInterface->pinDigitalWrite( P1_GAMES_LED1, LOW ); _pinInterface->pinDigitalWrite( P2_GAMES_LED1, LOW );
    _pinInterface->pinDigitalWrite( P1_GAMES_LED2, LOW ); _pinInterface->pinDigitalWrite( P2_GAMES_LED2, LOW );
    _pinInterface->pinDigitalWrite( P1_GAMES_LED3, LOW ); _pinInterface->pinDigitalWrite( P2_GAMES_LED3, LOW );
    _pinInterface->pinDigitalWrite( P1_GAMES_LED4, LOW ); _pinInterface->pinDigitalWrite( P2_GAMES_LED4, LOW );
    _pinInterface->pinDigitalWrite( P1_GAMES_LED5, LOW ); _pinInterface->pinDigitalWrite( P2_GAMES_LED5, LOW );
    _pinInterface->pinDigitalWrite( P1_GAMES_LED6, LOW ); _pinInterface->pinDigitalWrite( P2_GAMES_LED6, LOW );
    _pinInterface->pinDigitalWrite( P1_TIEBREAKER, LOW ); _pinInterface->pinDigitalWrite( P2_TIEBREAKER, LOW );
    _pinInterface->pinDigitalWrite( P1_SETS_LED1,  LOW ); _pinInterface->pinDigitalWrite( P2_SETS_LED1,  LOW );
    _pinInterface->pinDigitalWrite( P1_SETS_LED2,  LOW ); _pinInterface->pinDigitalWrite( P2_SETS_LED2,  LOW ); }
