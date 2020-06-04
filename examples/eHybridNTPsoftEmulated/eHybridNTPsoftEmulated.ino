#include <Ticker.h>
#include <NTPClient.h> //NTPclient Lib: https://github.com/SanUSB/NTPClient 
#include <WiFiUdp.h>

const char *ssid     = "------------";
const char *password = "------------";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

Ticker ticker;


int LED = 2;
int horas = 13, minutos = 15, segundos = 45;

void tick()
{
  digitalWrite(LED, !digitalRead(LED));     // set pin to the opposite state
  //Serial.print("Software emulated clock\n");

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
  
  if (segundos == 0) { //Para compara o relógio emulado com o NTP
  Serial.printf("NTP time is: %02d:%02d:%02d\n", timeClient.getHours(), timeClient.getMinutes(), timeClient.getSeconds());
    }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, 1);
   
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  timeClient.begin();
  timeClient.setTimeOffset(-3 * 3600);

  timeClient.update();

  horas = timeClient.getHours();
  Serial.print("Horas: ");
  Serial.println(horas);  

  minutos = timeClient.getMinutes();
  Serial.print("Minutos: ");
  Serial.println(minutos); 
   
  segundos = timeClient.getSeconds();
  Serial.print("Segundos: ");
  Serial.println(segundos); 
     
  //************O processo seguinte é offline*************************************   
  ticker.attach(1, tick); //Função tick  um segundo
}

void loop() {    
}
