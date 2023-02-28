//#include <Wire.h>

#ifndef MODULEFUNC_H
#define MODULEFUNC_H
#include <BleGamepad.h>
#include "Adafruit_seesaw.h"
#include <stdbool.h>

void faceButtonSetup (int top, int bottom, int left, int right, char address, Adafruit_seesaw ss);
void faceButtonRead (int top, int bottom, int left, int right, Adafruit_seesaw ss);
void dpadSetup (int up, int down, int left, int right, char address, Adafruit_seesaw ss);
void dpadRead (int up, int down, int left, int right, Adafruit_seesaw ss);
void rJoystickSetup(int x, int y, int select, char address, Adafruit_seesaw ss);
void rJoystickRead(int x, int y, int select, Adafruit_seesaw ss);
void lJoystickSetup(int x, int y, int select, char address, Adafruit_seesaw ss);
void lJoystickRead(int x, int y, int select, Adafruit_seesaw ss);
void lTriggerSetup ( int top, int bottom, char address, Adafruit_seesaw ss );
void rTriggerSetup ( int top, int bottom, char address, Adafruit_seesaw ss );
void lTriggerRead ( int top, int bottom, bool trigger, Adafruit_seesaw ss );
void rTriggerRead ( int top, int bottom, bool trigger, Adafruit_seesaw ss );
void debuggerSetup(int output, char address, Adafruit_seesaw ss);
void debuggerWrite(int output, bool trigger, bool button, bool joystick, char address, 
                   Adafruit_seesaw ss);


#endif
