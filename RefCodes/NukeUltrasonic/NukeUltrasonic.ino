int duration;

void setup() 
{
Serial.begin(9600);
pinMode(4, OUTPUT);//trigger
pinMode(2, INPUT);//echo
}

void loop() 
{
  Ultra(s1);
}

void Ultra(int s)
{
 digitalWrite(4, LOW);
 delayMicroseconds(2);
 digitalWrite(4, HIGH);
 delayMicroseconds(10);
 digitalWrite(4, LOW);
 duration = pulseIn(2, HIGH);
 s=duration*0.034/2;
 Serial.println(s);
}
