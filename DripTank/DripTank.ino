
int Time1, dist ;
int t=4,e=2;
void setup() 
{
  pinMode(t, OUTPUT);
  pinMode(e, INPUT);
  Serial.begin(9600);
  
}

void loop()
{
 int l =  Ultra(); 
  delay(1000);
  if((l >= 18) && (l <20))
  Serial.println("Slow mode");
  
  else if((l >= 20) &&(l < 22))
  Serial.println("Medium mode");
  
  else if((l >= 22) && (l <=24))
  Serial.println("fast mode");
    else 
   Serial.println("stop flow");
 

}
int Ultra()
{int s;
 digitalWrite(t, LOW);
 delayMicroseconds(2);
 digitalWrite(t, HIGH);
 delayMicroseconds(10);
 digitalWrite(t, LOW);
int duration = pulseIn(e, HIGH);
 s=duration*0.034/2;
 Serial.println(s);
 return(s);
 
}
