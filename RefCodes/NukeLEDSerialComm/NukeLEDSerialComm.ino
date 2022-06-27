int c=0;
void setup() 
{
 pinMode(16,OUTPUT);
 Serial.begin(115200);
}

void loop() 
{
  
Serial.println("LED State:(0/1)");
c=Serial.read();
if(c==1)
 digitalWrite(16,LOW);
else
 digitalWrite(16,HIGH); 
}
