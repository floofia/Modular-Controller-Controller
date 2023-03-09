/* SDSMT
   #11ModularGameController
   written by Duncan McGonagle, Sofia Sadun
   Handles functions that edit the ATTiny817 EEPROM
*/
#ifndef MODULE_READ_WRITE_FUNCTIONS_H
#define MODULE_READ_WRITE_FUNCTIONS_H

#include "global_variables.h"


//functions
int string_convert_int();
String string_read();
void all_devices_output();
void all_devices_buffer();
void read_entire_rom(Adafruit_seesaw ss);
void read_device_rom(Adafruit_seesaw ss);
void write_device_rom_sequence(Adafruit_seesaw &ss);
void write_device_address(Adafruit_seesaw &ss);
void write_device_mod_name(Adafruit_seesaw ss);
void write_device_dev_type(Adafruit_seesaw ss);
void write_device_pins(Adafruit_seesaw &ss);
String mod_type(int type);
int mod_type_int(String type);

Adafruit_seesaw ss;

Adafruit_seesaw i2c_outputs[8];

/* Reads string from the user
   Then converts it to an integer
*/
int string_convert_int()
{
  String string;
  char char_array[32];
  int hex;

  while (Serial.available() == 0) {}

  string = Serial.readStringUntil('\n');

  return string.toInt();

}

/* Reads string from the user
*/
String string_read()
{

  String string;
  char char_array[32];
  int hex;

  //Waits for the users input
  while (Serial.available() == 0) {}
  //reads until a null terminator
  string = Serial.readStringUntil('\n');

  return string;

}

/* Initializes i2c connected devices
*/
void all_devices_output()
{
  //redundency check
  i2c_scan();
  //i2c_scan();

  Serial.println("START");


  for (int i = 0; i < nDevices; i++)
  {
    //error checking if i2c device does not start
    if (!i2c_outputs[i].begin(i2c_addresses[i]))
    {
      //Serial.print(nDevices);
      Serial.println("Address 0000, BAD, BAD, BAD");
      //delay(10);
    }

    read_device_rom(i2c_outputs[i]);

  }

  Serial.println("END");
  Serial.println();

}


/* Overwrites values in the i2c_outputts array
*/
void all_devices_buffer()
{
  //redundency check
  i2c_scan();
  i2c_scan();

  for (int i = 0; i < nDevices; i++)
  {
    if (!i2c_outputs[i].begin(i2c_addresses[i]))
    {

    }

  }

}
 


/* Outputs all registers of the EEPROM
   Useful for debugging
*/
void read_entire_rom(Adafruit_seesaw ss)
{
  int i;
  int eepromval;
  //outputs all registers to terminal
  for (i = 0; i < 128; i++)
  {
    Serial.print(F("\nInitial read from register: "));
    eepromval = ss.EEPROMRead8(i);
    Serial.println(eepromval);
  }

}

/* Outputs all used registers of the EEPROM
   Output matches the reading format of the GUI
*/
void read_device_rom(Adafruit_seesaw ss)
{
  char module_name[64];

  int device_type;
  int address, eepromval;
  int pins[15];
  String dev_type;

  int k;
  int i;

  //Serial.print(F("\nName of Device: "));

  for (i = 0; i < 32; i++)
  {
    eepromval = ss.EEPROMRead8(i);
    module_name[i] = (char)eepromval;
  }

  for (int j = 0; j < 15; j++)
  {
  
  pins[j] = ss.EEPROMRead8(70 + j);

  }

  //Serial.print(F("\nDevice Type: "));
  device_type = ss.EEPROMRead8(126);

  if (device_type > 15) {
    dev_type = "Feedback";
  }
  if (device_type % 16 > 0) {
    dev_type = "Input";
  }
  if (device_type == 0) {
    dev_type = "Passive";
  }


/*  "Passive -- 0", 
  "Audio -- 16",
  "Visual -- 32",
  "Haptic -- 48",
  "----------------",
  "Face Buttons -- 1",
  "L Trigger -- 2",
  "R Trigger -- 3",
  "L Joystick -- 4",
  "R Joystick -- 5",
  "D-Pad -- 6", */

int pins_out[7] = {0, 4, 2, 2, 3, 3, 4};

  //Serial.print(F("\nAddress: "));
  address = ss.EEPROMRead8(127);

  //Writing the info to the screen formatted nicely for the
  // GUI and user to read
  //address
  //Serial.print("Address ");
  Serial.print(address);
  Serial.print(";");
  //module name
  Serial.print(module_name);
  Serial.print(";");
  //device type
  //Serial.print(dev_type);
  //Serial.print("; ");
  //device
  Serial.print(mod_type(device_type));
  Serial.print(";");
  //pins
  Serial.print("Pins: ");
  
  for (k = 0; k < pins_out[device_type] - 1; k++)
  {
  Serial.print(pins[k]);
  Serial.print(", ");
  }
  Serial.print(pins[k]);
  Serial.print(";");
  //analog pins
  //Serial.print("Analog ");
  //Serial.print(analog_pins);
  //Serial.print("; ");
  Serial.println();


}





//Address; module_name; dev_type; Digital: 1 2 3 4; Analog: 5 6 7 8;



/* Write sequence for modifying modules
*/
void write_device_rom_sequence(Adafruit_seesaw &ss)
{

  write_device_mod_name(ss);

  write_device_dev_type(ss);

  write_device_pins(ss);

  write_device_address(ss);



  ss.begin();
}

/* Reads and writes register 127.
   This is the register of the device.
   The user is  prompted for an address change
*/
void write_device_address(Adafruit_seesaw &ss)
{
  int address = 50;
  int eepromval = 0;


  Serial.print(F("Initial Device Address: "));
  address = ss.EEPROMRead8(127);
  Serial.print(address);
  Serial.println();
  Serial.println();
  Serial.print(F("Enter new Device Address [[between 10 and 125]]: "));

  eepromval = string_convert_int();

  //make sure address is not too low or too high
  //others issues with reading the device will occur
  if (!(eepromval > 9 && eepromval < 126))
  {
    while (!(eepromval > 9 && eepromval < 126))
    {
      Serial.println();
      Serial.println();
      Serial.print("Enter a value between 10 and 125: ");
      eepromval = string_convert_int();

    }

  }

  ss.EEPROMWrite8(127, eepromval);

  ss.begin(eepromval);
  // Serial.print(F("New Device Address: "));
  // address = ss.EEPROMRead8(127);
  //Serial.print(address);
  Serial.println();
  Serial.println();
  Serial.println();

}


/* Reads and writes register 124 and 125.
   This is the register of the device.
   The user is  prompted for an address change
*/
void write_device_pins(Adafruit_seesaw &ss)
{
  
    int address = 0;
    int eepromval = 0;


Serial.print("Initial Pins: ");

for(int i = 0; i < 15; i++)
{
Serial.print(ss.EEPROMRead8(70 + i));
Serial.print(",");
}

Serial.println();


Serial.println("**Available Pins to use**");
Serial.println("0, 1, 2, 3, 20, 5, 6, 7, 8, 9, 12, 13, 14, 18, 19");
Serial.println("Enter pins individually, stop with -1: ");


int j = 0;
int i =0;

//loop until all 15 pins are entered or eeprom is less than 0
while ((j < 15))
{

eepromval = string_convert_int();

Serial.println(eepromval);

if ((eepromval > -1) && (eepromval < 21))
{
ss.EEPROMWrite8(70 + j, eepromval);
}
else
{
ss.EEPROMWrite8(70 + j, 100);
Serial.println("Invalid Value, setting to 100");
eepromval = -1;
j = 100;
}

j++;

}


Serial.print("Updated Pins: ");

for(i = 0; i < 14; i++)
{
Serial.print(ss.EEPROMRead8(70 + i));
Serial.print(",");
}

Serial.print(ss.EEPROMRead8(70 + i));
Serial.println();

}

/* First 32 registers are read and outputs to
   The screen. This is the name of the device.
   The user is  prompted for a name change
*/
void write_device_mod_name(Adafruit_seesaw ss)
{
  //temp values for writing to the eeprom
  String string;
  char module_name[32];
  int eepromval;
  int i;

  //reads 32 registers of the EEPROM
  //and saves it to a temp variable
  Serial.print("Initial Name of Device: ");
  for (i = 0; i < 32; i++)
  {
    eepromval = ss.EEPROMRead8(i);
    module_name[i] = (char)eepromval;
  }
  //prints name that was read from the EEPROM
  Serial.println(module_name);
  Serial.println();
  //prompts user for a new name
  Serial.print("Enter New Name for Device: ");
  string = string_read();
  Serial.println();
  string.toCharArray(module_name, 32);

  Serial.println();
  Serial.println("!!Writing Name!!");
  //name is written character by character
  //into the registers
  for (i = 0; i < 32; i++)
  {
    ss.EEPROMWrite8(i, module_name[i]);
  }
  Serial.println();
  //rereads what was written to the eeprom
  //so you know it was correct
  Serial.print("New Name of Device: ");
  for (i = 0; i < 32; i++)
  {
    eepromval = ss.EEPROMRead8(i);
    module_name[i] = (char)eepromval;
  }


  Serial.print(module_name);
  Serial.println();
  Serial.println();
  Serial.println();

}


/* A value is read from register 126 of the EEPROM
   This is the device type of the module
   The user is  prompted to change the device type
*/
void write_device_dev_type(Adafruit_seesaw ss)
{
  //temp values that will be written to memory
  int device_type;
  int eepromval;
  //int address;

  //read and return device type
  Serial.print("Initial Device Type: ");
  device_type = ss.EEPROMRead8(126);
  Serial.print(device_type);
  Serial.println();
  Serial.println();

  Serial.println("Device Types: ");

  //return menu stored in globals.h
  for (int i = 0; i < 13; i++) 
  {
    Serial.println(names_dev[i]);
  }

  //read new value from user and write it to the EEPROM
  Serial.print("Enter New Device Types: ");
  eepromval = string_convert_int();
  Serial.println();
  ss.EEPROMWrite8(126, eepromval);
  Serial.println();


}

//void write_device_pins(Adafruit_seesaw ss)
//{
//
//  int address = 50;
//  int eepromval = 0;
//
//  Serial.print(F("Initial Device Address: "));
//  address = ss.EEPROMRead8(127);
//  Serial.print(address);
//  Serial.println();
//  Serial.println();
//  Serial.print(F("Enter new Device Address [[between 25 and 125]]: "));
//
//  eepromval = string_convert_int();
//
//  //make sure address is not too low or too high
//  //others issues with reading the device will occur
//  if (!(eepromval > 25 && eepromval < 125))
//  {
//    while (!(eepromval > 25 && eepromval < 125))
//    {
//    Serial.println();
//    Serial.println();
//    Serial.print("Enter a value between 25 and 125: ");
//    eepromval = string_convert_int();
//
//    }
//
//  }
//
//  ss.EEPROMWrite8(127, eepromval);
//
//  ss.begin(eepromval);
// // Serial.print(F("New Device Address: "));
// // address = ss.EEPROMRead8(127);
//  //Serial.print(address);
//  Serial.println();
//  Serial.println();
//  Serial.println();
//}
//
//void read_device_pins(Adafruit_seesaw ss)
//{
//
// int address = 124;
//
//
//
//}


//pins
//1111 1111
///ADC pins 0, 1, 2, 3, 6, 7, 18, 19, 20


//upper 4 of byte
//19, 18, 7, 6
//lower 4 of byte
//3, 2, 1, 0
//full byte: 19, 18, 7, 6, 3, 2, 1, 0


//an example of 0, 2, 7, 19, pins being used would be
//1010 0101
//this is written to register 124 as digital
//register 125 will be used for analog

//let's say we want to wire up a standard joystick 2-axis 1-push-button
//by default let's do this


//used pins:
//digital, register 124:  0000 0100
//analog, register 125:   0000 0011


/* Value stored in register 126 is read
   The value determines the device type
*/
String mod_type(int type)
{

  String dev_type;

  switch (type) {
    case 0b00000000:
      dev_type = "Passive";
      break;
    case 0b00010000:
      dev_type = "Audio";
      break;
    case 0b00100000:
      dev_type = "Visual_Feedback";
      break;
    case 0b00110000:
      dev_type = "Haptic";
      break;
    case 0b00000001:
      dev_type = "Face Buttons";
      break;
    case 0b00000010:
      dev_type = "L Trigger";
      break;
    case 0b00000011:
      dev_type = "R Trigger";
      break;
    case 0b00000100:
      dev_type = "L Joystick";
      break;
    case 0b00000101:
      dev_type = "R Joystick";
      break;
     case 0b00000110:
      dev_type = "D-Pad";
      break;
    default:
      dev_type = "default";
      break;
  }

  return dev_type;
}

 /* "Passive -- 0", 
  "Audio -- 16",
  "Visual -- 32",
  "Haptic -- 48",\
  "----------------",
  "Face Buttons -- 1",
  "L Trigger -- 2",
  "R Trigger -- 3",
  "L Joystick -- 4",
  "R Joystick -- 5",
  "D-Pad -- 6", */



int mod_type_int(String type)
{

  int dev_type;


  if (type == "Passive") {
    dev_type = 0b00000000;
  }

  else if (type == "Audio") {
    dev_type = 0b00010000;
  }

  else if (type == "Visual_Feedback") {
    dev_type = 0b00100000;
  }


  else if (type == "Haptic") {
    dev_type = 0b00110000;
  }


  else if (type == "Face Buttons") {
    dev_type = 0b00000001;
  }


  else if (type == "L Trigger") {
    dev_type = 0b00000010;
  }


  else if (type == "R Trigger") {
    dev_type = 0b00000011;
  }


  else if (type == "L Joystick") {
    dev_type = 0b00000100;
  }


  else if (type == "R Joystick") {
    dev_type = 0b00000101;
  }

  
  else if (type == "D-Pad") {
    dev_type = 0b00000110;
  }

  else {
    dev_type = 0b00000000;
  }


return dev_type;

}


#endif
