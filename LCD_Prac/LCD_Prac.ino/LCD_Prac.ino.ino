#include <Adafruit_RGBLCDShield.h>

#include <LiquidCrystal.h>


LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int KEY_IN;



int readButtons()
{
   KEY_IN = analogRead(0);
   Serial.print("Value:");
   Serial.println(KEY_IN);
   //lcd.print(KEY_IN);
   
  }
  
  void Command()
  {
  
    if (KEY_IN > 1000) 
    {
      //Nothing
      }
      else if (KEY_IN >= 740 && KEY_IN <= 745)
      {
        //The Select Button
        }
        else if (KEY_IN >= 500 && KEY_IN <= 510)
        {
          //The Left Button
          }
          else if (KEY_IN >= 325 && KEY_IN <= 335)
          {
            //The Down Button
            }
            else if (KEY_IN >= 140 && KEY_IN <= 150)
            {
              //The Up Button
              }
              else if (KEY_IN < 1)
              {
                //The Right Button
                }
    }
    
 
      
void setup() 
{
Serial.begin(9600);

lcd.begin(16, 2); 
lcd.clear();
lcd.home();
lcd.print("We currently have $6,901.36");

}

void loop() {
readButtons();
lcd.scrollDisplayLeft();
delay(300);

//Command();

  
  }

