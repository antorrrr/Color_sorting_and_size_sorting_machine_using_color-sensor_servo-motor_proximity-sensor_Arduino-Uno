/*

Code By: *----- ANTOR MONDAL -----*

E-mail: antor.mondal2002@gmail.com

Facebook: https://www.facebook.com/antor31021/
LinkedIn: www.linkedin.com/in/antor-mondal-084764287

N.B: Please do not use this code for business puepose 

*/


//let's define the sensor pins
#define S0 4
#define S1 3
#define S2 6
#define S3 5
#define OUT 7

//set the intial value of the freuency
int redfrequency = 0;
int greenfrequency =0;
int bluefrequency =0;

void setup() 
{
  //declaring the output and input pins
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}
void loop()
{
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);

  // Reading the output frequency
  redfrequency = pulseIn(OUT, LOW);
  delay(100);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  greenfrequency = pulseIn(OUT, LOW);
  delay(100);

   // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  bluefrequency = pulseIn(OUT, LOW);

  // Printing the value on the serial monitor
  delay(100);

 Serial.print("Red = ");
 Serial.print(redfrequency);
 Serial.print("  -- Green = ");
 Serial.print(greenfrequency);
 Serial.print("  -- Blue = ");
 Serial.println(bluefrequency);
}
