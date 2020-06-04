#include <Ticker.h>
//Biblioteca esp8266 e esp32 que chama funções de interrupção periodicamente por software

Ticker tickerNivelAlto;
Ticker tickerNivelBaixo;

void setPin(int state) { //Função setPin
  digitalWrite(2, state);
  Serial.print("Interrupcao ticker: ");
  Serial.println(state);
}

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);

  // ticker.attach(tempo, função de interrupção, parâmetro da função);
  tickerNivelBaixo.attach_ms(700, setPin, 0);

  // a cada 1500 ms, chama setPin(1)
  tickerNivelAlto.attach_ms(1500, setPin, 1);
}

void loop() {}
