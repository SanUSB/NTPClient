#include <NTPClient.h> //NTPclient Lib: https://github.com/SanUSB/NTPClient 
#include <WiFiUdp.h>
#include <time.h>
#include <sys/time.h>
struct tm data;//Cria a estrutura que contem as informacoes da data.
/*
Unix time é a contagem de segundos desde 01/01/1970. 
*/

// Replace with your network credentials
const char *ssid     = "-----------";
const char *password = "------------";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");
#define led 2
String hora_rtc;

void setup()
{
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  digitalWrite(led, 1);
   
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

// Initialize a NTPClient to get time
  timeClient.begin();
  timeClient.forceUpdate();        // Atualização 
  timeClient.setTimeOffset(-3 * 3600);
  delay(1000);
  timeClient.update();  

  unsigned long epochTime = timeClient.getEpochTime();
  Serial.print("Unix Time: ");
  Serial.println(epochTime);
  
//************O processo abaixo é offline*************************************      
  timeval tv;//Cria a estrutura temporaria para funcao abaixo.
  //tv.tv_sec = 1591140533;//Atribui data atual manual
  tv.tv_sec = timeClient.getEpochTime();
  settimeofday(&tv, NULL);//Configura o RTC para manter a data atribuida atualizada.
}

void loop()
{
    time_t tt = time(NULL);//Obtem o tempo atual em segundos. Utilize isso sempre que precisar obter o tempo atual
    data = *gmtime(&tt);//Converte o tempo atual e atribui na estrutura    
    char data_formatada[64];
    strftime(data_formatada, 64, "%d/%m/%Y %H:%M:%S", &data);//Cria uma String formatada da estrutura "data"
    printf("\nUnix Time: %d\n", int32_t(tt));//Mostra na Serial o Unix time
    printf("Data formatada: %s\n", data_formatada);//Mostra na Serial a data formatada
    delay(1000);
    
    tt = time(NULL);//Obtem o tempo atual em segundos. Utilize isso sempre que precisar obter o tempo atual
    data = *gmtime(&tt);//Converte o tempo atual e atribui na estrutura    
    data_formatada[64];
    strftime(data_formatada, 64, "%H:%M", &data);//Cria uma String formatada da estrutura "data"
    printf("\nUnix Time: %d\n", int32_t(tt));//Mostra na Serial o Unix time
    printf("Hora formatada: %s\n", data_formatada);//Mostra na Serial a data formatada
    hora_rtc = data_formatada;
    
    if (hora_rtc == "13:53") {
      Serial.println("SanUSB.org Alarm!!!"); 
    }
    delay(1000);
    digitalWrite(led, !digitalRead(led)); 
}
