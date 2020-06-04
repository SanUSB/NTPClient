#include <Ticker.h>
//Biblioteca esp8266 que chama funções de interrupção periodicamente por software

Ticker TickSegundo;

volatile int watchdogCount = 0;

void ISRwatchdog() {
  watchdogCount++;
  Serial.println("interrompeu!");
  if ( watchdogCount == 10 ) {
      Serial.println("O cachorro mordeu!");
     ESP.reset();
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting");
  TickSegundo.attach(1, ISRwatchdog);
}

void loop() {
  Serial.print("Watchdog counter = ");
  Serial.println(watchdogCount);
  //watchdogCount = 0; //Se zerar o watchdogCount no loop nunca vai resetar pelo watchdog
  delay(1000);
}
