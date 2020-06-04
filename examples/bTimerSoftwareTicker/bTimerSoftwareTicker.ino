// Software timer interrupt

#include <Ticker.h>
Ticker ticker;

int LED = 2; // ESP32 and ESP8266

void tick()
{
  //toggle state
  digitalWrite(LED, !digitalRead(LED));     // set pin to the opposite state
  Serial.print("Timer ticker Interrupt\n");
}

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  ticker.attach(1, tick);
  
}

void loop() {
}
