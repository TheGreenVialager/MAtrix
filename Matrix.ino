// Adafruit_NeoMatrix example for single NeoPixel Shield.
// Scrolls 'Howdy' across the matrix in a portrait (vertical) orientation.

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define PIN 6
String nbrltr = String("Quel est le bruit d'un oiseau qui survolle un camp de comcentration ?                     Cuit Cuit");
int temps = -nbrltr.length()*6;


Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(255, 255, 255), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(30);
  matrix.setTextColor(colors[0]);
Serial.begin(9600);


}

  
int x    = matrix.width();
int pass = 0;

void loop() {
 
 Serial.println(temps);
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print((nbrltr));
  if(--x < temps) {
    x = matrix.width();
    if(++pass >= 3) pass = 0;
    matrix.setTextColor(colors[pass]);
  }
  matrix.show();
  delay(105);



}
