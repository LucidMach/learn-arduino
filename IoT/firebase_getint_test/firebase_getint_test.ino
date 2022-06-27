#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

FirebaseData led_data;

#define project "ldrmonitoring.firebaseio.com"
#define secret "yFvxUmo7jJtMmiKOo2kOk2uPnBMn6KxPjHcdsCbm"

#define ssid "Lema Labs"
#define password "do_not_settle"

void setup()
{
  Serial.begin(115200);
  pinMode(16,OUTPUT);
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }

  Firebase.begin(project,secret);
  Serial.println("Firebase Connected");
}

void loop(){
  int value;
  Firebase.getInt(led_data,"/LED",value);

  if (value==0)
  digitalWrite(16,HIGH);
  else
  digitalWrite(16,LOW);
}
