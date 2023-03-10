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

#include <BleGamepad.h>



BleGamepad gamepad;

void faceButtonSetup (int top, int bottom, int left, int right, int address,
                      Adafruit_seesaw ss);
void faceButtonRead (int top, int bottom, int left, int right, bool &button,
                     Adafruit_seesaw ss);

void dpadRead (int up, int down, int left, int right, bool button,
               Adafruit_seesaw ss);


void dpadSetup (int up, int down, int left, int right, char address,
                Adafruit_seesaw ss);




void Controller_Programming_Mode()
{

  int attiny_device;
  int gui_select_device;
  int selection;

  used_module module[8];

  while (1)
  {

    do
    {
      do {
        Serial.println();
        i2c_scan();

        //ssa.begin(i2c_addresses[0]);

       

        all_devices_buffer();
        
       
       
        all_devices_output();

        for (int i = 0; i < nDevices; i++)
        {

          Seesaw_read_settings(module[i], i2c_outputs[i]);

        }


        Serial.println();
        Serial.println("Enter Value of the i2c device you'd like to edit--");
        Serial.println("Or enter -1 for GUI interface: ");
        Serial.println("Or enter 200 for refresh: ");

        attiny_device = string_convert_int();

      } while (attiny_device == 200); //if entered value is 200 refresh list

      if (attiny_device == -1)
      {
        do
        {

          Serial.println("Enter Value of the i2c device you'd like to edit: ");
          gui_select_device = string_convert_int();
        } while (!ss.begin(gui_select_device));



      }


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

    if (attiny_device != -1)
    {
      //menu for users to see which option they want
      do {
        selection = 0;
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
        case 1:
          //read_entire_rom(ss);
          read_device_rom(ss);
          Serial.println();
          break;
        case 2:
          write_device_rom_sequence(ss);
          break;
        case 3:

          for (int i = 0; i < nDevices; i++)
          {
            Seesaw_Struct_Name(module[i]);
          }

          break;

        case 4:

      
          gamepad.begin();

          bool button;
          

      
          dpadSetup(module[0].pins[0], module[0].pins[1], module[0].pins[2], module[0].pins[3], 10, i2c_outputs[0]);
          faceButtonSetup(module[1].pins[0], module[1].pins[1], module[1].pins[2], module[1].pins[3], 10, i2c_outputs[1]);
       

          while (1)
          {


            dpadRead(module[0].pins[0], module[0].pins[1], module[0].pins[2], module[0].pins[3], button, i2c_outputs[0]);
            faceButtonRead(module[1].pins[0], module[1].pins[1], module[1].pins[2], module[1].pins[3], button, i2c_outputs[1]);


           //read_all()
          }

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



void setup_all(struct used_module &module[], Adafruit_seesaw ss[])
{

for (int i = 0; i < nDevices; i++)
{

  if (module.address > 9 && module.address < 20)
  {
    faceButtonSetup(module.pins[0], module.pins[1], module.pins[2], module.pins[3], 10, i2c_outputs[1]);
  }
  if (module.address > 19 && module.address < 30)
  {
    dpadSetup(module.pins[0], module.pins[1], module.pins[2], module.pins[3], 10, i2c_outputs[0]);
  }

}

}

//void read_all(struct used_module &module[], Adafruit_seesaw i2c_outputs[])
//{
//
//
//
//}



















void faceButtonSetup (int top, int bottom, int left, int right, int address,
                      Adafruit_seesaw ss)
{
  ss.pinMode(top, INPUT_PULLUP);
  ss.pinMode(bottom, INPUT_PULLUP);
  ss.pinMode(left, INPUT_PULLUP);
  ss.pinMode(right, INPUT_PULLUP);

}



void faceButtonRead (int top, int bottom, int left, int right, bool & button,
                     Adafruit_seesaw ss)
{
  button = false;

  //process the top button input
  if (ss.digitalRead(top) == LOW)
  {
    gamepad.press(BUTTON_4);
    Serial.println("Button 4");
    button = true;
  }
  else
  {
    gamepad.release(BUTTON_4);
  }

  //process bottom button input
  if (ss.digitalRead(bottom) == LOW)
  {
    gamepad.press(BUTTON_1);
    Serial.println("Button 1");
    button = true;
  }
  else
  {
    gamepad.release(BUTTON_1);
  }

  //process left button input
  if (ss.digitalRead(left) == LOW)
  {
    gamepad.press(BUTTON_3);
    Serial.println("Button 3");
    button = true;
  }
  else
  {
    gamepad.release(BUTTON_3);
  }

  //process right button input
  if (ss.digitalRead(right) == LOW)
  {
    gamepad.press(BUTTON_2);
    Serial.println("Button 2");
    button = true;
  }
  else
  {
    gamepad.release(BUTTON_2);
  }
}




void dpadRead (int up, int down, int left, int right, bool button,
               Adafruit_seesaw ss)
{
  //THIS MODULE IS LIKELY TO BE FULLY MESSED UP BY WRONG BUTTON MAPPING
  //It depends on if the other triggers are included in the button mapping
  button = false;

  //process the up button input
  if (ss.digitalRead(up) == LOW)
  {
    gamepad.press(BUTTON_13);
    Serial.println("Button_13");
    button = true;
  }
  else
  {
    gamepad.release(BUTTON_13);
  }

  //process down button input
  if (ss.digitalRead(down) == LOW)
  {
    gamepad.press(BUTTON_14);
    Serial.println("Button_14");
    button = true;
  }
  else
  {
    gamepad.release(BUTTON_14);
  }

  //process left button input
  if (ss.digitalRead(left) == LOW)
  {
    gamepad.press(BUTTON_15);
    Serial.println("Button_15");
    button = true;
  }
  else
  {
    gamepad.release(BUTTON_15);
  }

  //process right button input
  if (ss.digitalRead(right) == LOW)
  {
    gamepad.press(BUTTON_16);
    Serial.println("Button_16");
    button = true;
  }
  else
  {
    gamepad.release(BUTTON_16);
  }
}



void dpadSetup (int up, int down, int left, int right, char address,
                Adafruit_seesaw ss)
{
  ss.pinMode(up, INPUT_PULLUP);
  ss.pinMode(down, INPUT_PULLUP);
  ss.pinMode(left, INPUT_PULLUP);
  ss.pinMode(right, INPUT_PULLUP);
}






#endif
