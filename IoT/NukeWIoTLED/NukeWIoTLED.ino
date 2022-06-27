#include<ESP8266WebServer.h>
ESP8266WebServer servy;
const char username[]="ApexionWiFi";
const char password[]="jaihind7";
int p=16;
void setup() 
{
 pinMode(p,OUTPUT);
 Serial.begin(115200);
 WiFi.softAP(username,password);
 IPAddress ip=WiFi.softAPIP();
 Serial.print("AP IP:");
 Serial.println(ip);
 servy.begin();
 servy.on("/led",led);
}

void loop() 
{
 servy.handleClient();
}

void led()
{
 String mthl="<html><head><title>Apexions</title></head><body style=\"background-color:yellow\"><h1><center>IoT</center></h1><form><center><button type=\"submit\" name=\"state\" value=\"0\" style=\"background-color:green\">LED ON</button><button type=\"submit\" name=\"state\" value=\"1\" style=\"background-color:red\">LED OFF</button></center></form></body></html>";
 servy.send(200,"text/html",mthl);
 if(servy.arg("state")=="0")
    digitalWrite(p,LOW);
 else
    digitalWrite(p,HIGH);    
}
