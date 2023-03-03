/* SDSMT
   #11ModularGameController
   written by Duncan McGonagle
   Main file for handling programming the i2c devices
   Outputs information the GUI can read
*/

#include <Arduino.h>
#include "Controller_Setup.h"

/* Displays the connected i2c devices to the screen
   This can be easily viewed by the user and the GUI
   The user is given menu prompts to choose the
   module they want to program and view
*/
void setup() {


  //toggle switch
  pinMode(A0, INPUT_PULLUP);


  serial_setup(115200);
  while (!Serial) delay(1000);   // wait until serial port is opened


  //if toggle is HIGH
  if (digitalRead(A0) == HIGH)
  {
    Controller_Programming_Mode();
  }
  else
  {
    Controller_Game_Mode();
  }


}



void loop()
{
  //unneeded as we do not reach this point
}
