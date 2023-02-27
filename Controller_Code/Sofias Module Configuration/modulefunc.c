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
/// @param ss - the seesaw in question
void faceButtonRead (int top, int bottom, int left, int right, 
                     Adafruit_seesaw ss)
{

}

void dpadRead (int up, int down, int left, int right, Adafruit_seesaw ss)
{

}


void rJoystickRead(int x, int y, int select, Adafruit_seesaw ss)
{

}

void lJoystickRead(int x, int y, int select, Adafruit_seesaw ss)
{

}