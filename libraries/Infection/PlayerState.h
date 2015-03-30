#include "Arduino.h"
#include "Network.h"

#ifndef PlayerState_h
#define PlayerState_h

#define NUM_PLAYERS 100

enum State {
	HEALTHY, EXPOSED, INFECTED, CONTAGIOUS
};

class PlayerState
{
  public:
    PlayerState();
    int getMaxBrightness();
    void setMaxBrightness(int brightness);
    void update();
    State getState();

  private: 
    int maxBrightness;
    int exposureCounts[NUM_PLAYERS];
    double exposureStrengths[NUM_PLAYERS];
    boolean isInfected;
    int totalExposureCount;
    State state;
    Network network;
    
    int getExposureCount();
};

#endif
