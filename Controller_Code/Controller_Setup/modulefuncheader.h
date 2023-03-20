#ifndef MODULEFUNCHEADER_H_
#define MODULEFUNCHEADER_H_

#include <BleConnectionStatus.h>
#include <BleGamepad.h>
#include <BleGamepadConfiguration.h>
#include "Adafruit_seesaw.h"
#include <stdbool.h>
#include <Wire.h>


BleGamepad gamepad;


////////////////////////
////****************////
////**DECLARATIONS**////
////****************////
////////////////////////
void faceButtonSetup (int top, int bottom, int left, int right, Adafruit_seesaw ss);
void faceButtonRead (int top, int bottom, int left, int right, Adafruit_seesaw ss);
void dpadSetup (int up, int down, int left, int right, Adafruit_seesaw ss);
void dpadRead (int up, int down, int left, int right, Adafruit_seesaw ss);
void rJoystickSetup(int x, int y, int select, Adafruit_seesaw ss);
void rJoystickRead(int x, int y, int select, Adafruit_seesaw ss);
void lJoystickSetup(int x, int y, int select, Adafruit_seesaw ss);
void lJoystickRead(int x, int y, int select, Adafruit_seesaw ss);
void lTriggerSetup ( int top, int bottom, Adafruit_seesaw ss );
void rTriggerSetup ( int top, int bottom, Adafruit_seesaw ss );
void lTriggerRead ( int top, int bottom, Adafruit_seesaw ss );
void rTriggerRead ( int top, int bottom, Adafruit_seesaw ss );
void debuggerSetup(int output, Adafruit_seesaw ss);
void debuggerWrite(int output, Adafruit_seesaw ss);
int  check_modules();

#endif
