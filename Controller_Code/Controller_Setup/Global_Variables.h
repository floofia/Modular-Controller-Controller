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
extern String names_dev[] = {"###################",
  "Passive -- 0", 
  "Audio -- 16",
  "Visual -- 32",
  "Haptic -- 48",
  "----------------",
  "D-Pad -- 1",
  "Joystick -- 2",
  "Keyboard -- 4",
  "Trigger -- 5",
  "###################"};




struct used_module{
  
char module_name[64] = "";

int pins_analog[8] = {0, 0, 0, 0, 0, 0, 0, 0}; 
int pins_digital[8] = {0, 0, 0, 0, 0, 0, 0, 0}; 

int device_type = 0;

int address = 0;

};

extern struct used_module module;


#endif
