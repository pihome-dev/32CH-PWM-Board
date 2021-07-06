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


  Setting|Value|Description
  --------|---|-------
  F_CPU|12000000 - 16000000|Set the CPU Frequency
  OUTSORTING|0,1|Set the Output Pindirection
  F_PWM| 50 - 100 |Set the PWM Frequency
  PWM_STEPS|100 - 255 |Set max. PWM Steps
  
  #### Outsorting Table
 
  #### 1 (Default)
  --------|---|-------
  CH1  | CH3  | CH5  | CH7  | CH9  | CH11 | CH13 | CH15 | CH17 | CH19 | CH21 | CH23 | CH25 | CH27 | CH29 | CH31
  
  CH2  | CH4  | CH6  | CH8  | CH10 | CH12 | CH14 | CH16 | CH18 | CH20 | CH22 | CH24 | CH26 | CH28 | CH30 | CH32

  #### 2
  CH1  | CH2  | CH3  | CH4  | CH5  | CH6  | CH7  | CH8  | CH9  | CH10 | CH11 | CH12 | CH13 | CH14 | CH15 | CH16
  
  CH17 | CH18 | CH19 | CH20 | CH21 | CH22 | CH23 | CH24 | CH25 | CH26 | CH27 | CH28 | CH29 | CH30 | CH31 | CH32