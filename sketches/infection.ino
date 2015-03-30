#include <Network.h>
#include <PlayerState.h>
#include <Adafruit_NeoPixel.h>

#define PIN 1
#define PIXEL_COUNT 16

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIN, NEO_GRB + NEO_KHZ800);
PlayerState* playerState;

void setup() {
  playerState = new PlayerState();
  strip.setBrightness(10);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
//  playerState.setMaxBrightness(10);

}

void loop() {
  colorWipe(strip.Color(0, 0, 255), 50);
  playerState->update();
  State state = playerState->getState();
  if (state == HEALTHY) {
     colorWipe(strip.Color(0, 255, 0), 50);
  } else if (state == EXPOSED) {
     colorWipe(strip.Color(255, 255, 0), 50);
  } else if (state == CONTAGIOUS) {
     colorWipe(strip.Color(255, 0, 0), 50);
  }
}

