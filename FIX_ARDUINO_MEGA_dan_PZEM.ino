#include "SoftwareSerial.h"
#define TX 9
#define RX 10

const byte wcs1700 = A0;
const byte wcs1700b = A1;
float zero = 509; //511.5; // zero calibrate
float span = 0.1386; // max Amp calibrate
float current1;
float current2;

//void setup() {
//  Serial.begin(9600);
//}
//
//void loop() {
/*  float current = (analogRead(wcs1700) - zero) * span;
  Serial.print(current, 1);
  Serial.println(" Amp");
  delay(1000);
//}*/


#include <PZEM004Tv30.h>

PZEM004Tv30 pzem1(TX, RX, 0x01);
PZEM004Tv30 pzem2(TX, RX, 0x02);
PZEM004Tv30 pzem3(TX, RX, 0x03);

void setup() {
   Serial.begin(115200);
}

void loop() {
    float current1 = (analogRead(wcs1700) - zero) * span;
    Serial.print(current1, 1);
    Serial.println(" Amp");
    delay(1000);
    float current2 = (analogRead(wcs1700b) - zero) * span;
    Serial.print(current2, 2);
    Serial.println(" Amp");
    delay(1000);
  
    Serial.println("BATAS\n\n");

     Serial.println("pzem pertama");
     float voltage = pzem1.voltage();
     if(voltage != NAN){
         Serial.print("Voltage: "); 
         Serial.print(voltage);
         Serial.println("V");
     } else {
         Serial.println("Error reading voltage");
     }

     float current = pzem1.current();
     if(current != NAN){
         Serial.print("Current: ");
         Serial.print(current);
         Serial.println("A");
     } else {
         Serial.println("Error reading current");
     }

     float power = pzem1.power();
     if(current != NAN){
         Serial.print("Power: ");
         Serial.print(power);
         Serial.println("W");
     } else {
         Serial.println("Error reading power");
     }

     float energy = pzem1.energy();
     if(current != NAN){
         Serial.print("Energy: ");
         Serial.print(energy,3);
         Serial.println("kWh");
     } else {
         Serial.println("Error reading energy");
     }

     float frequency = pzem1.frequency();
     if(current != NAN){
         Serial.print("Frequency: ");
         Serial.print(frequency, 1);
         Serial.println("Hz");
     } else {
         Serial.println("Error reading frequency");
     }

     float pf = pzem1.pf();
     if(current != NAN){
         Serial.print("PF: ");
         Serial.println(pf);
     } else {
         Serial.println("Error reading power factor");
     }
  Serial.println();
  Serial.println("pzem kedua");

  voltage = pzem2.voltage();
  if (voltage != NAN) {
    Serial.print("Voltage: "); Serial.print(voltage); Serial.println("V");
  } else {
    Serial.println("Error reading voltage");
  }

  current = pzem2.current();
  if (current != NAN) {
    Serial.print("Current: "); Serial.print(current); Serial.println("A");
  } else {
    Serial.println("Error reading current");
  }

  power = pzem2.power();
  if (current != NAN) {
    Serial.print("Power: "); Serial.print(power); Serial.println("W");
  } else {
    Serial.println("Error reading power");
  }

  energy = pzem2.energy();
  if (current != NAN) {
    Serial.print("Energy: "); Serial.print(energy, 3); Serial.println("kWh");
  } else {
    Serial.println("Error reading energy");
  }

  frequency = pzem2.frequency();
  if (current != NAN) {
    Serial.print("Frequency: "); Serial.print(frequency, 1); Serial.println("Hz");
  } else {
    Serial.println("Error reading frequency");
  }

  pf = pzem2.pf();
  if (current != NAN) {
    Serial.print("PF: "); Serial.println(pf);
  } else {
    Serial.println("Error reading power factor");
  }

  Serial.println();
  Serial.println("pzem ketiga");

  voltage = pzem3.voltage();
  if (voltage != NAN) {
    Serial.print("Voltage: "); Serial.print(voltage); Serial.println("V");
  } else {
    Serial.println("Error reading voltage");
  }

  current = pzem3.current();
  if (current != NAN) {
    Serial.print("Current: "); Serial.print(current); Serial.println("A");
  } else {
    Serial.println("Error reading current");
  }

  power = pzem3.power();
  if (current != NAN) {
    Serial.print("Power: "); Serial.print(power); Serial.println("W");
  } else {
    Serial.println("Error reading power");
  }

  energy = pzem3.energy();
  if (current != NAN) {
    Serial.print("Energy: "); Serial.print(energy, 3); Serial.println("kWh");
  } else {
    Serial.println("Error reading energy");
  }

  frequency = pzem3.frequency();
  if (current != NAN) {
    Serial.print("Frequency: "); Serial.print(frequency, 1); Serial.println("Hz");
  } else {
    Serial.println("Error reading frequency");
  }

  pf = pzem3.pf();
  if (current != NAN) {
    Serial.print("PF: "); Serial.println(pf);
  } else {
    Serial.println("Error reading power factor");
  }

     Serial.println();
     delay(2000);
 }
