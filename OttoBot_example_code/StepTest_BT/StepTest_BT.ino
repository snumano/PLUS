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
  Otto.home();

  btSerial.begin(9600);
  commandList();
}

///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void loop() {
  if (btSerial.available()) {
    String command = btSerial.readString();
    command.replace(" ", "");
    int length = command.length();
    String command_1 = command.substring(0, length-1);

    if (command.equals("home")) {
      btSerial.println("Otto at rest position");
      Otto.setRestState(false);
      Otto.home();
    } else if (command.equals("jump")) {
      btSerial.println("Otto jump");
      Otto.jump(1, 1500);
    } else if (command_1.equals("walk")) {
      int dir = command.substring(length-1, length).toInt();
      if (dir == 1 || dir == 2) {
        if (dir == 2) dir = -1;
        btSerial.println("Otto walking");
        Otto.walk(2, 1000, dir);
      }
    } else if (command_1.equals("turn")) {
      int dir = command.substring(length-1, length).toInt();
      if (dir == 1 || dir == 2) {
        if (dir == 2) dir = -1;
        btSerial.println("Otto Turning");
        Otto.turn(4, 1500, dir);
      }
    } else if (command_1.equals("bend")) {
      int dir = command.substring(length-1, length).toInt();
      if (dir == 1 || dir == 2) {
        if (dir == 2) dir = -1;
        btSerial.println("Otto bend");
        Otto.bend(1, 1500, dir);
      }
    } else if (command_1.equals("shakeLeg")) {
      int dir = command.substring(length-1, length).toInt();
      if (dir == 1 || dir == 2) {
        if (dir == 2) dir = -1;
        btSerial.println("Otto shakeLeg");
        Otto.shakeLeg(1, 1500, dir);
      }
    } else if (command.equals("updown")) {
      btSerial.println("Otto updown");
      Otto.updown(1, 1500, 15);
    } else if (command.equals("swing")) {
      btSerial.println("Otto swing");
      Otto.swing(1, 1500, 15);
    } else if (command.equals("tiptoeSwing")) {
      btSerial.println("tiptoeSwing");
      Otto.tiptoeSwing(1, 1500, 15);
    } else if (command.equals("jitter")) {
      btSerial.println("Otto jitter");
      Otto.jitter(1, 1500, 15);
    } else if (command.equals("ascendingTurn")) {
      btSerial.println("Otto ascendingTurn");
      Otto.ascendingTurn(1, 1500, 15);
    } else if (command_1.equals("moonwalker")) {
      int dir = command.substring(length-1, length).toInt();
      if (dir == 1 || dir == 2) {
        if (dir == 2) dir = -1;
        btSerial.println("Otto moonwalker");
        Otto.moonwalker(4, 1500, 15, dir);
      }
    } else if (command_1.equals("crusaito")) {
      int dir = command.substring(length-1, length).toInt();
      if (dir == 1 || dir == 2) {
        if (dir == 2) dir = -1;
        btSerial.println("Otto crusaito");
        Otto.crusaito(2, 1500, 15, dir);
      }
    } else if (command_1.equals("flapping")) {
      int dir = command.substring(length-1, length).toInt();
      if (dir == 1 || dir == 2) {
        if (dir == 2) dir = -1;
        btSerial.println("Otto flapping");
        Otto.flapping(2, 1500, 15, dir);
      }
    } else if (command.equals("help")) {
      help();
    } else if (command.equals("command")) {
      commandList();
    } else {
      btSerial.println("please check the command");
    }
  }
}

void commandList() {
  btSerial.println("CommandList");
  btSerial.print("home, jump, walk, turn, bend, shakeLeg, updown, swing, tiptoeSwing, ");
  btSerial.println("jitter, ascendingTurn, moonwalker, crusaito, flapping, help, command");
}

void help() {
  btSerial.println("========================================================");
  btSerial.println("The following items require additional parameters.");
  btSerial.println("walk, turn, bend, shakeLeg, moonwalker, crusaito, flapping");
  btSerial.println("1 means : forward or left, 2 means: backward or right");
  btSerial.println("e.g: walk 1 (this means This means walking forward.)");
  btSerial.println("========================================================");
}
