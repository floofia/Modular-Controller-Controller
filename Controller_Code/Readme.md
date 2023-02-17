## This is the code for the hardware/firmware. 
______________________________
# Contents of this readme:    |
- Legend for File Map         |
- File Map                    |
- File Descriptions           |
- Function Descriptions       |
- EEPROM Notes                |
-------------------------------
____________
# Legend:  |
> folder   |
- File     |
* function |
-----------------------------------------------
# MAP:                                            
    > Controller_code
        > Module_Initializer   

        > Module_Programmer
            - Bit_Write_ESP32.cpp

            - Bit_write.h
                * string_convert_int
                * string_read
                * all_devices_output
                * all_devices_buffer
                * read_entire_rom
                * read_device_rom
                * write_device_rom_sequence
                * write_device_address
                * write_device_mod_name
                * write_device_dev_type
                * mod_type

            - globals.h

            - i2c_scan.h
                *i2c_scan_verbose
                *i2c_scan

            - serial_setup.h
                *serial_setup

        > Sofia's Headers
            - controllerheader.h

-----------------------------------------------

# FILE DESCRIPTIONS:
    Bit_Write_ESP32.cpp
        This file is the main file for handling programming the i2c devices
        it outputs information the GUI can read.

    Bit_write.h
        This file has a lot of functions for use in Bit_Write_ESP32.cpp

    globals.h
        This file is the file with Global Variables to be used by multiple files

    i2c_scan.h
        This file detects the addresses of i2c devices connected to the esp-32

        Future Iteration: This is not how I want to handle detecting
            address, Duncan will be modifying this code to use his own
            Implementaion to better fit the project

    Serial_setup.h
        This file is an example that shows how to blink a pin on a seesaw.
        It is written to use the built-in LED on the ATtiny817 breakout with seesaw.

        Future Iteration: Use this code as a base to intialize individual pins

    controllerheader.h
        This file is for Sofia to write and modify code to try to define how 
        things are going to be processed.

        Future Iteration: This page should be updated once we settle on how 
            everything will be processed. 


# FUNCTION DESRIPTIONS: (Arranged alphabetically)
    all_devices_buffer (Bit_write.h)
        This function overwrites the values in the i2c)_outputts array

        >Input: none
        >Output: none

    all_devices_output (Bit_write.h)
        This function initializes i2c connected devices

        >Input: none
        >Output: none

    i2c_scan_verbose (i2cscan.h)
        This function detects connected i2c devices and saves their addresses
        to an array that can be used to initialize multiple attiny917
        seesaw devices, verbose is useful as it is nice for error checking
        This function is not used in the program

        >Input: none
        >Output: none
    
    i2c_scan (i2c_scan.h)
        This function is near identical to i2c_scan_verbose however it only 
        displays an error if something goes wrong
        
        >Input: none
        >Output: none
    
    mod_type (Bit_write.h)
        This function overwrites values in the i2c_outputts array   

        >Input: int type
        >Output: string

    read_device_rom (Bit_write.h)
        This function outputs all used registers of the eeprom and outputs 

        to the GUI in the proper format
        >Input: Adafruit_seesaw ss
        >Output: none

    read_entire_rom (Bit_write.h)
        This function outputs all registers of the eeprom, useful for debuging  

        >Input: Adafruit_seesaw ss
        >Output: none

    serial_setup (serial_setup.h)
        This function

        >Input: int baud
        >Output: none

    string_convert_int (Bit_write.h)
        This function reads a user submitted strin and turns it into an int

        >Input: none
        >Output: none
        
    string_read (Bit_write.h)
        This function reads a string from the user    

        >Input: none
        >Output: string

    write_device_rom_sequence (Bit_write.h)
        This function writes a sequence for modifying modules

        >Input: Adafruit_seesaw &ss
        >Output: none

    write_device_address (Bit_write.h)
        This function reads and writes register 127 (the device's address)
        and then prompts the user to change the name. 

        >Input: Adafruit_seesaw &ss
        >Output: none

    write_device_mod_name (Bit_write.h)
        This function reads the first 32 registers of the eeprom (which is 
        the device name) and prints to the screen and prompts the user for 
        a name change. 

        >Input: Adafruit_seesaw ss
        >Output: none

    write_device_dev_type (Bit_write.h)
        This function reads register 126 of the EEPROM (which is the device
        type for the module) and prompts the user to change it. 

        >Input: Adafruit_seesaw ss
        >Output: none


# EEPROM Notes:
    EEPROM BYTE MAP
    Byte 0-63 - Name (may shorten to 32 bytes)
    Byte 64-123 - ??? (space for later)
    Byte 124 - Pins p.1 
    Byte 125 - Pins p.2
    \\for each pin on seesaw 1 = user input, 0 = controller feedback
    Byte 126 - Device Type
    Byte 127 - Address

    BYTE 126 DEVICE TYPE LEGEND	
    Battery(Passive):   00000000
    Audio:              00010000
    Visual Feedback:    00100000
    Haptic/rumble:      00110000
    D-Pad:              00000001
    Joystick:           00000010
    Button:             00000011
    Keyboard:           00000100
    Trigger:            00000101

    *Note: first 4 bits are for feedback, last 4 for inputs:
    If char > 15 then feedback is true
    If char%16 > 0 then input is true
    If both, MIXED module
    If char == 0 then passive
