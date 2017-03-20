//  done by T SAI RUTHVIK 
//  Uses hardware serial to talk to the host computer and software serial for communication with the bluetooth module
//
//  Pinout
//  Bluetooth VCC to Arduino 5V out. 
//  Bluetooth GND to GND
//  Bluetooth Receiver to Arduino pin 10 (through a voltage divider)
//  Bluetooth Transmitter  to Arduino pin 9 (no need voltage divider)
//  OUT pin to 5v for AT commands
//
//  When a command is entered in the serial monitor on the computer 
//  the Arduino will relay it to the bluetooth module and display the result.
//
//  These HC-05 modules require capital letters and no line ending

#include<SoftwareSerial.h>

SoftwareSerial BTSerial(9,10);

String HC_05="";// response of HC 05 Bluettoth module

void setup(){



Serial.begin(9600);

Serial.println("Enter AT command:");

BTSerial.begin(9600);

}

void loop(){

if(BTSerial.available())

Serial.write(BTSerial.read());

if(Serial.available())

BTSerial.write(Serial.read());

}
