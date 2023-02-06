// This #include statement was automatically added by the Particle IDE.
#include <neopixel.h>

#define PIXEL_COUNT 24 // 24 Pixels on our ring
#define PIXEL_PIN D0 // Ring uses D0 as default pin
#define PIXEL_TYPE WS2812B // Ring uses WS2812 Pixels

Adafruit_NeoPixel pixels(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE); // Create out "ring" object

int brightness = 127;

void setup() {
pixels.begin();
pixels.show();
Particle.function("setBrightness", setBrightness);
}

void loop() {
pixels.setPixelColor(0, pixels.Color(brightness, brightness, brightness));
pixels.show();
}

int setBrightness(String args) {
  int newBrightness = args.toInt();
  if (newBrightness > 255) newBrightness = 255;
  if (newBrightness < 0) newBrightness = 0;

  // calculate step size based on difference and number of steps
  int steps = 10;
  int step = (newBrightness - brightness) / steps;
  int delayTime = 2;

  // fade to new brightness value
  for (int i = 0; i < steps; i++) {
    brightness += step;
    pixels.setPixelColor(0, pixels.Color(brightness, brightness, brightness));
    pixels.show();
    delay(delayTime);
  }
  brightness = newBrightness;

  return brightness;
}





