/* SDSMT
   #11ModularGameController
   written by Duncan McGonagle
   File with Global Variables to be used by multiple files
*/

#ifndef CONTROLLER_SETUP_H
#define CONTROLLER_SETUP_H

#include "Global_Variables.h"
#include "Adafruit_seesaw.h"
#include "serial_setup.h"
#include "i2c_scan.h"
#include "Module_Read_Write_Functions.h"
#include "gui_interface.h"
#include "Module_Initialization.h"


void Controller_Programming_Mode()
{


  int attiny_device;
  int gui_select_device;
  int selection;

  used_module module;

  while (1)
  {

    do
    {
      Serial.println();
      i2c_scan();

      ss.begin(i2c_addresses[0]);

      all_devices_buffer();
      all_devices_output();

      Serial.println();
      Serial.println("Enter Value of the i2c device you'd like to edit--");
      Serial.println("Or enter -1 for GUI interface: ");

      attiny_device = string_convert_int();

      if (attiny_device == -1)
      {
        do
        {

          Serial.println("Enter Value of the i2c device you'd like to edit: ");
          gui_select_device = string_convert_int();
        } while (!ss.begin(gui_select_device));

        gui_setup (ss);

      }


      if (attiny_device != -1)
      {

        //Serial.println(attiny_device);
        Serial.println();
        Serial.println();

        //check to see if the address entered was valid
        if (!ss.begin(attiny_device))
        {
          Serial.println(F("seesaw failed to start"));
          Serial.println();
          all_devices_output();
        }
      }

      

    } while (!ss.begin(attiny_device) && !ss.begin(gui_select_device));

    if (attiny_device != -1)
    {
      //menu for users to see which option they want
      do {
        selection = 0;
        Serial.println("READ MODULE       [1]");
        Serial.println("Write MODULE      [2]");
        Serial.println("Struct Test       [3]");
        Serial.println();
        Serial.print("Selection: ");
        //reads selection from user
        selection = string_convert_int();
        Serial.println();
        Serial.println();

      } while ((selection != 1) && (selection != 2) && (selection != 3));

      switch (selection) {
        case 1:
          //read_entire_rom(ss);
          read_device_rom(ss);
          Serial.println();
          break;
        case 2:
          write_device_rom_sequence(ss);
          break;
        case 3:

          Seesaw_read_settings(module, ss);
          Seesaw_Struct_Name(module);

          break;

        default:
          Serial.print("You shouldn't be here");
          break;
      }

    }


    i2c_scan();
    delay(1000);

  }

}

void Controller_Game_Mode()
{

Serial.println("GAME_MODE");

delay(100);

}
























#endif
