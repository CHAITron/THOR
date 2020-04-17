
int LED1 = 5; //Green LED
int LED2 = 6; //Red LED

int trigPin1=3; //First Ultrasonic sensor - OK BUTTON - Green LED
int echoPin1=2;

int trigPin2=7; //Second Ultrasonic sensor - CHOOSE BUTTON - Red LED
int echoPin2=4;
int num=0;

String text="";

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 8, 9, 10, 11); //LCD Screen

void setup() {
  Serial.begin (9600);            //set transmission rate (bit/secs)
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  lcd.begin(16, 2);
  lcd.print("TEXT:  ");
  lcd.setCursor(0,1);
  lcd.print(">>0<<123456789/.");
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
}


void loop() {
  long duration1, distance1; //distance use for HC-SR04 which is 'OK button' 
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;

   if (distance1 >= 15 || distance1 <= 0){  //15 cm is threshold distance you can change
    Serial.println("Out of range");
    digitalWrite(LED1, LOW);
  }
  else {
    String num2 =  String(num, HEX);
    if (num == 10){num2="/";}
    if (num == 11){num2=".";}
    text += num2;
    lcd.setCursor(0,0);
    lcd.print("TEXT:  "+text);
    digitalWrite(LED1, HIGH);
    Serial.print ( "Sensor1  ");
    Serial.print ( distance1);
    Serial.println("cm (PRESSING)");
  }
  delay(200);   //you can adjust delay time for HC-SR04 sensitivity
long duration2, distance2;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2= (duration2/2) / 29.1;

   if (distance2 >= 15 || distance2 <= 0){   //15 cm is threshold distance you can change
    Serial.println("Out of range");
    digitalWrite(LED2, LOW);
  }
  else {
    digitalWrite(LED2, HIGH);
    Serial.print("Sensor2  ");
    Serial.print(distance2);
    Serial.println("cm (PRESSING)");
    num++;
    if (num == 12){num = 0;}
    lcd.setCursor(0,1);
    if (num == 0){lcd.print("> 0 <123456789/.");}
    if (num == 1){lcd.print("0> 1 <23456789/.");}
    if (num == 2){lcd.print("01> 2 <3456789/.");}
    if (num == 3){lcd.print("012> 3 <456789/.");}
    if (num == 4){lcd.print("0123> 4 <56789/.");}
    if (num == 5){lcd.print("01234> 5 <6789/.");}
    if (num == 6){lcd.print("012345> 6 <789/.");}
    if (num == 7){lcd.print("0123456> 7 <89/.");}
    if (num == 8){lcd.print("01234567> 8 <9/.");}
    if (num == 9){lcd.print("012345678> 9 </.");}
    if (num == 10){lcd.print("0123456789> / <.");}
    if (num == 11){lcd.print("0123456789/> . <");}
  }
  delay(200); //you can adjust delay time for HC-SR04 sensitivity
}
