/* FILE:    Avatar Arm Exoskeleton Control
   DATE:    6/11/2022
   VERSION: 1
   AUTHOR:  Reuel Terezakis

This code uses the HCPCA9685 library together with the PCA9685
to control up to 11 servos in a linkage-based robot arm. The sketch will initialise the library putting it into 
'servo mode' and then map the potentiometer voltage values from the exoskeleton controller to the position range of the servos.

To use the module connect it to your Arduino as follows:

PCA9685...........Uno/Nano
GND...............GND
OE................N/A
SCL...............A5
SDA...............A4
VCC...............5V

External 5V Power for the servo(s) can be supplied by the V+ and GND input of the 
screw terminal block.

PLEASE NOTE: Depending on your servo it is possible for this sketch to attempt 
drive the servo beyond its end stops. If your servo is hitting its end stops then
you should adjust the the min and max values in this sketch.

You may copy, alter and reuse this code in any way you like, but please leave
reference to HobbyComponents.com in your comments if you redistribute this code.
This software may not be used directly for the purpose of selling products that
directly compete with Hobby Components Ltd's own range of products.

THIS SOFTWARE IS PROVIDED "AS IS". HOBBY COMPONENTS MAKES NO WARRANTIES, WHETHER
EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ACCURACY OR LACK OF NEGLIGENCE.
HOBBY COMPONENTS SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR ANY DAMAGES,
INCLUDING, BUT NOT LIMITED TO, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY
REASON WHATSOEVER.
*/


/* Include the HCPCA9685 library */
#include "HCPCA9685.h"

/* I2C slave address for the device/module. For the HCMODU0097 the default I2C address
   is 0x40 */
#define  I2CAdd 0x40


/* Create an instance of the library */
HCPCA9685 HCPCA9685(I2CAdd);

int potPin0 = 0;    
int indexPos = 0;       

int potPin1 = 1;    
int middlePos = 0;       

int potPin2 = 2;    
int ringFinger = 0;    

int potPin3 = 3;    
int pinkyPos = 0;   

int potPin4 = 4;    
int thumbPos = 0;   

int potPin5 = 5;    
int palmPos = 0;   

void setup()
{
  /* Initialise the library and set it to 'servo mode' */ 
  HCPCA9685.Init(SERVO_MODE);

  /* Wake the device up */
  HCPCA9685.Sleep(false);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, OUTPUT);
  pinMode(A7, OUTPUT);
  pinMode(A8, OUTPUT);
  pinMode(A9, OUTPUT);
  pinMode(A10, OUTPUT);
  Serial.begin(9600);
}


void loop() 
{
  unsigned int Pos;

  indexPos = analogRead(A0); // Get Index finger potentiometer voltage reading.
  indexPos = map(indexPos, 0, 1023, 400, 10); // Map potentiometer value to servo position range
  HCPCA9685.Servo(0, Pos); // 
  
  middlePos = analogRead(A1);
  middlePos = map(middlePos, 0, 1023, 400, 10);    
  myservo4.write(middlePos*2); 
  
  ringPos = analogRead(A2);
  ringPos = map(ringPos, 0, 1023, 400, 10);     
  myservo6.write(ringPos*2); 
  
  pinkyPos = analogRead(A3);
  pinkyPos = map(pinkyPos, 0, 1023, 400, 10);      
  myservo8.write(pinkyPos*2); 
  
  thumbPos = analogRead(A4);
  thumbPos = map(thumbPos, 0, 1023, 400, 10);     
  myservo10.write(thumbPos*2); 
  
  palmPos = analogRead(A5);
  palmPos = map(palmPos, 0, 1023, 400, 10);     
  myservo12.write(palmPos*2); 
  
  delay(20); // Loop frequency: 50Hz
}
