#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
int count = 10;
char PassTest[] ={'1','2','3','4','5','6'};
char dao = '*';
char tempPass[6];
 
const byte ROWS = 4; // four rows
const byte COLS = 4;  //four Column
char keys[ROWS][COLS] = {
                        {'1','2','3','A'},
                        {'4','5','6','B'},
                        {'7','8','9','C'},  
                        {'*','0','#','D'},
};
byte rowPins[ROWS] = {30,31,32,33};
byte colPins[COLS] = {34,35,36,37};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS,COLS );
LiquidCrystal_I2C lcd(0x27,16,2);// set the LCD address to 0x27 for a 16*2 lines display
                                 // set the LCD address to 0x3F for a 20*4 lines display

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  Serial.begin(9600);
  lcd.setCursor(1,0); // set cursor to use at 0 row start from 1
  lcd.print("Hello Zad&kao!");
}
void loop() {
  // put your main code here, to run repeatedly:
  int i = 0;
  char key = keypad.getKey();
  if (key != NO_KEY)
  {
    Serial.print(key);
    if(count <16){
      //getArrPassTemp();
       lcd.setCursor(count,1);  
       lcd.print(dao); 
       tempPass[count-10] = key;
       count++;
    }else{ 
           Serial.println();
           for(int b=0;b<6;b++){
              Serial.print(tempPass[b]);
           }
           Serial.println();
           lcd.setCursor(0,1);
           lcd.print("                    ");
           count=10;
      }
    } 
}


void clearScreen(){
  lcd.setCursor(0,0);
  lcd.print("                 ");
  lcd.setCursor(0,1);
  lcd.print("                ");  
}
