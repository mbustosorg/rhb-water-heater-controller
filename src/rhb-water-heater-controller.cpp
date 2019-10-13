#include "WProgram.h"
#include <math.h>

const int CIRCUIT_1 = 0;
const long FIFTEEN_MINUTES = 60000 * 15;
const long FIFTEEN_MINUTES_PLUS_10 = FIFTEEN_MINUTES + 10000;

long runningTime = 0;
long cycleStart = 0;

void setup() {
  pinMode(CIRCUIT_1_PWM, OUTPUT);
  digitalWrite(CIRCUIT_1_PWM, LOW);
  runningTime = millis();
  cycleStart = millis();
} 

void loop() {

  runningTime = millis();
  if (runningTime - cycleStart < FIFTEEN_MINUTES) {
    digitalWrite(CIRCUIT_1_PWM, HIGH);
  } else if (runningTime - cycleStart < FIFTEEN_MINUTES_PLUS_10) {
    digitalWrite(CIRCUIT_1_PWM, LOW);
  } else {
    cycleStart = millis();
  }
}
