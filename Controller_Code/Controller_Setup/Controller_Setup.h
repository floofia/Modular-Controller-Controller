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
#include "modulefunctiondefinitions.h"

#include <BleGamepad.h>


void Controller_Input();
void Controller_address_setup();


// this declares a class that is called gamepad.
// all of our calls to send game inputs will start with "gamepad"
//eg. gamepad.press(BUTTON_1)
BleGamepad gamepad;

used_module module[8];

/// @brief This function is the basis of the programming mode. this mode lets
///        you modify various aspects of the controller.
void Controller_Programming_Mode()
{

  int attiny_device;
  int gui_select_device;
  int selection;



  while (1)
  {

    do
    {
      do {
        Serial.println();
        gamepad.begin();

        //ssa.begin(i2c_addresses[0]);
        
        nDevices = 0;

        all_devices_output();

        // pull the information for all devices
        for (int i = 0; i < nDevices; i++)
        {

          Seesaw_read_settings(module[i], i2c_outputs[i]);

        }

        //print menu
        Serial.println();
        Serial.println("Enter Value of the i2c device you'd like to edit--");
        Serial.println("Or enter -1 for GUI interface: ");
        Serial.println("Or enter 200 for refresh: ");


        attiny_device = string_convert_int();

      } while (attiny_device == 200); //if entered value is 200 refresh list

      if (attiny_device == -1) // gui is interfacing
      {

        do
        {

          Serial.println("Enter Value of the i2c device you'd like to edit: ");


          gui_select_device = string_convert_int();

          if (ss.begin(gui_select_device))
          {
            gui_setup(ss);
          }

          ss.begin(gui_select_device);

        } while (!ss.begin(gui_select_device));



      }

      // if not using the gui interface
      if (attiny_device != -1)
      {

        //Serial.println(attiny_device);
        Serial.println();
        Serial.println();

        //check to see if the address entered was valid
        if (!ss.begin(attiny_device))
        {
          Serial.println("seesaw failed to start");
          Serial.println();
          all_devices_output();
        }
      }


    } while (!ss.begin(attiny_device) && !ss.begin(gui_select_device));

    //if not using gui interface
    if (attiny_device != -1)
    {
      //menu for users to see which option they want
      //repeats until a valid input is given.
      do {
        selection = 0;

        // prints a menu
        Serial.println("READ MODULE       [1]");
        Serial.println("Write MODULE      [2]");
        Serial.println("Struct Test       [3]");
        Serial.println("Controls Test     [4]");
        Serial.println();
        Serial.print("Selection: ");

        //reads selection from user
        selection = string_convert_int();
        Serial.println();
        Serial.println();

      } while ((selection != 1) && (selection != 2) && (selection != 3) && (selection != 4));

      switch (selection) {
        // if selection is to read module
        case 1:
          //read_entire_rom(ss);
          read_device_rom(ss);
          Serial.println();
          break;

        // if selection is to write to a module
        case 2:
          write_device_rom_sequence(ss);
          break;

        // if the selection is to do a struct test
        case 3:

          for (int i = 0; i < nDevices; i++)
          {
            Seesaw_Struct_Name(module[i]);
          }

          break;

        // if the selection is to test controls
        case 4:

          // initialize gamepad

          Controller_address_setup();



          //forever run input processing
          while (1)
          {
            Controller_Input();
          }

          break;

        // this shouldn't ever happen
        default:
          Serial.print("You shouldn't be here");
          break;
      }

    }

    i2c_scan();
    delay(1000);

  }

}

/// @brief This is the game mode function. While this is true, the controller
///        should just run as a normal controller. "GAME_MODE" is printed
///        via serial for clarification to any people reading the serial output
void Controller_Game_Mode()
{

  Serial.println("GAME_MODE");

  delay(100);


}



/// @brief This function processes all the inputs. There should be
void Controller_Input()
{
  bool button = false;

  for (int i = 0; i < nDevices; i++)
  {
    //face_button read
    if (module[i].address > 9 && module[i].address < 20)
    {
      faceButtonRead (module[i].pins[0], module[i].pins[1], module[i].pins[2], module[i].pins[3], i2c_outputs[i]);

    }
    //L Trigger read
    else if (module[i].address > 19 && module[i].address < 30)
    {
      lTriggerRead ( module[i].pins[0], module[i].pins[1], i2c_outputs[i]);

    }
    //R Trigger Setup
    else if (module[i].address > 29 && module[i].address < 40)
    {
      rTriggerRead ( module[i].pins[0], module[i].pins[1], i2c_outputs[i]);

    }
    //L Joystick read
    else if (module[i].address > 39 && module[i].address < 50)
    {
      lJoystickRead(module[i].pins[0], module[i].pins[1], module[i].pins[2], i2c_outputs[i]);

    }
    //R Joystick read
    else if (module[i].address > 49 && module[i].address < 60)
    {
      rJoystickRead(module[i].pins[0], module[i].pins[1], module[i].pins[2], i2c_outputs[i]);

    }
    //D-Pad read
    else if (module[i].address > 59 && module[i].address < 70)
    {
      dpadRead(module[i].pins[0], module[i].pins[1], module[i].pins[2], module[i].pins[3], i2c_outputs[i]);
    }
    //if out of bounds
    else
    {


    }

  }

}


/// @brief this function runs the initialization functions
void Controller_address_setup()
{

  for (int i = 0; i < nDevices; i++)
  {
    bool button;
    //face_button setup
    if (module[i].address > 9 && module[i].address < 20)
    {
      faceButtonSetup (module[i].pins[0], module[i].pins[1], module[i].pins[2], module[i].pins[3], i2c_outputs[i]);

    }
    //L Trigger Setup
    else if (module[i].address > 19 && module[i].address < 30)
    {
      lTriggerSetup ( module[i].pins[0], module[i].pins[1], i2c_outputs[i]);

    }
    //R Trigger Setup
    else if (module[i].address > 29 && module[i].address < 40)
    {
      rTriggerSetup ( module[i].pins[0], module[i].pins[1], i2c_outputs[i]);

    }
    //L Joystick Setup
    else if (module[i].address > 39 && module[i].address < 50)
    {
      lJoystickSetup(module[i].pins[0], module[i].pins[1], module[i].pins[2], i2c_outputs[i]);

    }
    //R Joystick Setup
    else if (module[i].address > 49 && module[i].address < 60)
    {
      rJoystickSetup(module[i].pins[0], module[i].pins[1], module[i].pins[2], i2c_outputs[i]);

    }
    //D-Pad Setup
    else if (module[i].address > 59 && module[i].address < 70)
    {
      dpadSetup(module[i].pins[0], module[i].pins[1], module[i].pins[2], module[i].pins[3], i2c_outputs[i]);

    }
    //if out of bounds
    else
    {


    }

  }

}


#endif
