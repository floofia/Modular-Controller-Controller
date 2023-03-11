//String  input = "Address; module_name; dev_type; Digital: 1 2 3 4; Analog: 5 6 7 8;";
//drmpf - inspired by
//https://forum.arduino.cc/t/how-to-split-a-string-with-space-and-store-the-items-in-array/888813/14




#ifndef GUI_INTERFACE_H
#define GUI_INTERFACE_H

#include "Global_Variables.h"
#include "Module_Read_Write_Functions.h"

void gui_setup (Adafruit_seesaw ss)
{
  char module_name_char[32];
  String strs[20];
  int StringCount = 0;

  String input;
  
  String address;
  String module_name;
  String dev_type;
  String pins;
  
  int int_address;
  int int_pin[15] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
  int int_dev_type;

  //String str, full_read;


  Serial.println("Begin GUI Interface");
  Serial.print("Format Expected: ");
  Serial.println("Address;module_name;dev_type;Pins: 1, 2, 3, 4, 5;");

  input = string_read();

  // Split the string into substrings 
  //this section uses code that I will want to adjust more
  while (input.length() > 0)
  {
    int index = input.indexOf(';');
    if (index == -1) // No space found
    {
      strs[StringCount++] = input;
      break;
    }
    else
    {
      strs[StringCount++] = input.substring(0, index);
      input = input.substring(index + 1);
    }
  }

  address = strs[0];
  module_name = strs[1];
  dev_type = strs[2];
  pins = strs[3];

//converting pins string to array of integers
  int numCount = 0;//elements in array

  int pos = pins.indexOf(":") + 1;//extract values after :

  while (pos < pins.length()) 
  {
    String numStr = "";

    while (pos < pins.length() && isDigit(pins.charAt(pos)))
     {
      numStr += pins.charAt(pos++);//append digits from string
    }

    if (numStr != "") 
    {
      int num = numStr.toInt();//convert string to int
      int_pin[numCount++] = num;//add int to array
    }

    pos++;//skip comma or space after number
  }



  int_address = address.toInt();
  int_dev_type = mod_type_int(dev_type);
  module_name.toCharArray(module_name_char, 32);

//write module name
  for (int i = 0; i < 32; i++)
  {
    ss.EEPROMWrite8(i, module_name_char[i]);
  }

//write pins
for (int i = 0; i < 15; i++)
{
ss.EEPROMWrite8(70 + i, int_pin[i]);
}



  if ((int_address < 127) && (int_address > 0) )
  {

    ss.EEPROMWrite8(126, int_dev_type);

    ss.EEPROMWrite8(127, int_address);

   }
  else
  {

    Serial.println("Error in Writing, check values");

  }

}










#endif
