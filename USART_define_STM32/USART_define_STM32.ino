
#include <HardwareSerial.h>

// Variables:
int previousMillis = 0;        // will store the last time the LED was updated
int interval = 500;            // interval at which to blink (in milliseconds)
uint32_t counter = 0;

//                      RX    TX
HardwareSerial Serial2(PA3, PA2);


void setup() {
  // Set up the built-in LED pin as output:
  pinMode(PC13, OUTPUT);

  Serial2.begin(19200);
}

void loop() {
  // Check to see if it's time to blink the LED; that is, if the
  // difference between the current time and last time we blinked
  // the LED is bigger than the interval at which we want to blink
  // the LED.
  if (millis() - previousMillis > interval) {
    // Save the last time you blinked the LED
    previousMillis = millis();

   
    Serial2.print("Counter: ");
    Serial2.print(counter);
    Serial2.println(" - Hello UART 2!");

    
    counter ++;
    // If the LED is off, turn it on, and vice-versa:
    digitalWrite(PC13,!digitalRead(PC13));
    }
}
