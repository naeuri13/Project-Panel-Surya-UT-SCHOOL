const byte wcs1700 = A0;
float zero = 509; //511.5; // zero calibrate
float span = 0.1386; // max Amp calibrate
float current1;

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

PZEM004Tv30 pzem(&Serial1);  // Menggunakan Hardware Serial 3

void setup() {
   Serial.begin(115200);
}

void loop() {
    float current1 = (analogRead(wcs1700) - zero) * span;
    Serial.print(current1, 1);
    Serial.println(" Amp");
    delay(1000);
    Serial.println("BATAS\n\n");

      
     float voltage = pzem.voltage();
     if(voltage != NAN){
         Serial.print("Voltage: "); 
         Serial.print(voltage);
         Serial.println("V");
     } else {
         Serial.println("Error reading voltage");
     }

     float current = pzem.current();
     if(current != NAN){
         Serial.print("Current: ");
         Serial.print(current);
         Serial.println("A");
     } else {
         Serial.println("Error reading current");
     }

     float power = pzem.power();
     if(current != NAN){
         Serial.print("Power: ");
         Serial.print(power);
         Serial.println("W");
     } else {
         Serial.println("Error reading power");
     }

     float energy = pzem.energy();
     if(current != NAN){
         Serial.print("Energy: ");
         Serial.print(energy,3);
         Serial.println("kWh");
     } else {
         Serial.println("Error reading energy");
     }

     float frequency = pzem.frequency();
     if(current != NAN){
         Serial.print("Frequency: ");
         Serial.print(frequency, 1);
         Serial.println("Hz");
     } else {
         Serial.println("Error reading frequency");
     }

     float pf = pzem.pf();
     if(current != NAN){
         Serial.print("PF: ");
         Serial.println(pf);
     } else {
         Serial.println("Error reading power factor");
     }

     Serial.println();
     delay(2000);
 }
