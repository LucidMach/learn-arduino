//Temprature Range:-55˚C +150˚
//Voltage-Celsius Scale Factor:+0.01 V/°C

double temp,thres;
int lm35=A0;
int opVolt=5;
int rele=4;

void setup() 
{
 pinMode(lm35,INPUT);
 pinMode(rele,OUTPUT);
 Serial.begin(9600);
}

void loop()
{
 temp=(opVolt/1024)*analogRead(lm35)*100;     //(analog to volt)*SensorAnalogInput*1/(0.01V/C)
 TempControl();
 Serial.println("Temp:");
 Serial.println(temp);  
}

void TempControl()
{
  if(temp>thres)
   digitalWrite(rele,LOW);
  else
   digitalWrite(rele,HIGH); 
}
