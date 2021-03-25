// Smart Parking System
#include<Servo.h>

#include <Wire.h>

 #include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,9);

Servo shivam;

Servo samadhiya;

int c1=0;

int c2=0;

int f1 = 0, f2 =0,f3=0,f4=0;

int total_slot=4;

int in=0;

int space=0;

int slot_left=0;

int exitt=0;

int ir1=7;

int ir2=8;

int ir3=12;

int ir4=13;

int buzzer=123;

void setup()

{

  lcd.begin(16,2);

//Serial.begin(9600);

  pinMode(ir1,INPUT);

  pinMode(ir2,INPUT);

  pinMode(ir3,INPUT);

  pinMode(ir4,INPUT);

  pinMode(buzzer,OUTPUT);

  shivam.attach(10);

  samadhiya.attach(11);

  shivam.write(0);

  samadhiya.write(0);

  //lcd.setCursor (0,0);

//lcd.print("TOTAL SLOTS");

}

void loop()

{ 

  if(c1<total_slot)

  {

  if(digitalRead(ir1)==0 && f1 == 0 )

  { 

    shivam.write(100);

    f1 = 1;   

      }

  else if(digitalRead(ir2)==0 && f1 == 1)

  { 

    shivam.write(0);

    f1 =0;

    

     c1++;

     c2++;

     in++;

   }

   

  }

if(c2>0)

{

   if(digitalRead(ir3)==0 && f3 == 0)

  {

    samadhiya.write(100);  

    f3 =1;

    f4=1;

    exitt++;

    

  }

  else if(digitalRead(ir4)==0 &&f4== 1)

  {

    c2--;

    c1--;

    samadhiya.write(0);

    f3=0;

    f4=0;

    

   }

}

space=total_slot-in;

slot_left=space+exitt;

//Serial.print("TOTAL SLOTS::");

lcd.setCursor (0,0);

lcd.print("TOTAL SLOTS ");

// Serial.println(total_slot);

//total_slot;

lcd.print(slot_left);

//Serial.print("  ");

if(slot_left !=0){

//Serial.print("slot available:: ");

lcd.setCursor (0,1);

lcd.print("WELCOME  ");

//Serial.print(slot_left);

//lcd.clear();

}

else

{

  lcd.setCursor(0,1);

  //Serial.println("no");

lcd.print ("NOT SPACE");

  //lcd.clear();

  delay(10);

}

}