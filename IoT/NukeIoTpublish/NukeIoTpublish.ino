#include<ESP8266WiFi.h>

#include"Adafruit_MQTT_Client.h"

#define Ain A0

#define wifi "NukeAsus"
#define password "244466666"

#define server "io.adafruit.com"
#define port 1883
#define username "NukeSuraj"
#define key "24b0a6021d794bb28ac57e831a071346"
WiFiClient esp;
Adafruit_MQTT_Client mqtt(&esp,server,port,username,key);
Adafruit_MQTT_Publish feed=Adafruit_MQTT_Publish(&mqtt,username"/feeds/pm");  //Change Feed

void setup() 
{
 Serial.begin(9600);
 delay(10);
 Serial.println("Adafruuit");
 Serial.print("connecting TO ");
 Serial.print(wifi);
 WiFi.begin(wifi,password);
 while(WiFi.status()!=WL_CONNECTED)
 {
  delay(100);
  Serial.print(".");
 }
 Serial.println("WiFi connected");
 Serial.println("IP address: ");
 Serial.println(WiFi.localIP());

 Serial.println("MQTT connecting");
 while(mqtt.connect())
 {
  Serial.print(".");
 }
}

void loop() 
{
 if(mqtt.connected())
 {
  int data=analogRead(Ain);
  Serial.print("\nSending Sensor value ");
  Serial.print(data,DEC);
  Serial.print("...");
  if(feed.publish(data))
     Serial.println("Success :)");
  else   
     Serial.println("Fail :("); 
  delay(2200);
 }
}
