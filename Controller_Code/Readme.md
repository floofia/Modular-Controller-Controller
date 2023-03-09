## This is the code for the hardware/firmware. 
______________________________
# Contents of this readme:    |
- Legend for File Map         |
- File Map                    |
- EEPROM Notes                |
- Module/Pin Notes            |
-------------------------------
____________
# Legend:  |
> folder   |
- File     |
* function |
-----------------------------------------------
# MAP:                                            
    > Controller_code
        > Controller_Setup   
            - Controller_Setup.ino

            - Global_Variables.h

            - gui_interface.h
                *gui_setup
                
            - i2c_scan.h
                *i2c_scan_verbose
                *i2c_scan
            
            - Module_initialization.h
                *Seesaw_struct_name
                *Seesaw_read_settings
                *byte_to_pins_read

            - Module_Read_Write_Functions.h
                *string_convert_int                
                *string_read
                *all_devices_output
                *all_devices_buffer
                *read_entire_rom
                *read_device_rom
                *write_device_rom_sequence
                *write_device_address
                *write_device_mod_name
                *write_device_dev_type
                *write_device_pins
                *mod_type
                *mod_type_int

            - serial_setup.h
                *serial_setup

        > Module Programmer
            - Controller_Setup.ino

        > Sofias Module Configuration
            > sofiasnewcode
                 - modulefuncheader.h
                 
                 - modulefunctiondefinitions.h
                    *faceButtonSetup
                    *faceButtonRead 
                    *dpadSetup 
                    *dpadRead
                    *rJoystickSetup
                    *rJoystickRead
                    *lJoystickSetup
                    *lJoystickRead
                    *lTriggerSetup
                    *rTriggerSetup
                    *lTriggerRead 
                    *rTriggerRead  
                    *debuggerSetup
                    *debuggerWrite 

                 - sofiasnewcode.ino

            - controllerheader.h

-----------------------------------------------
    
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

# Module/Pin Notes: 
    ## DEFAULTS
    - Joystick module:
        Select/button -> pin 12(Digital)
        X out  -> pin 18 (Using ADC)
        Y out -> pin 19 (Using ADC)
    - Buttons/Dpad module:
        Top/up -> pin 13 (Digital)
        Bottom/down -> pin 18 (Digital)
        Left -> pin 14 (Digital)
        Right -> pin 19 (Digital)
    - Triggers:
        Top trigger -> pin 18 (Digital)
        Bottom trigger -> pin 14 (Digital)

    ## PINS
    - ADC (Analog Input) Capable Pins: 0, 1, 2, 3, 6, 7, 18, 19, 20 		
    - PWM (Analog Output) Capable Pins: 0, 1, 9, 12, 13				
    - Digital Capable Pins: 0, 1, 2, 3, 20, 5, 6, 7, 8, 9, 12, 13, 14, 18, 19	
