int ir;
int a=0;
int cnt=0;

void setup() 
{
 pinMode(8, INPUT);
 pinMode(3, OUTPUT);
 pinMode(5, OUTPUT);
 Serial.begin(9600);
 
}
void loop() 
{
 ir=digitalRead(8);
 digitalWrite(5,HIGH);
 digitalWrite(3,LOW);
 if(ir==HIGH && a==0)
   {
    cnt++;
    a=7;
   }
 if(ir==LOW && a==7)
     a=0;
 Serial.println(cnt);
}

 void count()
 {
  cnt++;
 }

