#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16 ,2);



String str;
String myinfo = "20172256 YHS";
const int LEDPIN=13;
const int LEDPIN_ =12;
const int APIN2 = 2;
const int APIN3 = 3;
const int APIN4 = 4;
const int APIN5 = 5;
const int APIN6 = 6;
const int APIN7 = 7;
const int APIN8 = 8;



void setup() {
  Serial.begin(115200);
  pinMode(LEDPIN,OUTPUT);
  pinMode(LEDPIN_, OUTPUT);
  
  

  pinMode(APIN2, OUTPUT);
  pinMode(APIN3, OUTPUT);
  pinMode(APIN4, OUTPUT);
  pinMode(APIN5, OUTPUT);
  pinMode(APIN6, OUTPUT);
  pinMode(APIN7, OUTPUT);
  pinMode(APIN8, OUTPUT);


  lcd.init();
  lcd.backlight();
}

void loop() {
  str="";
  static unsigned int col =0;
  
  int isFirstRead =0;
 while(Serial.available()) {
  char temp = Serial.read();

    if(temp=='1' && isFirstRead ==0 ) {

      isFirstRead = 1;
      continue;
    }
    else if(temp=='2' && isFirstRead==0 ) {

      isFirstRead=2;
      continue;
    }
    

    if(isFirstRead ==1) {

    int temp_ =temp - '0';
     digitalWrite(LEDPIN,HIGH);
     delay(1000);

    if(temp_ == 0) {
       digitalWrite(APIN2,HIGH);
       digitalWrite(APIN3,HIGH);
        digitalWrite(APIN4,HIGH);
        digitalWrite(APIN5,LOW); 
       digitalWrite(APIN6,HIGH);
       digitalWrite(APIN7,HIGH);
        digitalWrite(APIN8,HIGH);
    }
     if(temp_ == 1) {
      digitalWrite(APIN2,LOW);
       digitalWrite(APIN3,HIGH);
        digitalWrite(APIN4,HIGH);
        digitalWrite(APIN5,LOW); 
       digitalWrite(APIN6,LOW);
       digitalWrite(APIN7,LOW);
        digitalWrite(APIN8,LOW);
    }
     if(temp_ == 2) {
       digitalWrite(APIN2,HIGH);
       digitalWrite(APIN3,HIGH);
        digitalWrite(APIN4,LOW);
        digitalWrite(APIN5,HIGH); 
       digitalWrite(APIN6,LOW);
       digitalWrite(APIN7,HIGH);
        digitalWrite(APIN8,HIGH);
    }
     if(temp_ == 3) {
       digitalWrite(APIN2,LOW);
       digitalWrite(APIN3,HIGH);
        digitalWrite(APIN4,HIGH);
        digitalWrite(APIN5,HIGH); 
       digitalWrite(APIN6,LOW);
       digitalWrite(APIN7,HIGH);
        digitalWrite(APIN8,HIGH);
    }
     if(temp_ == 4) {
       digitalWrite(APIN2,LOW);
       digitalWrite(APIN3,HIGH);
        digitalWrite(APIN4,HIGH);
        digitalWrite(APIN5,HIGH); 
       digitalWrite(APIN6,HIGH);
       digitalWrite(APIN7,LOW);
        digitalWrite(APIN8,LOW);
    }
     if(temp_ == 5) {
       digitalWrite(APIN2,LOW);
       digitalWrite(APIN3,LOW);
        digitalWrite(APIN4,HIGH);
        digitalWrite(APIN5,HIGH); 
       digitalWrite(APIN6,HIGH);
       digitalWrite(APIN7,HIGH);
        digitalWrite(APIN8,HIGH);
    }
     if(temp_ == 6) {
       digitalWrite(APIN2,HIGH);
       digitalWrite(APIN3,LOW);
        digitalWrite(APIN4,HIGH);
        digitalWrite(APIN5,HIGH); 
       digitalWrite(APIN6,HIGH);
       digitalWrite(APIN7,HIGH);
        digitalWrite(APIN8,HIGH);
    }
     if(temp_ == 7) {
       digitalWrite(APIN2,LOW);
       digitalWrite(APIN3,HIGH);
        digitalWrite(APIN4,HIGH);
        digitalWrite(APIN5,LOW); 
       digitalWrite(APIN6,LOW);
       digitalWrite(APIN7,LOW);
        digitalWrite(APIN8,HIGH);
    }
     if(temp_ == 8) {
      digitalWrite(APIN2,HIGH);
       digitalWrite(APIN3,HIGH);
        digitalWrite(APIN4,HIGH);
        digitalWrite(APIN5,HIGH); 
       digitalWrite(APIN6,HIGH);
       digitalWrite(APIN7,HIGH);
        digitalWrite(APIN8,HIGH);
    }
     if(temp_ == 9) {
       digitalWrite(APIN2,LOW);
       digitalWrite(APIN3,HIGH);
        digitalWrite(APIN4,HIGH);
        digitalWrite(APIN5,HIGH); 
       digitalWrite(APIN6,HIGH);
       digitalWrite(APIN7,HIGH);
        digitalWrite(APIN8,HIGH);
    }
 
  }
  else if(isFirstRead ==2 ) {
      lcd.clear();
      delay(100);
      // digitalWrite(LEDPIN_, HIGH);
     //  delay(1000);
     // digitalWrite(LEDPIN_, LOW);
     // delay(1000);
      str.concat(temp);

      Serial.print("red light:");
      Serial.println(str);
   }
 }
 
 char bufferDelete = Serial.read(); //마지막 useless char delete

 
  lcd.setCursor(0,0);
  lcd.print(myinfo);
 
 lcd.setCursor(0,1);
 lcd.print(str);
 delay(1000);
 

digitalWrite(LEDPIN,LOW);
digitalWrite(LEDPIN_, LOW);



}
