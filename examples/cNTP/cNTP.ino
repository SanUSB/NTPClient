#include <NTPClient.h>
#include <time.h>

int LED = 2;

const char* ssid = "----------";
const char* password = "-----------";
int timezone = -3;
int dst = 0;

void setup() {
  Serial.begin(115200);
  pinMode(2,OUTPUT);
  digitalWrite(LED, LOW);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("\nConnecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
    
  configTime(timezone * 3600, dst * 0, "pool.ntp.org", "time.nist.gov");
  while (!time(nullptr)) {
  Serial.print(".");
  delay(1000);
  }
}

void loop() {
    time_t now;
    struct tm * timeinfo;
    time(&now);
    timeinfo = gmtime(&now); 
    //timeinfo = localtime(&now);

    Serial.printf("The time is: %02d:%02d:%02d\n", timeinfo->tm_hour, 
           timeinfo->tm_min, timeinfo->tm_sec); 
    //  , timeinfo->tm_mday, timeinfo->tm_mon+1, timeinfo->tm_year-100);
     
    //Serial.println(ctime(&now));
    delay(1000);
    digitalWrite(LED, !digitalRead(LED)); 
}
