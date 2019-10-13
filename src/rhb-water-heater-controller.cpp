#include "WProgram.h"
#include <math.h>

const int CIRCUIT_1 = 13;
const long FIFTEEN_MINUTES = 60000 * 15;
const long FIFTEEN_MINUTES_PLUS_10 = FIFTEEN_MINUTES + 10000;

long runningTime = 0;
long cycleStart = 0;

void setup() {
  pinMode(CIRCUIT_1, OUTPUT);
  digitalWrite(CIRCUIT_1, LOW);
  runningTime = millis();
  cycleStart = millis();
} 

void loop() {

  runningTime = millis();
  if (runningTime - cycleStart < FIFTEEN_MINUTES) {
    digitalWrite(CIRCUIT_1, HIGH);
  } else if (runningTime - cycleStart < FIFTEEN_MINUTES_PLUS_10) {
    digitalWrite(CIRCUIT_1, LOW);
  } else {
    cycleStart = millis();
  }
}
