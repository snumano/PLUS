//----------------------------------------------------------------
// Code to put all 4 servos in home position (90 degrees)
//-----------------------------------------------------------------
#include <Servo.h>
#include <EEPROM.h>
#include <Otto.h>
#include <SoftwareSerial.h>
#include "BatReader.h"
#include <Oscillator.h>
#include "MaxMatrix.h"
#include <US.h>

Otto otto;  //This is Otto!
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
void setup() {
  //Set the servo pins
  otto.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR,true);
  otto.sing(S_connection); //Otto wake up!
  otto.home();
  delay(50);
  otto.sing(S_happy); // a happy Otto :)

  btSerial.begin(9600);
  Serial.begin(9600);
  printCommand();
}
///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void loop() {
  if (obstacleDetector()) {
    otto.putMouth(30 ,true);
    otto.sing(S_surprise);
  } else {
    otto.putMouth(10, true);
  }

  if (btSerial.available()) {
    int act = btSerial.parseInt();
    switch (act) {
      case 0: // jump
        otto.putMouth(13, true);
        otto.jump(1, 1000);
        break;
      case 1: // sing a song
        otto.putMouth(0, true);
        sing();
        break;
      case 2: // backward
        otto.putMouth(19, true);
        otto.walk(2, 1000, -1);
        break;
      case 3: // dance
        dance();
        break;
      case 4: // left
        otto.putMouth(11, true);
        otto.turn(3, 1200, 1);
        break;
      case 5: // stand
        otto.setRestState(false);
        otto.home();
        break;
      case 6: // right
        otto.putMouth(12, true);
        otto.turn(3, 1200, -1);
        break;
      case 7: // moonwalk left
        otto.putMouth(17, true);
        otto.moonwalker(3, 1200, 30, 1);
        break;
      case 8: // forward
        otto.putMouth(11, true);
        otto.walk(2, 1000, 1);
        break;
      case 9: // moonwalk right
        otto.putMouth(18, true);
        otto.moonwalker(3, 1200, 30, -1);
        break;
      case 10: // batteryVolage
        btSerial.println(otto.getBatteryVoltage());
        break;
      case 99:
        printCommand();
        break;
    }
  }
}

int obstacleDetector(){
  int distance = otto.getDistance();
  if(distance<15){
    return 1;
  }else {
    return 0;
  }
}

void printCommand() {
  btSerial.write("=================Otto bot command list====================\n");
  btSerial.write("0:jump, 1: sing a song, 2: backward, 3: dance, 4: left\n");
  btSerial.write("5:stand 6: right 7: moonwalk left, 8: forward , 9: moonwalk right\n");
  btSerial.write("10:battery voltage 99: command List\n");
  btSerial.write("==========================================================\n");
}

void dance() {
  for (int i=0; i<2; i++) {
    otto.moonwalker(4, 1000, 20, 1);
    otto.moonwalker(4, 1000, 20, -1);
  }

  otto.crusaito(1, 3800, 30, -1);
  otto.crusaito(1, 3500, 30, -1);

  for (int i=0; i<16; i++) {
    otto.flapping(1, 124, 8, 1);
    delay(371);
  }

  for (int i=0; i<2; i++) {
    otto.moonwalker(4, 1000, 20, 1);
    otto.moonwalker(4, 1000, 20, -1);
  }

  otto.crusaito(1, 1000, 30, -1);
  otto.crusaito(1, 3800, 30, -1);
  otto.crusaito(1, 1000, 30, -1);
  otto.crusaito(1, 3800, 30, -1);
  otto.crusaito(1, 1000, 30, -1);
  otto.crusaito(1, 1400, 30, -1);

  delay(495);

  for (int i=0; i<32; i++) {
    otto.flapping(1, 245, 8, 1);
    delay(245);
  }

  otto.setRestState(false);
  otto.home();
}

void sing() {
  char notes[] = "ccggaag ffeeddc ggffeed ggffeed ccggaag ffeeddc ";
  int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1 };
  int tempo = 300;
  int notes_index = 0;

  while (notes[notes_index] != '\0') {
    int beat = beats[notes_index%8]*tempo;
    switch (notes[notes_index]) {
      case 'c':
        otto._tone(note_C4, beat, 50);
        break;
      case 'd':
        otto._tone(note_D4, beat, 50);
        break;
      case 'e':
        otto._tone(note_E4, beat, 50);
        break;
      case 'f':
        otto._tone(note_F4, beat, 50);
        break;
      case 'g':
        otto._tone(note_G4, beat, 50);
        break;
      case 'a':
        otto._tone(note_A4, beat, 50);
        break;
      case ' ': // space
        delay(beat/3);
        break;
    }
    notes_index+=1;
  }
}
