/*
  Controlling a servo position using a potentiometer using an ATTiny13
  Uses MicroCore: https://github.com/MCUdude/MicroCore

*/
#define F_CPU 9600000
#include <avr/io.h>
#define PIN_KNOB A1 // Pin A2 is actually pin Pin 3 on the DIP Chip
#define PIN_SERVO 0 // Pin 2 is actually pin 7 on the DIP chip
// VCC pin is 8, GND Pin is 4


#define SERVOMAX 180
#define SERVOMIN 0
#define PULSEPERIOD 50 // Pulse period in MS

#define PULSE_MIN_POS 350 // Time for "minimum position" in microseconds
#define PULSE_MAX_POS 2500 // Time for "max position" in microseconds
#define PULSE_NEUTRAL_POS 1500 // Time for "neutral position" in microseconds

int val;    // variable to read the value from the analog pin

void setup() {
  pinMode(PIN_SERVO, OUTPUT);
}

void loop() {
  val = analogRead(PIN_KNOB);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, PULSE_MIN_POS, PULSE_MAX_POS);     // scale the time directly to the pulse length
  digitalWrite(PIN_SERVO, HIGH);
  delayMicroseconds(val);
  digitalWrite(PIN_SERVO, LOW);
  delay(PULSEPERIOD);                           // waits for the servo to get there
}
