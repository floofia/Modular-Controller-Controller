/* SDSMT
 * #11ModularGameController
 * written by Duncan McGonagle, Sofia Sadun
 * File with Global Variables to be used by multiple files
*/

#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

//addresses read from connectec attiny817 devices
extern int i2c_addresses[8] = {0, 0, 0, 0, 0, 0, 0, 0};
//number of connected devices;
extern int nDevices = 0;

//menu for showing device type options
extern String names_dev[] = {
  "###################",
  "Passive -- 0", 
  "Audio -- 16",
  "Visual -- 32",
  "Haptic -- 48",
  "----------------",
  "Face Buttons -- 1",
  "L Trigger -- 2",
  "R Trigger -- 3",
  "L Joystick -- 4",
  "R Joystick -- 5",
  "D-Pad -- 6",
  "###################"
  };


///module struct - this carries all the info that'll be passed into the GUI 
struct used_module{
  
  char module_name[64] = "";
  // pins is an array that will hold all the pin connections in an agreed upon
  // order. This order depends on the module type and new modules will be able
  // to choose their own order they want the values passed in as. 
  int pins[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
  
  //device type is another
  int device_type = 0;
  
  // address of the seesaw. Values represent different modules.
  int address = 0;

};

extern struct used_module module[8];

extern struct BleGamepad gamepad;

extern struct Adafruit_seesaw ssa[8];

#endif
