#include <Wire.h>
#include "Adafruit_seesaw.h"
#include <BLEGamepad.h>


void faceButtonSetup (int top, int bottom, int left, int right, char address, Adafruit_seesaw ss);
void faceButtonRead (int top, int bottom, int left, int right, Adafruit_seesaw ss);
void dpadSetup (int up, int down, int left, int right, char address, Adafruit_seesaw ss);
void dpadRead (int up, int down, int left, int right, Adafruit_seesaw ss);
void rJoystickSetup(int x, int y, int select, char address, Adafruit_seesaw ss);
void rJoystickRead(int x, int y, int select, Adafruit_seesaw ss);
void lJoystickSetup(int x, int y, int select, char address, Adafruit_seesaw ss);
void lJoystickRead(int x, int y, int select, Adafruit_seesaw ss);
