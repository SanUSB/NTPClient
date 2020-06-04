#include <NTPClient.h> //NTPclient Lib: https://github.com/SanUSB/NTPClient 
#include <WiFiUdp.h>

// Replace with your network credentials
const char *ssid     = "------------";
const char *password = "------------";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");
#define led 2

void setup() {
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
  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT -1 = -3600
  // GMT 0 = 0
  timeClient.setTimeOffset(-3 * 3600);
}

void loop() {
  timeClient.update();

  unsigned long epochTime = timeClient.getEpochTime();
  Serial.print("Epoch Time: ");
  Serial.println(epochTime);
  
  String formattedTime = timeClient.getFormattedTime();
  Serial.print("Formatted Time: ");
  Serial.println(formattedTime);  
  if (formattedTime == "22:29:50")
   {
      Serial.println("Alarm!!!");
   }

  int currentHour = timeClient.getHours();
  Serial.print("Hour: ");
  Serial.println(currentHour);  

  int currentMinute = timeClient.getMinutes();
  Serial.print("Minutes: ");
  Serial.println(currentMinute); 
   
  int currentSecond = timeClient.getSeconds();
  Serial.print("Seconds: ");
  Serial.println(currentSecond);  
//********************************************************************************************
  //Get a time structure
  struct tm *timeinfo = gmtime ((time_t *)&epochTime); 

  int monthDay = timeinfo->tm_mday;
  Serial.print("day: ");
  Serial.println(monthDay);

  int currentMonth = timeinfo->tm_mon+1;
  Serial.print("Month: ");
  Serial.println(currentMonth);

  int currentYear = timeinfo->tm_year+1900;
  Serial.print("Year: ");
  Serial.println(currentYear);

  //Print complete date:
  String currentDate = String(monthDay) + "/" + String(currentMonth) + "/" + String(currentYear);
  Serial.print("Current date: ");
  Serial.println(currentDate);

  Serial.println("");
  digitalWrite(led, !digitalRead(led));
  delay(1000);
}
