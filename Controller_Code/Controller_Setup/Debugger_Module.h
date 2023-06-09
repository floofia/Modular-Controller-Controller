/******************************************************************************
* Written by: Sofia Sadun, Erin Green
* Edited by: Sofia Sadun, Erin Green
* Commented by: Sofia Sadun
* Last Updated: 3/30/2023
* 
* DESCRIPTION: This is an example for how to make a new module for the 
*              controller. With the bonus of using embedded C 
******************************************************************************/


#ifndef DEBUGGER_MODULE_H_
#define DEBUGGER_MODULE_H_
#include <Adafruit_seesaw.h>

// DEFINING FUNCTIONS
void debuggerSetup(int r, int g, int b, Adafruit_seesaw ss);
void debuggerWrite(int r, int g, int b, Adafruit_seesaw ss);
int  check_modules();



/// @brief This function sets up the debugger function
/// @param r - the pin number of the pwm pin that’ll run the Red part of the LED
/// @param g - the pin number of the pwm pin that’ll run the Green part of the LED
/// @param b - the pin number of the pwm pin that’ll run the Blue part of the LED
/// @param ss - the seesaw in use
/// default pins are:r = 9, g = 13, b = 12
void debuggerSetup(int r, int g, int b, Adafruit_seesaw ss)
{
  // r = 9;
  // g = 13;
  // b = 12;
  ss.pinMode(r, OUTPUT);
  ss.pinMode(g, OUTPUT);
  ss.pinMode(b, OUTPUT);
}




/// @brief This function reads if any of the buttons are in use and will
///        output colors to the LED accordingly
/// @param r - the pin number of the pwm pin that’ll run the Red part of the LED
/// @param g - the pin number of the pwm pin that’ll run the Green part of the LED
/// @param b - the pin number of the pwm pin that’ll run the Blue part of the LED
/// @param ss - the seesaw in use
void debuggerWrite(int r, int g, int b, Adafruit_seesaw ss)
{
  // r = 9;
  // g = 13;
  // b = 12;

  //we aren't taking into account the parameters due to time constraints
  int mode = check_modules();

  // Process the output from the variables
    if ( mode == 1)
    {
        // print red
        // 255, 0, 0
        ss.analogWrite(r, 255);
        ss.analogWrite(g, 0);
        ss.analogWrite(b, 0);

    }
    else if ( mode == 2)
    {
        // print green
        // 0, 255, 0
        
        ss.analogWrite(g, 255);
        ss.analogWrite(r, 0);
        ss.analogWrite(b, 0);

    }
    else if ( mode == 3)
    {
        // print blue
        // 0, 0, 255
        
        ss.analogWrite(b, 255);
        ss.analogWrite(r, 0);
        ss.analogWrite(g, 0);


    }
    else if ( mode == 4)
    {
        // print white
        // 255, 255, 255
      
        ss.analogWrite(r, 255);
        ss.analogWrite(g, 255);
        ss.analogWrite(b, 255);

    }
    else 
    {
        // print black
        // 0, 0, 0
        
        ss.analogWrite(r, 10);
        ss.analogWrite(g, 10);
        ss.analogWrite(b, 10);

        
    }
}



/// @brief This function reads the values of all the modules and tells 
///        which are in use via an integer
/// @return 0 = none | 1 = joystick | 2 = buttons | 3 = trigger
///         4 = multiple
int check_modules()
{
  int modules = 0; // 0 = none | 1 = joystick | 2 = buttons | 3 = trigger
  // 4 = multiple
  bool trigger_pressed = false;
  bool button_pressed = false;
  bool joystick_pressed = false;

  // check trigger inputs
  trigger_pressed |= gamepad.isPressed (BUTTON_5);
  trigger_pressed |= gamepad.isPressed (BUTTON_7);
  trigger_pressed |= gamepad.isPressed (BUTTON_6);
  trigger_pressed |= gamepad.isPressed (BUTTON_8);

  // check joystick inputs
  joystick_pressed |= gamepad.isPressed (BUTTON_11);
  joystick_pressed |= gamepad.isPressed (BUTTON_12);
  //if (gamepad._x == 0 && gamepad._y == 0 && gamepad._z == 0 && gamepad._rZ == 0)
  //{
  //  joystick_pressed = true;
  //}

  // check dpad and face buttons
  button_pressed |= gamepad.isPressed (BUTTON_4);
  button_pressed |= gamepad.isPressed (BUTTON_1);
  button_pressed |= gamepad.isPressed (BUTTON_3);
  button_pressed |= gamepad.isPressed (BUTTON_2);
  button_pressed |= gamepad.isPressed (BUTTON_13);
  button_pressed |= gamepad.isPressed (BUTTON_14);
  button_pressed |= gamepad.isPressed (BUTTON_15);
  button_pressed |= gamepad.isPressed (BUTTON_16);

  //if multiple inputs pressed
  if ( (button_pressed && trigger_pressed)  || 
       (button_pressed && joystick_pressed) || 
       (joystick_pressed && trigger_pressed)  )
    {
       return 4; // multiple in use
    }
  else if ((button_pressed || trigger_pressed || joystick_pressed) == 0)
    {
        return 0; // no modules
    }
  else if (joystick_pressed)
    {
        return 1; // joystick
    }    
  else if (trigger_pressed)
    {
        return 3; // trigger
    }
  else if (button_pressed)
    {
        return 2; // buttons
    }
  return 0; // shouldn't reach here.
}


#endif