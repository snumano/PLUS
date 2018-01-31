//----------------------------------------------------------------
// Code to put all 4 servos in home position (90 degrees)
//-----------------------------------------------------------------
#include <Servo.h>
#include <EEPROM.h>
#include <Otto.h>
#include <SoftwareSerial.h>
#include <Oscillator.h>
#include "MaxMatrix.h"
#include <US.h>
#include <BatReader.h>
Otto Otto;  //This is Otto!
SoftwareSerial btSerial(7,6);
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

///////////////////////////////////////////////////////////////////
//-- Global Variables -------------------------------------------//

///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void setup(){
  //Set the servo pins
  Otto.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR,true);
  Otto.clearMouth();

  btSerial.begin(9600);
  btSerial.println("zero:0\none:1\ntwo:2\nthree:3\nfour:4\nfive:5\nsix:6\nseven:7\neight:8\nnine:9\nsmile:10\nhappyOpen:11\nhappyClosed:12\nheart:13\nbigSurprise:14\nsmallSurprise:15\ntongueOut:16\nvamp1:17\nvamp2:18\nlineMouth:19\nconfused:20\ndiagonal:21\nsad:22\nsadOpen:23\nsadClosed:24\nokMouth:25\nxMouth:26\ninterrogation:27\nthunder:28\nculito:29\nangry:30");
  Otto.home();
}

///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void loop() {
  while(btSerial.available()) {
    int val = btSerial.parseInt();
    if (val >= 0 && val <= 30) {
      Otto.putMouth(val, true);
    }
    delay(2000);
  }
}
