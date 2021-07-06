# piHOME 32Channel PWM Controller Revision 1.0

Information


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