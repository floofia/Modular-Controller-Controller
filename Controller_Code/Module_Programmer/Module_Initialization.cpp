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
int module_name;

int pins_analog[10];
int pins_digital[10];

int device_type;

}used_module;




Seesaw_read_settings(Adafruit_seesaw module)
{
//use functions from Bit_Write.h (should rename)
//read analog pin register
//read digital pins register
//read device type register
//and address register


}


Seesaw_module_setup(used_module[] module Adafruit_seesaw[] seesaw_module)
{


//digital pin setup
seesaw_module[i].pinmode(used_module.pins_digital[j], INPUT_PULLUP);
seesaw_module[i].digitalWrite(used_module.pins_digital[j], HIGH);


//analog pin setup
seesaw_module[i].pinmode(used_module.pins_analog[j], INPUT_PULLUP);
seesaw_module[i].digitalWrite(used_module.pins_analog[j], HIGH);
}



//notes

//If the device uses a joystick but is said to be read as a d-pad, convert analog signals to digital
//If a d-pad is set to a joystick set the values to be max analog value when pushed
//etc etc add to as needed

