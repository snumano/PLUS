/*
ConfigBluetooth HC-06 from Arduino.
Change name, password and baud using serial port, only configurate one time
After upload code you have 10 seconds to connect the module
BT ---- Arduino
TX ----> 6
RX <---- 7

Once the LED off configuration will start and at the end LED will blink
After this you can pair your module
*/
#include <SoftwareSerial.h>
SoftwareSerial BT(6,7);
// creates a "virtual" serial port/UART
// connect BT module TX to D6
// connect BT module RX to D7
// connect BT Vcc to 5V, GND to GND

// Options:
  int ArduLED=13;       //Internal Arduino´s LED
  char ssid[10]   = "Zowi"; // Name for Bluetooth.
  char baudios     = '4';      // 1=>1200 baudios, 2=>2400, 3=>4800, 4=>9600 (default), 5=>19200, 6=>38400, 7=>57600, 8=>115200
  char password[10] = "1234";   // Password for pairing

void setup()
{
  BT.begin(9600); //9600bauds is the deafult baudrate for these modules.
          //if it´s not working try changing this baudrate to match your HC-06 initial setup
  
  // Waiting time (10 seconds) onboard LED is ON:
    pinMode(ArduLED,OUTPUT);
    digitalWrite(ArduLED,HIGH);
    delay(10000);
    digitalWrite(ArduLED,LOW);
  
BT.print("AT"); delay(1000); // Now configuration start

BT.print("AT+NAME"); BT.print(ssid); delay(1000);   // Change Name of BT

BT.print("AT+BAUD"); BT.print(baudios); delay(1000);    // Change Baud

BT.print("AT+PIN"); BT.print(password); delay(1000);      // Change Password
}

void loop()
{
  // After programing bluetooth, onboard LED will Blink.
  digitalWrite(ArduLED, !digitalRead(ArduLED));
  delay(500);
}
