
#include <FastLED.h>

#define NUM_LEDS 25

#define DATA_PIN 7
const int actionButton = 4;
int ButtonState1 = 0;
int presscount = 1;

// The debounce time in milliseconds
const int debounceTime = 250;

// Variables to track the last time the button was pressed and the current time
unsigned long lastPressTime = 0;
unsigned long currentTime = 0;

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  pinMode(actionButton, INPUT_PULLUP);
  pinMode(DATA_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Read the state of the button
  ButtonState1 = digitalRead(actionButton);

  // Get the current time
  currentTime = millis();

  // If the button is pressed and enough time has passed since the last press
  if (ButtonState1 == LOW && currentTime - lastPressTime >= debounceTime) {
    // Increment the presscount variable
  
    presscount++;

    // Update the lastPressTime variable with the current time
    lastPressTime = currentTime;
  }

  // Check if the presscount variable is even or odd
  if (presscount % 2 == 0) {
    // If it's even, set all the LEDs to orange
    FastLED.clear();
    fill_solid(leds, NUM_LEDS, CRGB(255, 50, 0));
    FastLED.show();
  } else {
    // If it's odd, set all the LEDs to blue
    FastLED.clear();
    fill_solid(leds, NUM_LEDS, CRGB(0, 0, 255));
    FastLED.show();
  }

 
}
