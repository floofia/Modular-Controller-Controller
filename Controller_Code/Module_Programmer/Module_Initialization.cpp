/* SDSMT
 * #11ModularGameController
 * written by Duncan McGonagle
*/

#include <Arduino.h>
#include "globals.h"
#include "Adafruit_seesaw.h"
#include "serial_setup.h"
#include "i2c_scan.h"
#include "Bit_Write.h"


//seesaw modules to be initialized
Adafruit_seesaw module[8];


struct{
char module_name[64];

int pins_analog[10];
int pins_digital[10];

int device_type;

int address;

}used_module;




Seesaw_read_settings(Adafruit_seesaw module)
{

int digital, analog = 0;

//read module name
  for (i = 0; i < 32; i++)
  {
    eepromval = ss.EEPROMRead8(i);
    used_module.module_name[i] = (char)eepromval;
  }

//read which pins are used and if they are analog or digital
  digital = ss.EEPROMRead8(124);
  analog = ss.EEPROMRead8(125);

  //convert byte to pins used function
  ///
  ///

//read device type
  used_module.device_type = ss.EEPROMRead8(126);

//read address of module
  used_module.address = ss.EEPROMRead8(127);

}


byte_to_pins_read(int pins, bool digital)
{

mask[9] = {}

//example 1100 1100
//1000 0000
//0100 0000
//0010 0000
//0001 0000
//0000 1000
//0000 0100
//0000 0010
//0000 0001


}



Seesaw_module_setup(used_module[] module Adafruit_seesaw[] seesaw_module)
{

//digital pin setup
seesaw_module[i].pinmode(used_module.pins_digital[i], INPUT_PULLUP);
seesaw_module[i].digitalWrite(used_module.pins_digital[i], HIGH);

//analog pin setup
seesaw_module[i].pinmode(used_module.pins_analog[i], INPUT_PULLUP);
seesaw_module[i].digitalWrite(used_module.pins_analog[i], HIGH);

}

//notes

//If the device uses a joystick but is said to be read as a d-pad, convert analog signals to digital
//If a d-pad is set to a joystick set the values to be max analog value when pushed
//etc etc add to as needed



