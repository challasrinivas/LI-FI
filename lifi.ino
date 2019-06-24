//lifi project
#include <SoftwareSerial.h>
#include <String.h>
#include <LiquidCrystal.h>

SoftwareSerial lifi(3, 4); // RX, TX
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

String s1 = "fon";
String s2 = "fof";
String s3 = "on";
String s4 = "off";
String s5 = "von";
String s6 = "vof";

int fan=7;
int bulb=6;
int motor=5;

String lifidata;
int count = 0;
char singleChar;
String readMsg;



void setup() {
  Serial.begin(9600);
//  lifi.begin(9600);
  lcd.begin(16, 2);                                               
  lcd.clear();                               
  pinMode(fan,OUTPUT);
  pinMode(bulb,OUTPUT);
  pinMode(motor,OUTPUT);
  
  lcd.setCursor(0, 0);                                            
  lcd.print("WELCOME TO THE");    
  lcd.setCursor(0, 1);
  lcd.print("  LIFI BASED   ");    
  Serial.println("WELCOME TO THE LIFI BASED");
  delay(2000);
  lcd.clear();                            
  lcd.setCursor(0, 0);                                            
  lcd.print("HOME AUTOMATION ");    
  Serial.println("HOME AUTOMATION");
  delay(2000);
  lcd.clear();
  lcd.print("----WAITING---");
  Serial.println("---WAITING---");
  digitalWrite(fan,LOW);
  digitalWrite(bulb,LOW);
  digitalWrite(motor,LOW); 


}

void loop() {
    if (Serial.available() > 0)
  {
    singleChar = Serial.read();
  //Serial.print(F("SINGLE CHAR:")); Serial.println(singleChar);
    count++;
    readMsg += singleChar;
    if (count == 3)
    {
        Serial.print(F("RECV DATA:")); Serial.println(readMsg);
        lcd.setCursor(2, 0);
        lcd.print(readMsg);delay(2000);
      if (readMsg == s1) {
        Serial.println(F("FAN TURNED ON"));
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("FAN TURNED ON");
        delay(1000);
        count = 0;
        readMsg = "";
        lcd.clear();                                
        digitalWrite(fan,HIGH);
      }
      else if (readMsg == s2) {
        Serial.println(F("FAN TURNED OFF"));
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("FAN TURNED OFF");
        delay(1000);
        count = 0;
        readMsg = "";
        lcd.clear();                                
        digitalWrite(fan,LOW);

      }
      else if (readMsg == s3) {
        Serial.println(F("BULB TURNED ON"));
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("BULB TURNED ON");
        delay(1000);
        count = 0;
        readMsg = "";
        lcd.clear();                              
        digitalWrite(bulb,HIGH);
      }
       else if (readMsg == s4) {
        Serial.println(F("BULB TURNED OFF"));
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("BULB TURNED OFF");
        delay(1000);
        count = 0;
        readMsg = "";
        lcd.clear();                                
        digitalWrite(bulb,LOW);
      }
       else if (readMsg == s5) {
        Serial.println(F("MOTOR TURNED ON"));
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("MOTOR TURNED ON");
        delay(1000);
        count = 0;
        readMsg = "";
        lcd.clear();                               
        digitalWrite(motor,HIGH);
      }
       else if (readMsg == s6) {
        Serial.println(F("MOTOR TURNED OFF"));
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("MOTOR TURNED OFF");
        delay(1000);
        count = 0;
        readMsg = "";
        lcd.clear();                              
        digitalWrite(motor,LOW);
      }
      else {
        Serial.println(F("INVALID DATA DETECTED"));
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("INVALID DATA");
        delay(1000);
        count = 0;
        readMsg = "";
        lcd.clear(); // clear LCD display                               
        lcd.setCursor(0, 0);                                            
         lcd.print("--WAITING--");    
      }

    }
  }

}
