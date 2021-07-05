# piHOME 32Channel PWM Controller Revision 1.0

Information

# Download and Print

A list

1. Bottom
2. Pads
3. Vias
4. Unrouted
5. Dimensions
6. Holes

# Build

1. Set configuration in config.h
2. Set pinconfiguration in pins.h
3. run 'make clean'
4. run 'make hex'
5. run 'make program' (Optionally)

# Instructions
Build instructions with images can be found here:

#### config.h

Different configuration values can be set in Config.h. The most important values are F_CPU and Outsorting.

*** Important

It is mandatory The F_CPU is set with the right CPU clock being set as it can otherwise come to an undesirable behavior.

Platform|MCU|Example Boards
  --------|---|-------

#### pins.h