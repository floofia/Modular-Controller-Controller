#include <Wire.h>
#include "Adafruit_seesaw.h"
#include <BLEGamepad.h>


void faceButtonSetup (int top, int bottom, int left, int right, Adafruit_seesaw ss);
void faceButtonRead (int top, int bottom, int left, int right, Adafruit_seesaw ss);
void dpadSetup (int up, int down, int left, int right, Adafruit_seesaw ss);
void dpadRead (int down, int down, int left, int right, Adafruit_seesaw ss);
void joystickSetup(int x, int y, int select, Adafruit_seesaw ss);
void joystickRead(int x, int y, int select, Adafruit_seesaw ss);