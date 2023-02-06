#include <neopixel.h>
 
#define PIXEL_COUNT 24             // 24 Pixels on our ring
#define PIXEL_PIN D0              // Ring uses D0 as default pin
#define PIXEL_TYPE WS2812B        // Ring uses WS2812 Pixels
 
Adafruit_NeoPixel pixels(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE); // Create out "ring" object
 
int brightness = 10;
int direction = 0;

int setBrightness(String cmd) {
  if (cmd == "up") {
    direction = 2;
  } else if (cmd == "down") {
    direction = -2;
  } else {
    direction = 0;
  }
  return 1;
}

void setup() {
  pixels.begin();
  pixels.show();
  Particle.function("setBrightness", setBrightness);
}

void loop() {
  if (direction != 0) {
    brightness = brightness + direction;
    if (brightness >= 255) {
      direction = 0;
      brightness = 255;
    }
    if (brightness <= 0) {
      direction = 0;
      brightness = 0;
    }
    pixels.setPixelColor(0, pixels.Color(brightness, brightness, brightness));
    pixels.show();
  }
  delay(0);
}
