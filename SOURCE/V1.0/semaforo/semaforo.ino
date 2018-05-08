/*

*/
#include <Adafruit_NeoPixel.h>



#define BUT_GREEN 12
#define BUT_YELLOW 11
#define BUT_RED 10

#define LED_GREEN 7
#define LED_YELLOW 6
#define LED_RED 5

#define PIN_NEO 2
#define NUMPIXELS 24

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN_NEO, NEO_GRB + NEO_KHZ800);


int BRIGHTNESS = 240;
int MAX_INT = 250;
int delayval = 0;
void setup() {
 
  strip.begin();
  strip.setBrightness(BRIGHTNESS); //adjust brightness here
  strip.show(); // Initialize all pixels to 'off'
  
  pinMode(BUT_GREEN, INPUT_PULLUP);
  pinMode(BUT_YELLOW, INPUT_PULLUP);
  pinMode(BUT_RED, INPUT_PULLUP);

  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  set_GREEN();
  delay(1000);
  set_YELLOW();
  delay(1000);
  set_RED();
  delay(1000);

  set_NONE();
}

void loop() {

  if (!digitalRead(BUT_GREEN)) {
  set_GREEN();
  }
  if (!digitalRead(BUT_YELLOW)) {
  set_YELLOW();
  }
  if (!digitalRead(BUT_RED)) {
  set_RED();
  }


  //set_NONE();
}

void set_GREEN (){
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
  abanico_NEO (0, 255, 0);
}

void set_YELLOW (){
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, HIGH);
  digitalWrite(LED_RED, LOW); 
  abanico_NEO (255, 255, 0);
}


void set_RED (){
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, HIGH);
  abanico_NEO (255, 0, 0);
}

void set_NONE (){
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
  abanico_NEO (0, 0, 0);
}

void abanico_NEO(int R, int G, int B){
    for (int i = 0; i < NUMPIXELS; i++) {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    strip.setPixelColor(i, strip.Color(R, G, 0)); // Moderately bright greeson color.

    strip.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
}

