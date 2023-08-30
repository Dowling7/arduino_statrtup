#include "FastLED.h"
void setup() {FastLED.addLeds<NEOPIXEL, 6>(leds, 11);
  // put your setup code here, to run once:

}

void loop() {
  for(int c1=0; c1<=10; c1++){
    for(int c2=0; c2<=10; c2++){
      leds[c2] = CRGB::Black;
    }
    led[c1] = CRGB::Red;
    delay(100);
    FastLED.show();
  }
  // put your main code here, to run repeatedly:

}
