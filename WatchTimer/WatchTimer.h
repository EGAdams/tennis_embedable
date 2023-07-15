#ifndef WatchTimer_H
#define WatchTimer_H
#include "../TennisConstants/TennisConstants.h"
#include "../Inputs/Inputs.h"
#include "../GameTimer/GameTimer.h"

class WatchTimer {
 public:
  WatchTimer();
  ~WatchTimer();

  int watchInputDelay( int delay, Inputs* input, int watchInterval );

};

#endif
