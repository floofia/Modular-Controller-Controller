

#include "modulefunc.h"

/*****************/
/*SETUP FUNCIONS**/
/*****************/

/// @brief This function sets up and defines the pins of the seesaw
/// @param top - the top face button
/// @param bottom - the bottom face button (usually the select button)
/// @param left - the left face button
/// @param right - the right face button (usually the decline button)
/// @param address - the seesaw's address
/// @param ss - the seesaw in question
void faceButtonSetup (int top, int bottom, int left, int right, char address, 
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
/// @param address - the seesaw's address
/// @param ss - the seesaw in question
void dpadSetup (int up, int down, int left, int right, char address, 
                Adafruit_seesaw ss)
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
/// @param address - the see saw's adress
/// @param ss - the seesaw in question
void rJoystickSetup(int x, int y, int select, char address, Adafruit_seesaw ss)
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
/// @param address - the see saw's adress
/// @param ss - the seesaw in question
void lJoystickSetup(int x, int y, int select, char address, Adafruit_seesaw ss)
{
    ss.pinMode(x, INPUT);
    ss.pinMode(y, INPUT);
    ss.pinMode(select, INPUT);

}

/// @brief This is a function that sets up the left trigger
/// @param top - top button's input pin
/// @param bottom - bottom button's input pin
/// @param address the seesaw's address
/// @param ss the seesw itself
void lTriggerSetup ( int top, int bottom, char address, Adafruit_seesaw ss )
{
    ss.pinMode(top, INPUT);
    ss.pinMode(bottom, INPUT);
 
}

/// @brief this is a function that sets up the right trigger
/// @param top - top button's input pin
/// @param bottom - bottom button's input pin
/// @param address the seesaw's address
/// @param ss the seesw itself
void rTriggerSetup ( int top, int bottom, char address, Adafruit_seesaw ss )
{
    ss.pinMode(top, INPUT);
    ss.pinMode(bottom, INPUT);
}


/***************/
/*USE FUNCIONS**/
/***************/
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

}

void dpadRead (int up, int down, int left, int right, bool button, 
               Adafruit_seesaw ss)
{

}


void rJoystickRead(int x, int y, int select, bool joystick, Adafruit_seesaw ss)
{
    Blegamepad.setRightThumb(ss.analogRead(x), ss.analogRead(y));
    
    int dx;
    int dy;
    int  z;
    int lx, ly, lz;
//    gamepad.getAxes(lx, ly, lz, _, _, _);
    if (x == 0 && y == 0)
    {
        joystick = false;
    }
    else 
    {
        joystick = true;
    }

    dx = map(x, 0, 1023, -128, 127);
    dy = map(y, 0, 1023, 127, -128);
        if (digitalread(select) == HIGH)
    {
        z = 127;
        joystick = true;

    }
    else
    {
        z = -127;
    }
    Blegamepad.setRZ(z);
    

}

void lJoystickRead(int x, int y, int select, bool joystick, Adafruit_seesaw ss)
{

}

void lTriggerRead ( int top, int bottom, bool trigger, Adafruit_seesaw ss )
{
    if (digitalread(top) == LOW)
    {
        //BleGamepad.release(BUTTON);
    }
    else
    {
        //BleGamepad.release(BUTTON);

    }

}

void rTriggerRead ( int top, int bottom, bool trigger, Adafruit_seesaw ss )
{

}
