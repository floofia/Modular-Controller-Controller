/* SDSMT
 * #11ModularGameController
 * written by Duncan McGonagle
*/

#include <Arduino.h>
#include "Global_Variables.h"
#include "Adafruit_seesaw.h"
#include "serial_setup.h"
#include "i2c_scan.h"
#include "Module_Read_Write_Functions.h"


//seesaw modules to be initialized
//Adafruit_seesaw module[8];


struct{
Adafruit_seesaw mod;

char module_name[64];

int pins_analog[10];
int pins_digital[10];

int device_type;

int address;

}used_module;





Seesaw_Struct_Name()
{

used_module modules_used[8];


for (int i = 0; i < 8; i++)


{

Serial.println("--Modules Output--");

Serial.print("Seesaw: ");
Serial.println(modules_used[i].mod);

Serial.print("Module Name: ");
Serial.println(modules_used[i].module_name);

Serial.print("Analog Pins: ");
Serial.println(modules_used[i].pins_analog);

Serial.print("Digital Pins: ");
Serial.println(modules_used[i].pins_digital);

Serial.print("Device Type: ");
Serial.println(modules_used[i].device_type);

Serial.print("Address: ");
Serial.println(modules_used[i].address);

}








}



Seesaw_read_settings(used_module module)
{

int digital, analog = 0;

//read module name

int eepromval;

 for (int i = 0; i < 32; i++)
 {
   eepromval = ss.EEPROMRead8(i);
   used_module.module_name[i] = (char)eepromval;
 }

//read which pins are used and if they are analog or digital
 digital = ss.EEPROMRead8(124);
 analog = ss.EEPROMRead8(125);

 //convert byte to pins used function


//read device type
 used_module.device_type = ss.EEPROMRead8(126);

//read address of module
 used_module.address = ss.EEPROMRead8(127);

}


byte_to_pins_read(used_module module, int pins, bool digital)
{
        //0, 1, 2, 3,  6,  7, 18, 19
int mask[9] = {1, 2, 4, 8, 16, 32, 64, 128  };
int used_pins[9] = {0, 1, 2, 3, 6, 7, 18, 19  };

if (digital == true)
{

for (int i = 0; i < 8; i++)
{
if ((pins & mask[i]) == mask[i]) {module.pins_digital[i] = used_pins[i]}
}

}


else
{


for (int i = 0; i < 8; i++)
{
if ((pins & mask[i]) == mask[i]) {module.pins_analog[i] = used_pins[i]}
}

}

}



// Seesaw_module_setup(used_module[] module)
// {


// if (int j = 0; j < 8; j++)
// {

// //digital pin setup
// seesaw_module[j].pinmode(used_module.pins_digital[i], INPUT_PULLUP);
// seesaw_module[j].digitalWrite(used_module.pins_digital[i], HIGH);

// //analog pin setup
// seesaw_module[j].pinmode(used_module.pins_analog[i], INPUT_PULLUP);
// seesaw_module[j].digitalWrite(used_module.pins_analog[i], HIGH);

// }

// }


//notes

//If the device uses a joystick but is said to be read as a d-pad, convert analog signals to digital
//If a d-pad is set to a joystick set the values to be max analog value when pushed
//etc etc add to as needed
