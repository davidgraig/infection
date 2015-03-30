#include "Arduino.h"
#include "PlayerState.h"

PlayerState::PlayerState() 
{
	//network = Network();
}

void PlayerState::update()
{
	if (state != INFECTED && state != CONTAGIOUS) {
		network.updateExposureData(NUM_PLAYERS, exposureCounts, exposureStrengths);
		/*
		 * TODO: Based on the updated exposure map, we should update the exposure count
		 * and determine if the player is infected
		 * we should also determine if the player is contagious 
		 * (i.e. after n minutes of being infected?)
		 */
		 
		 state = HEALTHY;
	}
	
}

int PlayerState::getExposureCount()
{
	int exposureCount = 0;
	for (int playerId = 0; playerId < NUM_PLAYERS; playerId++) {
		exposureCount += exposureCounts[playerId];
	}
	return exposureCount;
}

State PlayerState::getState()
{
	return state;
}

int PlayerState::getMaxBrightness()
{
	return maxBrightness;
}

void PlayerState::setMaxBrightness(int brightness)
{
	if (brightness <= 255 || brightness >= 0) {
		maxBrightness = brightness;	
	} else if (brightness > 255) {
		maxBrightness = 255;
	} else if (brightness < 0) {
		maxBrightness = 0;
	}
}