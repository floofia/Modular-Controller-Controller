/* SDSMT
 * #11ModularGameController
 * written by Duncan McGonagle
*/


#ifndef MODULE_INITIALIZATION_H
#define MODULE_INITIALIZATION_H

#include <Arduino.h>
#include "Global_Variables.h"
#include "Adafruit_seesaw.h"
#include "serial_setup.h"
#include "i2c_scan.h"
#include "Module_Read_Write_Functions.h"


void Seesaw_Struct_Name(struct used_module &module);
void Seesaw_read_settings(struct used_module &module, Adafruit_seesaw ss);
//void byte_to_pins_read(struct used_module &module, int pins, bool digital);




/// @brief this prints via serial the information about the module
/// @param module this is the module information
void Seesaw_Struct_Name(struct used_module &module)
{


int j = 0;


Serial.println("--Modules Output--");

//Serial.print("Seesaw: ");
//Serial.println(modules_used[i].mod);

Serial.print("Module Name: ");
Serial.println(module.module_name);


Serial.print("Pins: ");

for (j = 0; j < 14; j++)
{
Serial.print(module.pins[j]);
Serial.print(", ");
}
Serial.print(module.pins[15]);

Serial.println();

Serial.print("Device Type: ");
Serial.println(module.device_type);

Serial.print("Address: ");
Serial.println(module.address);

}

/// @brief this reads in the details of a module from serial
/// @param module This is the module information
/// @param ss this is the module itselg
void Seesaw_read_settings(struct used_module &module, Adafruit_seesaw ss)
{

int digital, analog = 0;

//read module name

int eepromval;


 for (int i = 0; i < 32; i++)
 {
   eepromval = ss.EEPROMRead8(i);
   module.module_name[i] = (char)eepromval;
 }

//read which pins are used
// 0, 1, 2, 3, 20, 5, 6, 7, 8, 9, 12, 13, 14, 18, 19

for (int j = 0; j < 15; j++)
 {

module.pins[j] = ss.EEPROMRead8(70 + j);

 }


//read device type
 module.device_type = ss.EEPROMRead8(126);

//read address of module
 module.address = ss.EEPROMRead8(127);

}


#endif
