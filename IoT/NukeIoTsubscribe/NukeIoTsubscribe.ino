#include<ESP8266WiFi.h>
#include"Adafruit_MQTT_Client.h"

#define wifi "NukeAsus"
#define password "244466666"

#define server "io.adafruit.com"
#define port 1883
#define username "NukeSuraj"
#define key "24b0a6021d794bb28ac57e831a071346"
WiFiClient esp;
Adafruit_MQTT_Client mqtt(&esp,server,port,username,key);
Adafruit_MQTT_Subscribe feed = Adafruit_MQTT_Subscribe(&mqtt,username"/feeds/jarvis");

void setup() 
{
 pinMode(16,OUTPUT);
 Serial.begin(115200);
 delay(10);
 Serial.println("Adafruuit Demo");
 Serial.print("connecting TO ");
 Serial.print(wifi);
 WiFi.begin(wifi,password);
 while(WiFi.status()!=WL_CONNECTED)
 {
  delay(100);
  Serial.print(".");
 }
 Serial.println("WiFi connected");
 Serial.println("IP address:");
 Serial.println(WiFi.localIP());

 Serial.println("MQTT connecting");
 while(mqtt.connect())
 {
  delay(500);
  Serial.print(".");
 }
 Serial.print("-");
}

void loop() 
{
 Serial.print(" ");  
 if(mqtt.readSubscription(5000))
 {
  Serial.print("GOT:");
  Serial.print((char*)feed.lastread);
  int a=atoi((char*)feed.lastread);

  Serial.print("");
    Serial.println(a);
  if(a==0)
   digitalWrite(16,LOW);
  else 
   digitalWrite(16,HIGH);
 }
}
