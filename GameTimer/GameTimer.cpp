#include "GameTimer.h"

GameTimer::GameTimer() {}
GameTimer::~GameTimer(){}

void GameTimer::gameDelay( int milliseconds ) { std::this_thread::sleep_for( std::chrono::milliseconds( milliseconds )); }

void GameTimer::sleep_until( int milliseconds ) {}

unsigned long GameTimer::gameMillis() {
    std::chrono::milliseconds ms =
    std::chrono::duration_cast<std::chrono::milliseconds>(
    std::chrono::system_clock::now().time_since_epoch());
    return ms.count(); }