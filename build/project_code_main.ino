/*

Code By: *----- ANTOR MONDAL -----*

E-mail: antor.mondal2002@gmail.com

Facebook: https://www.facebook.com/antor31021/
LinkedIn: www.linkedin.com/in/antor-mondal-084764287

N.B: Please do not use this code for business purpose 

*/


#include <Servo.h>

//define proximity pin
#define prox 7

//Servo Motors
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

//colorSensor-1
#define S01 3
#define S11 2
#define S21 5
#define S31 6
#define sensorOut1 4

int redfrequency1 = 0;
int greenfrequency1 =0;

//ColorSenor-2
#define S02 9
#define S12 8
#define S22 11
#define S32 12
#define sensorOut2 10

int redfrequency2 = 0;
int greenfrequency2 =0;

void setup() 
{
  //proximity sensor pin announce
  pinMode(prox, INPUT); 
  
  //servo pin announce
  servo1.attach(A0);
  servo2.attach(A1);
  servo3.attach(A2);
  servo4.attach(A3);
  servo5.attach(A4);

  pinMode(S01, OUTPUT);
  pinMode(S11, OUTPUT);
  pinMode(S21, OUTPUT);
  pinMode(S31, OUTPUT);
  pinMode(sensorOut1, INPUT);
  
  pinMode(S02, OUTPUT);
  pinMode(S12, OUTPUT);
  pinMode(S22, OUTPUT);
  pinMode(S32, OUTPUT);
  pinMode(sensorOut2, INPUT);
  
  // Set Frequency scaling to 20% for ColorSenor-1
  digitalWrite(S01,HIGH);
  digitalWrite(S11,LOW);

  // Set Frequency scaling to 20% for ColorSenor-2
  digitalWrite(S02,HIGH);
  digitalWrite(S12,LOW);

  Serial.begin(9600);
}
void loop() 
{
   int L = digitalRead(prox);
   
   if (L == 0)
   {
    servo1.write(135);
  //delay(2000);
 servo2.write(20);
  delay(5000);
   }
   else
   {
    servo1.write(100);
 //delay(2000);
 servo2.write(43);
  //delay(5000);
   }
// Setting red filtered photodiodes to be read for color sensor-1
  digitalWrite(S21,LOW);
  digitalWrite(S31,LOW);

  // Reading the output frequency
   redfrequency1 = pulseIn(sensorOut1, LOW);
  //delay(100);

// Setting red filtered photodiodes to be read for color sensor-2
  digitalWrite(S22,LOW);
  digitalWrite(S32,LOW);

// Reading the output frequency
   redfrequency2 = pulseIn(sensorOut2, LOW);
  //delay(100);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S21,HIGH);
  digitalWrite(S31,HIGH);

  // Reading the output frequency
  greenfrequency1 = pulseIn(sensorOut1, LOW);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S22,HIGH);
  digitalWrite(S32,HIGH);


  // Reading the output frequency
  greenfrequency2 = pulseIn(sensorOut2, LOW);


  if(redfrequency1>30 && redfrequency1<45) 
  {
   Serial.println("BIG RED OBJECT");

servo5.write(110);
  delay(500);
  servo5.write(180);
 delay(1000);
 servo5.write(110);
 

 servo3.write(170);
  delay(3000);
  servo3.write(89);
delay(1000);

  }

if(redfrequency2>58 && redfrequency2<68) 
  {
   Serial.println("SMALL RED OBJECT");

//servo3.write(89);
  //delay(1000);
  //servo3.write(10);
 //delay(1000);
 servo4.write(10);
  delay(3000);
  servo4.write(89);
delay(1000);

  }

if (greenfrequency1>55 && greenfrequency1<65) 
  {
  Serial.println("BIG GREEN OBJECT");

servo5.write(110);
  delay(500);
  servo5.write(180);
 delay(1000);
 servo5.write(110);
delay(4000);
servo3.write(10);
  delay(3000);
  servo3.write(89);
delay(3000);

  }


if (greenfrequency2>90 && greenfrequency2<105) 
  {
  Serial.println("SMALL GREEN OBJECT");
delay(3000);
servo4.write(170);
  delay(3000);
  servo4.write(89);
delay(3000);
  }
}