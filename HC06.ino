
// Done by T SAI RUTHVIK
//  Uses hardware serial to talk to the host computer and software serial for communication with the bluetooth module
//
//  Pinout
//  Bluetooth VCC to Arduino 5V out. 
//  Bluetooth GND to GND
//  Bluetooth Receiver to Arduino pin 3 (through a voltage divider)
//  Bluetooth Transmitter  to Arduino pin 2 (no need voltage divider)
//
//  When a command is entered in the serial monitor on the computer 
//  the Arduino will relay it to the bluetooth module and display the result.
//
//  These HC-06 modules require capital letters and no line ending
//
 
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); // RX | TX
 
void setup() 
{
  Serial1.begin(9600);
  pinMode(8,OUTPUT); digitalWrite(8,HIGH);
  Serial1.println("Enter AT commands:");
 
  // HC-06 default baud rate is 9600
  BTSerial.begin(9600);  
}
 
void loop()
{
 
  // Keep reading from HC-06 and send to Arduino Serial Monitor
  if (BTSerial.available())
    Serial1.write(BTSerial.read());
 
  // Keep reading from Arduino Serial Monitor and send to HC-06
  if (Serial1.available())
  BTSerial.write(Serial1.read());
}
