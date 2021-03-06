#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
                             {'1','2','3','A'},
                             {'4','5','6','B'},
                             {'7','8','9','C'},
                             {'*','0','#','D'}
                                              };
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
LiquidCrystal lcd(A0, A1, 13, 12, 11, 10);

void setup() 
{
  lcd.begin(16, 2);
  lcd.print("KeyPad Input: ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
}


void loop()
{
  
  char customKey = customKeypad.getKey();
  
  if (customKey) 
  {
    lcd.print(customKey);
  }
}
