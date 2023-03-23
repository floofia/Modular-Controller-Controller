/******************************************************************************
* Written by: Sofia Sadun
* Edited by: Duncan McGonagle
* Commented by: Sofia Sadun
* Last Updated: 3/22/2023
* Using the BLEGamepad library
******************************************************************************/


#ifndef MODULEFUNCDEFINITIONS_H_
#define MODULEFUNCDEFINITIONS_H_
#include "modulefuncheader.h"




/////////////////////////
////*****************////
////*SETUP FUNCIONS**////
////*****************////
/////////////////////////

bool button;
bool joystick;

/// @brief This function sets up and defines the pins of the seesaw
/// @param top - the top face button
/// @param bottom - the bottom face button (usually the select button)
/// @param left - the left face button
/// @param right - the right face button (usually the decline button)
/// @param ss - the seesaw in question
void faceButtonSetup (int top, int bottom, int left, int right,
                      Adafruit_seesaw ss)
{
  //sets all the pins (as given) as inputs
  ss.pinMode(top, INPUT_PULLUP);
  ss.pinMode(bottom, INPUT_PULLUP);
  ss.pinMode(left, INPUT_PULLUP);
  ss.pinMode(right, INPUT_PULLUP);

}


/// @brief This function sets up and defines the pins of the seesaw for a d-pad
///        module
/// @param up - the top button pin (used to navigate up)
/// @param down - the bottom button pin (used to navigate down)
/// @param left - the left button pin (used to navigate lefy)
/// @param right - the right button pin (used to navigate right)
/// @param ss - the seesaw in question
void dpadSetup (int up, int down, int left, int right, Adafruit_seesaw ss)
{
  //sets all the pins (as given) as inputs
  ss.pinMode(up, INPUT_PULLUP);
  ss.pinMode(down, INPUT_PULLUP);
  ss.pinMode(left, INPUT_PULLUP);
  ss.pinMode(right, INPUT_PULLUP);
}

/// @brief This function sets up and defines the pins of the see saw for a
///        joystick module (the camera joystick which usually is on the right
///        side of the controller)
/// @param x - x input pin (left and right movement)
/// @param y - y input pin (up and down movement)
/// @param select - joystick button press pin (joystick is pressed in)
/// @param ss - the seesaw in question
void rJoystickSetup(int x, int y, int select, Adafruit_seesaw ss)
{
  //sets all the pins (as given) as inputs
  ss.pinMode(x, INPUT_PULLUP);
  ss.pinMode(y, INPUT_PULLUP);
  ss.pinMode(select, INPUT_PULLUP);
}

/// @brief This function sets up and defines the pins of the see saw for a
///        joystick module (the movement joystick which usually is on the left
///        side of the controller)
/// @param x - x input pin (left and right movement)
/// @param y - y input pin (up and down movement)
/// @param select - joystick button press pin (joystick is pressed in)
/// @param ss - the seesaw in question
void lJoystickSetup(int x, int y, int select, Adafruit_seesaw ss)
{
  //sets all the pins (as given) as inputs
  ss.pinMode(x, INPUT_PULLUP);
  ss.pinMode(y, INPUT_PULLUP);
  ss.pinMode(select, INPUT_PULLUP);

}

/// @brief This is a function that sets up the left trigger
/// @param top - top button's input pin
/// @param bottom - bottom button's input pin
/// @param ss the seesw itself
void lTriggerSetup ( int top, int bottom, Adafruit_seesaw ss )
{
  //sets all the pins (as given) as inputs
  ss.pinMode(top, INPUT_PULLUP);
  ss.pinMode(bottom, INPUT_PULLUP);

}

/// @brief this is a function that sets up the right trigger
/// @param top - top button's input pin
/// @param bottom - bottom button's input pin
/// @param ss the seesw itself
void rTriggerSetup ( int top, int bottom, Adafruit_seesaw ss )
{
  //sets all the pins (as given) as inputs
  ss.pinMode(top, INPUT_PULLUP);
  ss.pinMode(bottom, INPUT_PULLUP);
}

///////////////////////
////***************////
////*USE FUNCIONS**////
////***************////
///////////////////////

////////////////////////////
/*********BUTTONS**********/
////////////////////////////

/// @brief This function uses the input pins and uses them to read input and
///        translate that into functional face button inputs
/// @param top - the top face button pin#
/// @param bottom - the bottom face button pin# (usually the select button)
/// @param left - the left face button pin #
/// @param right - the right face button pin # (usually the decline button)
/// @param ss - the seesaw in question
void faceButtonRead (int top, int bottom, int left, int right,
                     Adafruit_seesaw ss)
{
  
  //process the top button input
  if (ss.digitalRead(top) == LOW)
  {
    // Xbox Y button
    gamepad.press(BUTTON_4);
    Serial.println("Button_4");
  }
  else
  {
    gamepad.release(BUTTON_4);
  }

  //process bottom button input
  if (ss.digitalRead(bottom) == LOW)
  {
    //Xbox A button
    gamepad.press(BUTTON_1);
    Serial.println("Button_1");
  }
  else
  {
    gamepad.release(BUTTON_1);
  }

  //process left button input
  if (ss.digitalRead(left) == LOW)
  {
    //Xbox X button
    gamepad.press(BUTTON_3);
    Serial.println("Button_3");
  }
  else
  {
    gamepad.release(BUTTON_3);
  }

  //process right button input
  if (ss.digitalRead(right) == LOW)
  {
    //Xbox B button
    gamepad.press(BUTTON_2);
    Serial.println("Button_2");
  }
  else
  {
    gamepad.release(BUTTON_2);
  }
}


/// @brief This function uses the input pins and uses them to read input and
///        translate that into functional face button inputs
/// @param up - the up  button pin#
/// @param down - the down button pin# (usually the select button)
/// @param left - the left button pin #
/// @param right - the right button pin # (usually the decline button)
/// @param ss - the seesaw in question
void dpadRead (int up, int down, int left, int right, Adafruit_seesaw ss)
{
  //THIS MODULE IS LIKELY TO BE FULLY MESSED UP BY WRONG BUTTON MAPPING
  //It depends on if the other triggers are included in the button mapping


  //process the up button input
  if (ss.digitalRead(up) == LOW)
  {
    //up press
    gamepad.press(BUTTON_13);
    Serial.println("Button_13");
  }
  else
  {
    gamepad.release(BUTTON_13);
  }

  //process down button input
  if (ss.digitalRead(down) == LOW)
  {
    //down press
    gamepad.press(BUTTON_14);
    Serial.println("Button_14");
  }
  else
  {
    gamepad.release(BUTTON_14);
  }

  //process left button input
  if (ss.digitalRead(left) == LOW)
  {
    //left press
    gamepad.press(BUTTON_15);
    Serial.println("Button_15"); 
  }
  else
  {
    gamepad.release(BUTTON_15);
  }

  //process right button input
  if (ss.digitalRead(right) == LOW)
  {
    //right press
    gamepad.press(BUTTON_16);
    Serial.println("Button_16");
  }
  else
  {
    gamepad.release(BUTTON_16);
  }
}

/////////////////////////////
/*********JOYSTICK**********/
/////////////////////////////

/// @brief This function uses the input pins and uses them to read input and
///        translate that into functional joystick inputs (the camera stick)
/// @param x - the pin# for the x axis
/// @param y - the pin# for the y axis
/// @param select - the pin# for the button underneath the joystick
/// @param ss - the seesaw in question
void rJoystickRead(int x, int y, int select, Adafruit_seesaw ss)
{

  int dx;
  int dy;
  int xx, yy;

  // read from x and y to xx and yy
  xx = ss.analogRead(x);
  yy = ss.analogRead(y);

  // map xx and yy to the proper ranges to dx and dy
  dx = map(xx, 0, 1023, 0, 32767);
  dy = map(yy, 0, 1023, 0, 32767);

  //put the data in the gamepad
  gamepad.setRightThumb(dx, dy);// right-x and right-y

  //read button press
  if (ss.digitalRead(select) == HIGH)
  {
    //R3 input
    gamepad.press(BUTTON_12);
    Serial.println("Button_12");
  }
  else
  {
    gamepad.release(BUTTON_12);
  }

}

/// @brief This function uses the input pins and uses them to read input and
///        translate that into functional joystick inputs (the movement stick)
/// @param x - the pin# for the x axis
/// @param y - the pin# for the y axis
/// @param select - the pin# for the button underneath the joystick
/// @param ss - the seesaw in question
void lJoystickRead(int x, int y, int select, Adafruit_seesaw ss)
{
  int dx;
  int dy;
  int xx, yy;

  // read from x and y to xx and yy
  xx = ss.analogRead(x);
  yy = ss.analogRead(y);

  // map xx and yy to the proper ranges to dx and dy
  dx = map(xx, 0, 1023, 0, 32767);
  dy = map(yy, 0, 1023, 0, 32767);


  //put the data in the gamepad
  gamepad.setLeftThumb(dx, dy); //left-x and left-y

  //read button press
  if (ss.digitalRead(select) == HIGH)
  {
    // L3 input
    gamepad.press(BUTTON_11);
    Serial.println("Button_11");
  }
  else
  {
    gamepad.release(BUTTON_11);
  }
}

/////////////////////////////
/*********TRIGGERS**********/
/////////////////////////////

/// @brief This function uses the input pins and uses them to read input and
///        translate that into functional trigger button inputs
/// @param top - the top button pin#
/// @param bottom - the bottom button pin#
/// @param ss - the seesaw in question
void lTriggerRead ( int top, int bottom, Adafruit_seesaw ss )
{
  //read top trigger button press
  if (ss.digitalRead(top) == LOW)
  {
    //L1 input
    gamepad.press(BUTTON_5);
    Serial.println("Button_5");
  }
  else
  {
    gamepad.release(BUTTON_5);
  }
  
  //read bottom button press
  if (ss.digitalRead(bottom) == LOW)
  {
    //L2 input
    gamepad.press(BUTTON_7);
    Serial.println("Button_7");
  }
  else
  {
    gamepad.release(BUTTON_7);
  }

}

/// @brief This function uses the input pins and uses them to read input and
///        translate that into functional trigger button inputs
/// @param top - the top button pin#
/// @param bottom - the bottom button pin#
/// @param ss - the seesaw in question
void rTriggerRead ( int top, int bottom, Adafruit_seesaw ss )
{

  // read top button
  if (ss.digitalRead(top) == LOW)
  {
    //R1 input
    gamepad.press(BUTTON_6);
    Serial.println("Button_6");

  }
  else
  {
    gamepad.release(BUTTON_6);
    
  }

  // read bottom button
  if (ss.digitalRead(bottom) == LOW)
  {
    //R2 input
    gamepad.press(BUTTON_8);
    Serial.println("Button_8");

  }
  else
  {
    gamepad.release(BUTTON_8);
  }

}




/// @brief This function reads if any of the buttons are in use and will
///        output colors to the LED accordingly
/// @param output - the pin number of the pwm pin that’ll run the RGB LED
/// @param ss - the seesaw in 
void debuggerWrite(int output, Adafruit_seesaw ss)
{
  //DDR
  int module = check_modules();
  //0 = none | 1 = joystick | 2 = buttons | 3 = trigger 4 = multiple
  
  // Process the output from the variables
  // if multiple output white
  // if joystick output red
  // if buttons output green
  // if trigger output blue
  // if none do not output to LED
  //if (module == 0)
  //ss.analogWrite(output, )

  //portb 2 is our analog output
  // standard is pin 9








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
  trigger_pressed |= gamepad.isPressed (BUTTON_4);

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
