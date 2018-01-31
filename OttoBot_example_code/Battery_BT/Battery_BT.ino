#include <Servo.h>
#include <EEPROM.h>
#include <Otto.h>
#include "BatReader.h"
#include <SoftwareSerial.h>
#include <Oscillator.h>
#include <US.h>
#include "MaxMatrix.h"

Otto otto;
SoftwareSerial myserial(7, 6);
//---------------------------------------------------------
//-- First step: Configure the pins where the servos are attached
/*
         ---------------
        |     O   O     |
        |---------------|
YR 3==> |               | <== YL 2
         ---------------
            ||     ||
RR 5==>   -----   ------  <== RL 4
         |-----   ------|
*/
  #define PIN_YL 2 //servo[0]
  #define PIN_YR 3 //servo[1]
  #define PIN_RL 4 //servo[2]
  #define PIN_RR 5 //servo[3]

void setup() {
  // put your setup code here, to run once:
  otto.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR,true);
  otto.home();
  myserial.begin(9600);
}

void loop() {
  myserial.print("Battery Voltage: ");
  myserial.println(otto.getBatteryVoltage());
  myserial.print("Battery Level: ");
  myserial.print(otto.getBatteryLevel());
  myserial.println("%\n\r");
  delay(1000);
}
