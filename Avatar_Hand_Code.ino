#include <Servo.h>

Servo myservo2; 
Servo myservo4; 
Servo myservo6; 
Servo myservo8; 
Servo myservo10; 
Servo myservo12; 

int potPin0 = 0;    
int val0 = 0;       

int potPin1 = 1;    
int val1 = 0;       

int potPin2 = 2;    
int val2 = 0;    

int potPin3 = 3;    
int val3 = 0;   

int potPin4 = 4;    
int val4 = 0;   

int potPin5 = 5;    
int val5 = 0;   

void setup() {

  myservo2.attach(2);  
  myservo4.attach(4); 
  myservo6.attach(6); 
  myservo8.attach(8); 
  myservo10.attach(10); 
  myservo12.attach(12); 

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
Serial.print(analogRead(A0));
Serial.print('\n');
val0 = analogRead(A0);
val0 = map(val0, 0, 650, 400, -50);   
myservo2.write(val0*2); 

val1 = analogRead(A1);
val1 = map(val1, 300, 700, -50, 230);    
myservo4.write(val1*2); 

val2 = analogRead(A2);
val2 = map(val2, 0, 1023, -50, 230);     
myservo6.write(val2*2); 

val3 = analogRead(A3);
val3 = map(val3, 0, 1023, -50, 230);      
myservo8.write(val3*2); 

val4 = analogRead(A4);
val4 = map(val4, 0, 1023, -50, 230);     
myservo10.write(val4*2); 

val5 = analogRead(A5);
val5 = map(val5, 0, 1023, -50, 230);     
myservo12.write(val5*2); 

delay(20);

}
