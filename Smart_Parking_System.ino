
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,2,3,4,5);
int US1=7;
int US2=8;
int US3=9;
void setup()
{
lcd.begin(16,2);
Serial.begin (9600);

}

void loop()
{
int count=3;
bool slot_1=true;
bool slot_2=true;
  bool slot_3=true;
  int cm1=distanceMeasurement(US1);
  int cm2=distanceMeasurement(US2);
  int cm3=distanceMeasurement(US3);
  
  if(cm1<64){
    slot_1=false;
  count--;
  }
  
  if(cm2<64){
   slot_2=false;
    count--;
  }
  
  if(cm3<64){
       slot_3=false;

    count--;
  }

  delay(1000);

  if(count!=0){
    lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("Free: ");
  if(slot_1==true)
    lcd.print("1");
  if(slot_2==true)
    lcd.print(" 2");
  if(slot_3==true)
    lcd.print(" 3");
    
  lcd.setCursor(0,1);
    lcd.print("Occupied:");
    if(slot_1==false)
    lcd.print("1");
  if(slot_2==false)
    lcd.print(" 2");
  if(slot_3==false)
    lcd.print(" 3");
    
    }
  else{
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("No Space Available");
  }
     delay(500);
    }
    



long microsecondsToCentimeters(long microseconds) {
 
  return microseconds / 29 / 2;
}

long distanceMeasurement(int pingPin){
  long duration, cm;

 
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

 
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  cm = microsecondsToCentimeters(duration);
  delay(100);
  return cm;
}
