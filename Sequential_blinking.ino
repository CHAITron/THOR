
int LED1 = 12;
int LED2 = 11;

int trigPin1=2;
int echoPin1=3;

int trigPin2=8;
int echoPin2=13;
int num=0;
String text="";
#include <LiquidCrystal.h>
LiquidCrystal lcd(10, 9, 4, 5, 6, 7);
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
  long duration1, distance1;
  digitalWrite(trigPin1, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;

   if (distance1 >= 15 || distance1 <= 0){
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
  delay(200);
long duration2, distance2;
  digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2= (duration2/2) / 29.1;

   if (distance2 >= 15 || distance2 <= 0){
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
  delay(200);

  /*digitalWrite(LED1, HIGH);    // turn on LED1
  delay(200);                  // wait for 200ms       
  digitalWrite(LED2, HIGH);    // turn on LED2 
  delay(2000);                  // wait for 200ms
  digitalWrite(LED1, LOW);     // turn off LED1
  delay(300);                  // wait for 300ms
  digitalWrite(LED2, LOW);     // turn off LED2
  delay(300);*/                  // wait for 300ms before running program all over again
}
