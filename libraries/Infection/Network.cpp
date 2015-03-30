#include "Network.h"

Network::Network() {}

void Network::updateExposureData(int numPlayers, int* exposureCounts, double* exposureStrengths)
{	
	/* 
	 * TODO: this needs to be worked out with the xBee's
	 * for now, we'll just increment an exposure count
	 * exposureStrenths will be zeroed at each tick and then updated with RSSI values
	 */

	int numDistinctExposures = 3;
	double exposureStrength = 0.5;
	for (int playerId = 0; playerId < numDistinctExposures; playerId++) {
		exposureCounts[playerId] = 1;
		exposureStrengths[playerId] = 0.5;
	}
}