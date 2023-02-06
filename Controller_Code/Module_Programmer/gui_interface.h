//String  input = "Address; module_name; dev_type; Digital: 1 2 3 4; Analog: 5 6 7 8;";
//drmpf - inspired by
//https://forum.arduino.cc/t/how-to-split-a-string-with-space-and-store-the-items-in-array/888813/14




#ifndef GUI_INTERFACE_H
#define GUI_INTERFACE_H

#include "globals.h"
#include "Bit_Write.h"

void gui_setup (Adafruit_seesaw ss)
{
  char module_name_char[32];
  String strs[20];
  int StringCount = 0;

  String input;
  
  String address;
  String module_name;
  String dev_type;
  String digital_pins;
  String analog_pins;

  int int_address;
  int int_digital_pins;
  int int_analog_pins;
  int int_dev_type;

  //String str, full_read;


  Serial.println("Begin GUI Interface");
  Serial.print("Format Expected: ");
  Serial.println("Address; module_name; dev_type; Digital_pins; Analog_pins;");

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
  digital_pins = strs[3];
  analog_pins = strs[4];


  int_address = address.toInt();
  int_digital_pins = digital_pins.toInt();
  int_analog_pins = analog_pins.toInt();
  int_dev_type = mod_type_int(dev_type);


  module_name.toCharArray(module_name_char, 32);


  for (int i = 0; i < 32; i++)
  {
    ss.EEPROMWrite8(i, module_name_char[i]);
  }



  if (!(int_address > 127) || !(int_digital_pins > 255) || !(int_analog_pins > 255) || !(int_address < 0) || !(int_digital_pins < 0) || !(int_analog_pins < 0))
  {

    ss.EEPROMWrite8(124, int_digital_pins);
    ss.EEPROMWrite8(125, int_analog_pins);
    ss.EEPROMWrite8(126, int_dev_type);
    ss.EEPROMWrite8(127, int_address);
  }
  else
  {

    Serial.println("Error in Writing, check values");

  }

}










#endif
