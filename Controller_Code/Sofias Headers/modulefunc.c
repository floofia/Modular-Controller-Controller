#include "modulefunc.h"



void faceButtonSetup (int top, int bottom, int left, int right, char address, Adafruit_seesaw ss)
{
  Wire.begin();
  ss.begin(address); // The default address for the seesaw breakout board
  // Initialize the BLEGamepad
  gamepad.begin();
}