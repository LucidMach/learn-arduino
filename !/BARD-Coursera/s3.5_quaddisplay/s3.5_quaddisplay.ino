//библиотеку можно найти через сайт производителя: https://github.com/amperka/QuadDisplay
#include <QuadDisplay.h>

#define ECHO_PIN 8
#define TRIG_PIN 7
//дисплей будет управляться через единственный пин
#define DISPLAY_PIN 2

void setup() {
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  Serial.begin(9600);
  
  pinMode(DISPLAY_PIN, OUTPUT);
}

void loop() {
  //библиотечная функция displayInt() для вывода целого числа
  //найдите другие функции, которые дает библиотека QuadDisplay
  displayInt(DISPLAY_PIN, measure());
}

int measure()
{
  digitalWrite(TRIG_PIN, HIGH);
  digitalWrite(TRIG_PIN, LOW);
  int distance = pulseIn(ECHO_PIN, HIGH, 15000) / 50;

  return constrain(distance, 1, 300);
}
  
