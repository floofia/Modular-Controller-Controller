# Modular Controller - Controller 

## Description
All code related to the modular controller main controller we are making for our senior design project.
Code is placed in folders that relate to their function.

## Module Programmer
This is the largest program in this repository, it handles programming and reading the ATTiny817 devices, this will be added on to include all funtions we will implement in the design.

### Main Controller
The main controller of this project is the ESP-32, it programs the ATTiny817 devices connected to it over i2c by writing to their EEPROM. 
Parts of the game controller will be initialized by reading the EEPROM of the ATTiny817 devices connected.

### Modules 
Modules are ATTiny817 devices that connect to the ESP-32. They are initialized by the ESP-32 by reading their EEPROM. 
The ATTiny817 will have joystics, buttons, triggers, etc which will serve as inputs for the user.


## Team
- Sofia Sadun
- Duncan Thomas McGonagle
- Hannah Carroll


## Advisors
- Brian Butterfield (brian.butterfield@sdsmt.edu)
- Ed Mandy (ed@7400circuits.com)

## [Project Wiki](https://gitlab.com/groups/sdmines/sd/2022/11/-/wikis/home)
