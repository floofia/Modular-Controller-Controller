#ifndef MODULEFUNCDEFINITIONS_H_
#define MODULEFUNCDEFINITIONS_H_

#include "modulefuncheader.h"

/////////////////////////
////*****************////
////*SETUP FUNCIONS**////
////*****************////
/////////////////////////

/// @brief This function sets up and defines the pins of the seesaw
/// @param top - the top face button
/// @param bottom - the bottom face button (usually the select button)
/// @param left - the left face button
/// @param right - the right face button (usually the decline button)
/// @param ss - the seesaw in question
void faceButtonSetup (int top, int bottom, int left, int right, 
                      Adafruit_seesaw ss)
{
    ss.pinMode(top, INPUT);
    ss.pinMode(bottom, INPUT);
    ss.pinMode(left, INPUT);
    ss.pinMode(right, INPUT);

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
    ss.pinMode(up, INPUT);
    ss.pinMode(down, INPUT);
    ss.pinMode(left, INPUT);
    ss.pinMode(right, INPUT);
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
    ss.pinMode(x, INPUT);
    ss.pinMode(y, INPUT);
    ss.pinMode(select, INPUT);
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
    ss.pinMode(x, INPUT);
    ss.pinMode(y, INPUT);
    ss.pinMode(select, INPUT);

}

/// @brief This is a function that sets up the left trigger
/// @param top - top button's input pin
/// @param bottom - bottom button's input pin
/// @param ss the seesw itself
void lTriggerSetup ( int top, int bottom, Adafruit_seesaw ss )
{
    ss.pinMode(top, INPUT);
    ss.pinMode(bottom, INPUT);
 
}

/// @brief this is a function that sets up the right trigger
/// @param top - top button's input pin
/// @param bottom - bottom button's input pin
/// @param ss the seesw itself
void rTriggerSetup ( int top, int bottom, Adafruit_seesaw ss )
{
    ss.pinMode(top, INPUT);
    ss.pinMode(bottom, INPUT);
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
/// @param button - a bool that's true when the button module is in use
/// @param ss - the seesaw in question
void faceButtonRead (int top, int bottom, int left, int right, bool button,
                     Adafruit_seesaw ss)
{
    button = false;

    //process the top button input
    if (digitalRead(top))
    {
        gamepad.press(BUTTON_4);
        button = true;
    }
    else
    {
        gamepad.release(BUTTON_4);
    }

    //process bottom button input
    if (digitalRead(bottom))
    {
        gamepad.press(BUTTON_1);
        button = true;
    }
    else
    {
        gamepad.release(BUTTON_1);
    }

    //process left button input
    if (digitalRead(left))
    {
        gamepad.press(BUTTON_3);
        button = true;
    }
    else
    {
        gamepad.release(BUTTON_3);
    }
    
    //process right button input
    if (digitalRead(right))
    {
        gamepad.press(BUTTON_2);
        button = true;
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
/// @param button - a bool that's true when the button module is in use
/// @param ss - the seesaw in question
void dpadRead (int up, int down, int left, int right, bool button, 
               Adafruit_seesaw ss)
{
  //THIS MODULE IS LIKELY TO BE FULLY MESSED UP BY WRONG BUTTON MAPPING
  //It depends on if the other triggers are included in the button mapping
    button = false;

    //process the up button input
    if (digitalRead(up))
    {
        gamepad.press(BUTTON_13);
        button = true;
    }
    else
    {
        gamepad.release(BUTTON_13);
    }

    //process down button input
    if (digitalRead(down))
    {
        gamepad.press(BUTTON_14);
        button = true;
    }
    else
    {
        gamepad.release(BUTTON_14);
    }

    //process left button input
    if (digitalRead(left))
    {
        gamepad.press(BUTTON_15);
        button = true;
    }
    else
    {
        gamepad.release(BUTTON_15);
    }
    
    //process right button input
    if (digitalRead(right))
    {
        gamepad.press(BUTTON_16);
        button = true;
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
/// @param joystick - a bool that's true when the joystick module is in use
/// @param ss - the seesaw in question
void rJoystickRead(int x, int y, int select, bool joystick, Adafruit_seesaw ss)
{
    
    int dx;
    int dy;
    int xx, yy;

    // read from x and y to xx and yy
    xx = ss.analogRead(x);
    yy = ss.analogRead(y);
    
    // usage check
    if (x == 0 && y == 0)
    {
        joystick = false;
    }
    else 
    {
        joystick = true;
    }
    
    // map xx and yy to the proper ranges to dx and dy
    dx = map(xx, 0, 1023, 0, 32767);
    dy = map(yy, 0, 1023, 0, 32767);

    //put the data in the gamepad
    gamepad.setRightThumb(dx,dy);
    
    //read button press
    if (digitalRead(select) == HIGH)
    {      
        gamepad.press(BUTTON_12);
        joystick = true;
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
/// @param joystick - a bool that's true when the joystick module is in use
/// @param ss - the seesaw in question
void lJoystickRead(int x, int y, int select, bool joystick, Adafruit_seesaw ss)
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

    //joystick check
    if (x == 0 && y == 0)
    {
        joystick = false;
    }
    else 
    {
        joystick = true;
    }
    
    //put the data in the gamepad
    gamepad.setLeftThumb(dx,dy);

    //read button press
    if (digitalRead(select) == HIGH)
    {  
        gamepad.press(BUTTON_11);
        joystick = true;
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
/// @param trigger - a bool that's true when the trigger module is in use
/// @param ss - the seesaw in question
void lTriggerRead ( int top, int bottom, bool trigger, Adafruit_seesaw ss )
{
  bool t = digitalRead(top);
  bool b = digitalRead(bottom);
    if ( t == LOW && b == LOW)
    {
        gamepad.release(BUTTON_5);
        gamepad.release(BUTTON_7);
        trigger = false;
    }
    else
    {
        // default to not in use
        trigger = true;
        if(b) // if bottom button is pressed
        {
            gamepad.press(BUTTON_7);
        }
        else
        {
           gamepad.release(BUTTON_7);
        }
        
        if(t) // if the top button is pressed
        {
            gamepad.press(BUTTON_5);
        }
        else
        {
           gamepad.release(BUTTON_5);
        }
    }
}

/// @brief This function uses the input pins and uses them to read input and 
///        translate that into functional trigger button inputs
/// @param top - the top button pin#
/// @param bottom - the bottom button pin# 
/// @param trigger - a bool that's true when the trigger module is in use
/// @param ss - the seesaw in question
void rTriggerRead ( int top, int bottom, bool trigger, Adafruit_seesaw ss )
{
  bool t = digitalRead(top);
  bool b = digitalRead(bottom);
    if ( t == LOW && b == LOW)
    {
        gamepad.release(BUTTON_6);
        gamepad.release(BUTTON_8);
        trigger = false;
    }
    else
    {
        // if either button is in use, it's in use.
        trigger = true;
        
        if(b) // if bottom button is pressed
        {
            gamepad.press(BUTTON_8);
        }
        else
        {
           gamepad.release(BUTTON_8);
        }
        
        if(t) // if the top button is pressed
        {
            gamepad.press(BUTTON_6);
        }
        else
        {
           gamepad.release(BUTTON_6);
        }
    }
}

#endif
