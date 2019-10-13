#include <Arduino.h>
#include <Wire.h>
#include "FooLib.h"

FooClass FooObject;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on
  delay(500);                       // wait for half a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off
  delay(200);                       // wait for half a second
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on
  delay(600);                       // wait for half a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off
  delay(1000);                       // wait for half a second
}
