#define LED_PIN 3
#define IR_DIST_SENS A0
//определение количества измерений,
//по которым будет произвоидиться усреднение
#define MA 10

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int distance = measure(IR_DIST_SENS);
  Serial.println(distance);
  analogWrite(LED_PIN, map(distance, 0, 1023, 0, 255));
}
//функция, содержащая код для измерения и усреднения
//возвращает целое число (int), принимает номер пина,
//к которому подключен датчик
int measure(int pin)
{
  //создание массива с количеством элементов,
  //равным прописанному количеству измерений;
  //благодаря static, записанные в массив значения
  //сохранятся между вызовами функции
  static int measurements[MA];
  
  //цикл пройдет до предпоследнего элемента массива:
  //MA-1 - номер последнего элемента
  //за счет < счетчик остановится на значении перед 
  //номером последнего элемента
  for (int i = 0; i < MA - 1; i++)
  {
    //запись значения n+1 элемента массива в n-ный
    measurements[i] = measurements[i + 1];
  }
  //запись текущего измерения в последний элемент массива
  measurements[MA - 1] = analogRead(pin);

  //создание локальной переменной для хранения
  //суммы измерений, а затем и среднего значения
  //тип long позволит хранить значения от -2 147 483 648 до 2 147 483 647
  //т.к. int (значения от -32 768 до 32 767) может переполниться при большом количестве измерений 
  long mean = 0;
  //на этот раз цикл идет до последнего элемента массива
  for (int i = 0; i < MA; i++)
  {
    //на каждом проходе к mean
    //прибавляется следующий элемент
    mean += measurements[i];
  }
  //функция вернет значение,
  //равное полученной сумме, деленной на количество измерений
  return mean /= MA;
}
