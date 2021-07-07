# piHOME 32Channel PWM Controller Revision 1.0

The piHOME 32 channel PWM controller can be connected directly to the piHOME system via the piHOME Connect Bus.

The controller is ideal for dimming up to 32 lamps. The output voltage can be set to 5V (900mA max. Total voltage of all outputs) or operating voltage via a switch.

As with all piHOME additional components, 8 controllers can also be operated per mainboard. This enables PWM / switching channels of up to 256 pieces.

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
  
  P1|P2|P3|P4|P5|P6|P7|P8|P9|P10|P11|P12|P13|P14|P15|P16
  -------|---|---|---|---|---|---|---|---|---|---|---|---|---|---|-------
  CH1|CH2|CH3|CH4|CH5|CH6|CH7|CH8|CH9|CH10|CH11|CH12|CH13|CH14|CH15|CH16