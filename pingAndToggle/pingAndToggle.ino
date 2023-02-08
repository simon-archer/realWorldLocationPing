#include <neopixel.h>
 
#define PIXEL_COUNT 24             // 24 Pixels on our ring
#define PIXEL_PIN D0              // Ring uses D0 as default pin
#define PIXEL_TYPE WS2812B        // Ring uses WS2812 Pixels
 
Adafruit_NeoPixel pixels(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE); // Create out "ring" object
 
int brightness = 10;
int direction = 0;

int setBrightness(String cmd) {
  if (cmd == "up") {
    direction = 4;
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
  Particle.function("led", toggleLED);
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

int toggleLED(String command) {
  if (command == "pink") {
    pixels.setPixelColor(0, pixels.Color(255, 50, 50));  // Set the color to red
    pixels.show();                                   // Turn on the LED
    return 1;
  } else if (command == "green") {
    pixels.setPixelColor(0, pixels.Color(0, 255, 50));  // Set the color to off
    pixels.show();                                 // Turn off the LED
    return 1;
  } else if (command == "blue") {
    pixels.setPixelColor(0, pixels.Color(0, 50, 255));  // Set the color to off
    pixels.show();                                 // Turn off the LED
    return 1;
  } else if (command == "white") {
    pixels.setPixelColor(0, pixels.Color(255, 255, 255));  // Set the color to off
    pixels.show();                                 // Turn off the LED
    return 0;
  } else if (command == "off") {
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));  // Set the color to off
    pixels.show();                                 // Turn off the LED
    return 0;
  } else {
    return -1;
  }
}
