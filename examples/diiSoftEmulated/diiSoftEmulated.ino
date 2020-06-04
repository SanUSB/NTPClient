#include <Ticker.h>
Ticker ticker;

int LED = 2;
volatile int horas = 13, minutos = 15, segundos = 45;

void tick()
{
  digitalWrite(LED, !digitalRead(LED));     // set pin to the opposite state
  Serial.print("Software emulated clock\n");

  segundos++;

  if(segundos >= 60){
    segundos=0;
    minutos++;
  }
  if(minutos>=60){
    minutos = 0;
    horas++;
  }
  
  if(horas >= 24){
    segundos = 0;
    minutos = 0;
    horas = 0;
  }
  Serial.printf("The time is: %02d:%02d:%02d\n", horas, minutos, segundos); 
   
   if (minutos == 15 && segundos == 55) {
      Serial.println("SanUSB.org Alarm!!!"); 
    }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  ticker.attach(1, tick); //Função tick  um segundo
}

void loop() {    
}
