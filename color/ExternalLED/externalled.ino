#include <neopixel.h>
 
#define PIXEL_COUNT 24             // 24 Pixels on our ring
#define PIXEL_PIN D6              // Ring uses D6 as default pin
#define PIXEL_TYPE WS2812B        // Ring uses WS2812 Pixels
 
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE); // Create out "ring" object	
 
void setup() {
  strip.begin();       // Initialize the NeoPixel strip
  strip.show();        // Turn off all the LEDs
  Particle.function("led", toggleLED);  // Register the toggleLED function
}

void loop() {
  // Nothing to do here
}

int toggleLED(String command) {
  if (command == "red") {
    strip.setPixelColor(0, strip.Color(255, 0, 0));  // Set the color to red
    strip.show();                                   // Turn on the LED
    return 1;
  } else if (command == "green") {
    strip.setPixelColor(0, strip.Color(0, 255, 0));  // Set the color to off
    strip.show();                                 // Turn off the LED
    return 1;
  } else if (command == "blue") {
    strip.setPixelColor(0, strip.Color(0, 0, 255));  // Set the color to off
    strip.show();                                 // Turn off the LED
    return 1;
  } else if (command == "off") {
    strip.setPixelColor(0, strip.Color(0, 0, 0));  // Set the color to off
    strip.show();                                 // Turn off the LED
    return 0;
  } else {
    return -1;
  }
}