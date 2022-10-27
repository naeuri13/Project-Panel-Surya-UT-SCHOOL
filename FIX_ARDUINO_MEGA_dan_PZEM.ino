#include "SoftwareSerial.h"
#include <stdio.h>
#include <math.h>
#include <PZEM004Tv30.h>
#include "EasyNextionLibrary.h"

//SoftwareSerial mySerial(2, 3); // RX, TX
EasyNex myNex(Serial);

// Voltage Sensor
#define ANALOG_IN_PIN A2
float adc_voltage = 0.0;
float in_volt = 0.0;
// Floats for resistor values in divider (in ohms)
float R1 = 22000.0;
float R2 = 4700.0;
float ref_voltage = 5.0;
int adc_value = 0;

const byte wcs1700 = A0;
const byte wcs1700b = A1;

//float zero = 511.5; //511.5; // zero calibrate
float zero = 509.3;
float span = 0.1386; // max Amp calibrate


PZEM004Tv30 pzem1(&Serial1);
PZEM004Tv30 pzem2(&Serial2);
PZEM004Tv30 pzem3(&Serial3);


void setup() {
  Serial.begin(115200);
//  mySerial.begin(115200);
  myNex.begin(115200);
}

void loop() {
  Serial.println("PANEL SURYA");
  Serial.println("DC Voltage Test ");
  adc_value = analogRead(ANALOG_IN_PIN);
  adc_voltage  = (adc_value * ref_voltage) / 1024.0;
  in_volt = adc_voltage / (R2 / (R1 + R2)) ;
  Serial.print("Input Voltage = ");
  float vsp = mapf(in_volt, 0, 21.8, 0, 120);
  Serial.print(vsp, 2);
  Serial.println("V");

  
  Serial.println("DC Current Test");
  float DCcurrent1 = (analogRead(wcs1700) - zero) * span;
  Serial.print(DCcurrent1, 2);
  Serial.println(" Amp");
  Serial.println(" ");
  
  Serial.println("WIND TURBINE");
  Serial.println("DC Current Test II");
  float DCcurrent2 = (analogRead(wcs1700b) - zero) * span;
  Serial.print(DCcurrent2, 2);
  Serial.println(" Amp");
  Serial.println("------------------------------------------------------------------------------------------------\n\n");

  Serial.println("pzem pertama");
  float voltage1 = pzem1.voltage();
  if (voltage1 != NAN) {
    Serial.print("Voltage: ");
    Serial.print(voltage1);
    Serial.println("V");
  } else {
    Serial.println("Error reading voltage");
  }

  float current1 = pzem1.current();
  if (current1 != NAN) {
    Serial.print("Current: ");
    Serial.print(current1);
    Serial.println("A");
  } else {
    Serial.println("Error reading current");
  }

  float power1 = pzem1.power();
  if (power1 != NAN) {
    Serial.print("Power: ");
    Serial.print(power1);
    Serial.println("W");
  } else {
    Serial.println("Error reading power");
  }

  float energy1 = pzem1.energy();
  if (energy1 != NAN) {
    Serial.print("Energy: ");
    Serial.print(energy1, 3);
    Serial.println("kWh");
  } else {
    Serial.println("Error reading energy");
  }

  float frequency1 = pzem1.frequency();
  if (frequency1 != NAN) {
    Serial.print("Frequency: ");
    Serial.print(frequency1, 1);
    Serial.println("Hz");
  } else {
    Serial.println("Error reading frequency");
  }

  float pf1 = pzem1.pf();
  if (pf1 != NAN) {
    Serial.print("PF: ");
    Serial.println(pf1);
  } else {
    Serial.println("Error reading power factor");
  }
  


  Serial.println("pzem kedua");

  float voltage2 = pzem2.voltage();
  if (voltage2 != NAN) {
    Serial.print("Voltage: "); 
    Serial.print(voltage2); 
    Serial.println("V");
  } else {
    Serial.println("Error reading voltage");
  }

  float  current2 = pzem2.current();
  if (current2 != NAN) {
    Serial.print("Current: "); 
    Serial.print(current2); 
    Serial.println("A");
  } else {
    Serial.println("Error reading current");
  }

  float  power2 = pzem2.power();
  if (power2 != NAN) {
    Serial.print("Power: "); 
    Serial.print(power2); 
    Serial.println("W");
  } else {
    Serial.println("Error reading power");
  }

  float energy2 = pzem2.energy();
  if (energy2 != NAN) {
    Serial.print("Energy: "); 
    Serial.print(energy2, 3); 
    Serial.println("kWh");
  } else {
    Serial.println("Error reading energy");
  }

  float frequency2 = pzem2.frequency();
  if (frequency2 != NAN) {
    Serial.print("Frequency: "); 
    Serial.print(frequency2, 1); 
    Serial.println("Hz");
  } else {
    Serial.println("Error reading frequency");
  }

  float  pf2 = pzem2.pf();
  if (pf2 != NAN & Serial) {
    Serial.print("PF: "); 
    Serial.println(pf2);
  } else {
    Serial.println("Error reading power factor");
  }
  Serial.println();


  Serial.println("pzem ketiga");

  float voltage3 = pzem3.voltage();
  if (voltage3 != NAN) {
    Serial.print("Voltage: "); 
    Serial.print(voltage3);
    Serial.println("V");
  } else {
    Serial.println("Error reading voltage");
  }

  float current3 = pzem3.current();
  if (current3 != NAN) {
    Serial.print("Current: "); 
    Serial.print(current3); 
    Serial.println("A");
  } else {
    Serial.println("Error reading current");
  }

  float power3 = pzem3.power();
  if (power3 != NAN) {
    Serial.print("Power: "); 
    Serial.print(power3); 
    Serial.println("W");
  } else {
    Serial.println("Error reading power");
  }

  float energy3 = pzem3.energy();
  if (energy3 != NAN) {
    Serial.print("Energy: "); 
    Serial.print(energy3, 3); 
    Serial.println("kWh");
  } else {
    Serial3.println("Error reading energy");
  }

  float frequency3 = pzem3.frequency();
  if (frequency3 != NAN) {
    Serial.print("Frequency: "); 
    Serial.print(frequency3, 1); 
    Serial.println("Hz");
  } else {
    Serial.println("Error reading frequency");
  }

  float pf3 = pzem3.pf();
  if (pf3 != NAN) {
    Serial.print("PF: "); Serial.println(pf3);
  } else {
    Serial.println("Error reading power factor");
  }
  Serial.println();

  String Volt2 = String (voltage2);
  String Amp2 = String (current2);
  String Pow2 = String (power2);
  String Fre2 = String (frequency2, 1);
  String Ene2 = String (energy2, 3);
  String Pfc2 = String (pf2);
  String sVSP = String (vsp);
  String sCSP = String (DCcurrent1);
  myNex.writeStr("tcoba.txt", "TES");
  
  myNex.writeStr("sVolt1.txt", Volt2);
  myNex.writeStr("sAmp1.txt", Amp2);
  myNex.writeStr("sPow1.txt", Pow2);
  myNex.writeStr("sFre1.txt", Fre2);
  myNex.writeStr("sEne1.txt", Ene2);
  myNex.writeStr("sPcf1.txt", Pfc2);

  //SOLAR PANEL
  myNex.writeStr("sVSP.txt", sVSP);
  myNex.writeStr("sCSP.txt", sCSP);  
  Serial.print(Volt2 + Amp2 + Pow2 + Ene2 + Fre2 + Pfc2 + vsp);

  Serial.println();




  delay(10);
}
float mapf(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
