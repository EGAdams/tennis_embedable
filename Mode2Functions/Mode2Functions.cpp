#include "Mode2Functions.h"

Mode2Functions::Mode2Functions(Player* player1,
                               Player* player2,
                               PinInterface* pinInterface,
                               GameState* gameState)
    : _player1(player1),
      _player2(player2),
      _gameState(gameState),
      _pointLeds(player1, player2, pinInterface),
      _gameLeds(player1, player2, pinInterface),
      _setLeds(player1, player2, pinInterface){};

Mode2Functions::~Mode2Functions() {}

void Mode2Functions::m2Loop() {
  _gameState->setNow(/* now = */ GameTimer::gameMillis());
  // unsigned long elapsed_time = now -  previous_time;
  // Serial.println( "elapsed_time: " + to_string( elapsed_time ));
  if (_gameState->getNow() /* now */ -
          _gameState->getPreviousTime() /* previous_time */
      >= 1000 /*10000*/) {
    // if ( true ) {
    switch (_player1->getMode()) { /* modeP1 */

      // _player1 Points
      case 0:
        _player1->incrementSetting();                 // p1Setting++;
        _player1->setPoints(_player1->getSetting());  //  p1Points = p1Setting;
        _pointLeds.updatePoints();                    // UpdatePoints();
        if (_player1->getSetting() > 3) /* p1Setting > 3 */ {
          _player1->setSetting(0);  // p1Setting = 0;
          _player1->setPoints(0);   // p1Points = 0;
          _player1->setMode(1);     // modeP1 = 1;
          // Serial.println( "_player1 set to mode 1" );
        }
        break;

      // _player1 Games
      case 1:
        _player1->incrementSetting();                // p1Setting++;
        _player1->setGames(_player1->getSetting());  // p1Games = p1Setting;
        _gameLeds.updateGames();                     // UpdateGames();
        if (_player1->getSetting() > 6 /* p1Setting > 6 */) {
          _player1->setSetting(0);  // p1Setting = 0;
          _player1->setGames(0);    // p1Games = 0;
          _player1->setMode(2);     //   modeP1 = 2;
          // Serial.println( "_player1 set to mode 2" );
        }
        break;

      // _player1 Sets
      case 2:
        _player1->incrementSetting();
        _player1->setSets( _gameState, _player1->getSetting());
        _setLeds.updateSets();                      
        if (_player1->getSetting() > 1 ) {
          _player1->setSetting( 0 );  
          _player1->setSets( _gameState, 0 );
          _player1->setMode( 0 );     
        }
        break;
    }

    // _player2 Points
    switch (_player2->getMode() ) {
      case 0:
        // _player2->incrementSetting();
        _player2->setPoints(
            _player2->incrementSetting());
        _pointLeds.updatePoints();         
        if (_player2->getSetting() > 4 ) {
          _player2->setSetting(0);
          _player2->setPoints(0);
          _player2->setMode(1);
        }
        break;

      // _player2 Games
      case 1:
        // p2Setting++;
        // p2Games = p2Setting;
        _player2->setGames(
            _player2->incrementSetting());  // p2Games = p2Setting;
        _gameLeds.updateGames();            // UpdateGames();
        if (_player2->getSetting() > 7) /* p2Setting > 7 */ {
          _player2->setSetting(0);  // p2Setting = 0;
          _player2->setGames(0);    // p2Games = 0;
          _player2->setMode(2);     // modeP2 = 2;
        }
        break;

      // _player2 Sets
      case 2:
        // p2Setting++;
        _player2->setSets( _gameState, _player2->incrementSetting());  // p2Sets = p2Setting;
        _setLeds.updateSets();
        if (_player2->getSetting() > 1 ) {
          _player2->setSetting(0);  
          _player2->setSets(_gameState, 0 );
          _player2->setMode( 0 );   
        }
    }
    _gameState->setPreviousTime(_gameState->getNow());  
  } else { /* Serial.println("*** DID NOT ENTER BECAUSE NOT ENOUGH TIME HAS PASSED */ }
}

void Mode2Functions::m2PlayerButtons(int playerButton) {
  switch (playerButton) {
    case 0:
      break;

    case 1:
      // Serial.println("p1 Set 1 LED");
      _player1->setSetting(_player1->getSetting() + 1);  //  p1Setting++;
      _gameState->setNow(_gameState->getNow() +
                         10000);  // now = ( now + 10000 );
      // Mode2Button1();
      break;

    case 2:
      // Serial.println("p1 Set 2 LED");
      _player1->setSetting(_player1->getSetting() - 1);  // p1Setting--;
      _gameState->setNow(_gameState->getNow() +
                         10000);  // now = ( now + 10000 );
      //      Mode2Button2();
      break;

    case 3:
      // Serial.println("p2 Set 2 LED");
      _player2->setSetting(_player2->getSetting() + 1);  // p2Setting++;
      _gameState->setNow(_gameState->getNow() +
                         10000);  // now = ( now + 10000 );
      //      Mode2Button3();
      break;

    case 4:
      // Serial.println("p2 Set 1 LED");
      _player1->setSetting(_player1->getSetting() - 1);  // p2Setting--;
      _gameState->setNow(_gameState->getNow() +
                         10000);  // now = ( now + 10000 );
      //      Mode2Button4();
      break;
  }
  _gameState->setPlayerButton(0);  // playerButton = 0;
}

// void Mode2Button1() {
//   if (p1s1 == 0) {
//     pinAnalogWrite(P1_SETS_LED1, HIGH);
//     p1s1 = 1;
//   }
//   else {
//     pinAnalogWrite(P1_SETS_LED1, LOW);
//     p1s1 = 0;
//   }
// }
//
// void Mode2Button2() {
//   if (p1s2 == 0) {
//     pinAnalogWrite(P1_SETS_LED2, HIGH);
//     p1s2 = 1;
//   }
//   else {
//     pinAnalogWrite(P1_SETS_LED2, LOW);
//     p1s2 = 0;
//   }
// }
//
// void Mode2Button3() {
//   if (p1s3 == 0) {
//     pinAnalogWrite(P2_SETS_LED2, HIGH);
//     p1s3 = 1;
//   }
//   else {
//     pinAnalogWrite(P2_SETS_LED2, LOW);
//     p1s3 = 0;
//   }
// }
//
// void Mode2Button4() {
//   if (p1s4 == 0) {
//     pinAnalogWrite(P2_SETS_LED1, HIGH);
//     p1s4 = 1;
//   }
//   else {
//     pinAnalogWrite(P2_SETS_LED1, LOW);
//     p1s4 = 0;
//   }
// }
