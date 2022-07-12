#include "../header/system.h"

void modes_init(void) {
  for (int i = 0; i < PWMMODENUMS; i++) {
    pwmmode[i][CH1][0] = 0;
    pwmmode[i][CH2][0] = 0;
    pwmmode[i][CH3][0] = 0;
    pwmmode[i][CH4][0] = 0;
    pwmmode[i][CH5][0] = 0;
    pwmmode[i][CH6][0] = 0;
    pwmmode[i][CH7][0] = 0;
    pwmmode[i][CH8][0] = 0;
    
    pwmmode[i][CH9][0] = 0;
    pwmmode[i][CH10][0] = 0;
    pwmmode[i][CH11][0] = 0;
    pwmmode[i][CH12][0] = 0;
    pwmmode[i][CH13][0] = 0;
    pwmmode[i][CH14][0] = 0;
    pwmmode[i][CH15][0] = 0;
    pwmmode[i][CH16][0] = 0;
    
    pwmmode[i][CH17][0] = 0;
    pwmmode[i][CH18][0] = 0;
    pwmmode[i][CH19][0] = 0;
    pwmmode[i][CH20][0] = 0;
    pwmmode[i][CH21][0] = 0;
    pwmmode[i][CH22][0] = 0;
    pwmmode[i][CH23][0] = 0;
    pwmmode[i][CH24][0] = 0;
    
    pwmmode[i][CH25][0] = 0;
    pwmmode[i][CH26][0] = 0;
    pwmmode[i][CH27][0] = 0;
    pwmmode[i][CH28][0] = 0;
    pwmmode[i][CH29][0] = 0;
    pwmmode[i][CH30][0] = 0;
    pwmmode[i][CH31][0] = 0;
    pwmmode[i][CH32][0] = 0;
    
    pwmmode[i][CH1][1] = 3;
    pwmmode[i][CH2][1] = 3;
    pwmmode[i][CH3][1] = 3;
    pwmmode[i][CH4][1] = 3;
    pwmmode[i][CH5][1] = 3;
    pwmmode[i][CH6][1] = 3;
    pwmmode[i][CH7][1] = 3;
    pwmmode[i][CH8][1] = 3;
    
    pwmmode[i][CH9][1] = 3;
    pwmmode[i][CH10][1] = 3;
    pwmmode[i][CH11][1] = 3;
    pwmmode[i][CH12][1] = 3;
    pwmmode[i][CH13][1] = 3;
    pwmmode[i][CH14][1] = 3;
    pwmmode[i][CH15][1] = 3;
    pwmmode[i][CH16][1] = 3;
    
    pwmmode[i][CH17][1] = 3;
    pwmmode[i][CH18][1] = 3;
    pwmmode[i][CH19][1] = 3;
    pwmmode[i][CH20][1] = 3;
    pwmmode[i][CH21][1] = 3;
    pwmmode[i][CH22][1] = 3;
    pwmmode[i][CH23][1] = 3;
    pwmmode[i][CH24][1] = 3;
    
    pwmmode[i][CH25][1] = 3;
    pwmmode[i][CH26][1] = 3;
    pwmmode[i][CH27][1] = 3;
    pwmmode[i][CH28][1] = 3;
    pwmmode[i][CH29][1] = 3;
    pwmmode[i][CH30][1] = 3;
    pwmmode[i][CH31][1] = 3;
    pwmmode[i][CH32][1] = 3;
    
    pwmmode[i][CH1][2] = PWMCHANGESOFT;
    pwmmode[i][CH2][2] = PWMCHANGESOFT;
    pwmmode[i][CH3][2] = PWMCHANGESOFT;
    pwmmode[i][CH4][2] = PWMCHANGESOFT;
    pwmmode[i][CH5][2] = PWMCHANGESOFT;
    pwmmode[i][CH6][2] = PWMCHANGESOFT;
    pwmmode[i][CH7][2] = PWMCHANGESOFT;
    pwmmode[i][CH8][2] = PWMCHANGESOFT;
    
    pwmmode[i][CH9][2] = PWMCHANGESOFT;
    pwmmode[i][CH10][2] = PWMCHANGESOFT;
    pwmmode[i][CH11][2] = PWMCHANGESOFT;
    pwmmode[i][CH12][2] = PWMCHANGESOFT;
    pwmmode[i][CH13][2] = PWMCHANGESOFT;
    pwmmode[i][CH14][2] = PWMCHANGESOFT;
    pwmmode[i][CH15][2] = PWMCHANGESOFT;
    pwmmode[i][CH16][2] = PWMCHANGESOFT;
    
    pwmmode[i][CH17][2] = PWMCHANGESOFT;
    pwmmode[i][CH18][2] = PWMCHANGESOFT;
    pwmmode[i][CH19][2] = PWMCHANGESOFT;
    pwmmode[i][CH20][2] = PWMCHANGESOFT;
    pwmmode[i][CH21][2] = PWMCHANGESOFT;
    pwmmode[i][CH22][2] = PWMCHANGESOFT;
    pwmmode[i][CH23][2] = PWMCHANGESOFT;
    pwmmode[i][CH24][2] = PWMCHANGESOFT;
    
    pwmmode[i][CH25][2] = PWMCHANGESOFT;
    pwmmode[i][CH26][2] = PWMCHANGESOFT;
    pwmmode[i][CH27][2] = PWMCHANGESOFT;
    pwmmode[i][CH28][2] = PWMCHANGESOFT;
    pwmmode[i][CH29][2] = PWMCHANGESOFT;
    pwmmode[i][CH30][2] = PWMCHANGESOFT;
    pwmmode[i][CH31][2] = PWMCHANGESOFT;
    pwmmode[i][CH32][2] = PWMCHANGESOFT;
    
  }
  
  modedatachange = 0;
  runmode = 0;
}

uint8_t get_pwmmode_value(uint8_t modenr, uint8_t channel) {

  return pwmmode[modenr][channel][0];
}

void set_pwmmode_value(uint8_t modenr, uint8_t channel, uint8_t value) {
	
  pwmmode[modenr][channel][0] = value;
  eeprom_autosave();
}

uint8_t get_pwmmode_speed(uint8_t modenr, uint8_t channel) {

  return pwmmode[modenr][channel][1];
}

void set_pwmmode_speedchange(uint8_t modenr, uint8_t channel, uint8_t speed, uint8_t change) {
	
  pwmmode[modenr][channel][1] = speed;
  pwmmode[modenr][channel][2] = change;
  eeprom_autosave();
}

uint8_t get_pwmmode_changemode(uint8_t modenr, uint8_t channel) {

  return pwmmode[modenr][channel][2];
}
