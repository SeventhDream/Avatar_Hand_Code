/*
  Example for MCP3008 - Library for communicating with MCP3008 Analog to digital converter.
  Created by Uros Petrevski, Nodesign.net 2013
  Released into the public domain.
*/

#include <MCP3008.h>


// define pin connections
#define CS_PIN 12
#define CLOCK_PIN 9
#define MOSI_PIN 11
#define MISO_PIN 10

// put pins inside MCP3008 constructor
MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN);

/* Include the HCPCA9685 library */
#include "HCPCA9685.h"

/* I2C slave address for the device/module. For the HCMODU0097 the default I2C address
   is 0x40 */
#define  I2CAdd 0x40


/* Create an instance of the library */
HCPCA9685 HCPCA9685(I2CAdd);
int indexPos = 0;
void setup() {
 
 // open serial port
 Serial.begin(9600);
  /* Initialise the library and set it to 'servo mode' */ 
  HCPCA9685.Init(SERVO_MODE);

  /* Wake the device up */
  HCPCA9685.Sleep(false);
}



void loop() {
  
  
  int valElbow = adc.readADC(0); // read Chanel 0 from MCP3008 ADC
  Serial.print("Elbow: ");
  Serial.print(valElbow);
  Serial.print(" - ");
  valElbow = map(valElbow, 100, 510, 50, 430); // Map potentiometer value to servo position range
  Serial.print(valElbow);
  HCPCA9685.Servo(10, valElbow);
  
  int valShoulder = adc.readADC(1); // read Chanel 0 from MCP3008 ADC
  Serial.print(" | Shoulder: ");
  Serial.print(valShoulder);
  Serial.print(" - ");
  valShoulder = map(valShoulder, 500, 300, 10, 400); // Map potentiometer value to servo position range
  Serial.print(valShoulder);
  HCPCA9685.Servo(12, valShoulder);

  int valWrist = adc.readADC(2); // read Chanel 0 from MCP3008 ADC
  Serial.print(" | Wrist: ");
  Serial.print(valWrist);
  Serial.print(" - ");
  valWrist = map(valWrist, 230, 730, 10, 300); // Map potentiometer value to servo position range
  Serial.print(valWrist);
  HCPCA9685.Servo(8, valWrist);

    int valBicep = adc.readADC(3); // read Chanel 0 from MCP3008 ADC
  Serial.print(" | Bicep: ");
  Serial.print(valBicep);
  Serial.print(" - ");
  valBicep = map(valBicep, 500, 1023, 10, 300); // Map potentiometer value to servo position range
  Serial.print(valBicep);
  HCPCA9685.Servo(11, valBicep);
  
  int valShoulderHRot = adc.readADC(4); // read Chanel 0 from MCP3008 ADC
  Serial.print(" | ShoulderHRot: ");
  Serial.print(valShoulderHRot);
  Serial.print(" - ");
  valShoulderHRot = map(valShoulderHRot, 500, 1023, 10, 300); // Map potentiometer value to servo position range
  Serial.println(valShoulderHRot);
  HCPCA9685.Servo(9, valShoulderHRot);

  // int val2 = adc.readADC(2); // read Chanel 0 from MCP3008 ADC
  // Serial.print(val2);
  // val2 = map(val2, 0, 1023, 450, 10); // Map potentiometer value to servo position range
  // HCPCA9685.Servo(10, val2);

  // int val3 = adc.readADC(3); // read Chanel 0 from MCP3008 ADC
  // Serial.println(val3);
  // val3 = map(val3, 0, 1023, 450, 10); // Map potentiometer value to servo position range
  // HCPCA9685.Servo(11, val3);




  
  // iterate thru all channels
  /*
  for (int i=0; i<8; i++) {
   int val = adc.readADC(i);
   Serial.print(val);
   Serial.print("\t");
   }
   Serial.println("");
  */
  
}
