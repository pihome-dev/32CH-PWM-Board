#include "../header/system.h"

void channels_init(void) {

  PWM_DDRA = 0xFF;         // Port als Ausgang
  PWM_DDRB = 0xFF;
  PWM_DDRC = 0xFF;
  PWM_DDRE = 0xFF;
  
  PWM_PORTA &= ~(1<<PA0);
  PWM_PORTA &= ~(1<<PA1);
  PWM_PORTA &= ~(1<<PA2);
  PWM_PORTA &= ~(1<<PA3);
  PWM_PORTA &= ~(1<<PA4);
  PWM_PORTA &= ~(1<<PA5);
  PWM_PORTA &= ~(1<<PA6);
  PWM_PORTA &= ~(1<<PA7);
  
  PWM_PORTB &= ~(1<<PB0);
  PWM_PORTB &= ~(1<<PB1);
  PWM_PORTB &= ~(1<<PB2);
  PWM_PORTB &= ~(1<<PB3);
  PWM_PORTB &= ~(1<<PB4);
  PWM_PORTB &= ~(1<<PB5);
  PWM_PORTB &= ~(1<<PB6);
  PWM_PORTB &= ~(1<<PB7);
  
  PWM_PORTC &= ~(1<<PC0);
  PWM_PORTC &= ~(1<<PC1);
  PWM_PORTC &= ~(1<<PC2);
  PWM_PORTC &= ~(1<<PC3);
  PWM_PORTC &= ~(1<<PC4);
  PWM_PORTC &= ~(1<<PC5);
  PWM_PORTC &= ~(1<<PC6);
  PWM_PORTC &= ~(1<<PC7);
  
  PWM_PORTE &= ~(1<<PE0);
  PWM_PORTE &= ~(1<<PE1);
  PWM_PORTE &= ~(1<<PE2);
  PWM_PORTE &= ~(1<<PE3);
  PWM_PORTE &= ~(1<<PE4);
  PWM_PORTE &= ~(1<<PE5);
  PWM_PORTE &= ~(1<<PE6);
  PWM_PORTE &= ~(1<<PE7);
	
  for (int i = 0; i < 32; i++) {
    pwm[i][0] = 0;		// PWM Value
  }
  
  PWM_CH1_IS = 0;
  PWM_CH2_IS = 0;
  PWM_CH3_IS = 0;
  PWM_CH4_IS = 0;
  PWM_CH5_IS = 0;
  PWM_CH6_IS = 0;
  PWM_CH7_IS = 0;
  PWM_CH8_IS = 0;

  PWM_CH9_IS = 0;
  PWM_CH10_IS = 0;
  PWM_CH11_IS = 0;
  PWM_CH12_IS = 0;
  PWM_CH13_IS = 0;
  PWM_CH14_IS = 0;
  PWM_CH15_IS = 0;
  PWM_CH16_IS = 0;

  PWM_CH17_IS = 0;
  PWM_CH18_IS = 0;
  PWM_CH19_IS = 0;
  PWM_CH20_IS = 0;
  PWM_CH21_IS = 0;
  PWM_CH22_IS = 0;
  PWM_CH23_IS = 0;
  PWM_CH24_IS = 0;

  PWM_CH25_IS = 0;
  PWM_CH26_IS = 0;
  PWM_CH27_IS = 0;
  PWM_CH28_IS = 0;
  PWM_CH29_IS = 0;
  PWM_CH30_IS = 0;
  PWM_CH31_IS = 0;
  PWM_CH32_IS = 0;
}

void channels_update(void) {

  switch (OUTSORTING) {
    case 1:
	   // PA0
    	pwm_settingA[0] = PWM_CH1_IS;
    	// PA1
    	pwm_settingA[1] = PWM_CH2_IS;
    	// PA2
    	pwm_settingA[2] = PWM_CH3_IS;
    	// PA3
    	pwm_settingA[3] = PWM_CH4_IS;
    	// PA4
    	pwm_settingA[4] = PWM_CH5_IS;
    	// PA5
    	pwm_settingA[5] = PWM_CH6_IS;
   	// PA6
    	pwm_settingA[6] = PWM_CH7_IS;
    	// PA7
    	pwm_settingA[7] = PWM_CH8_IS;
  
    	// PC0
    	pwm_settingC[0] = PWM_CH6_IS;
    	// PC1
    	pwm_settingC[1] = PWM_CH15_IS;
    	// PC2
    	pwm_settingC[2] = PWM_CH14_IS;
    	// PC3
    	pwm_settingC[3] = PWM_CH13_IS;
    	// PC4
    	pwm_settingC[4] = PWM_CH12_IS;
    	// PC5
    	pwm_settingC[5] = PWM_CH11_IS;
    	// PC6
    	pwm_settingC[6] = PWM_CH10_IS;
    	// PC7
    	pwm_settingC[7] = PWM_CH9_IS;
  
    	// PB0
    	pwm_settingB[0] = PWM_CH24_IS;
    	// PB1
    	pwm_settingB[1] = PWM_CH23_IS;
	 	// PB2
    	pwm_settingB[2] = PWM_CH22_IS;
    	// PB3
    	pwm_settingB[3] = PWM_CH21_IS;
    	// PB4
    	pwm_settingB[4] = PWM_CH20_IS;
    	// PB5
    	pwm_settingB[5] = PWM_CH19_IS;
    	// PB6
    	pwm_settingB[6] = PWM_CH18_IS;
    	// PB7
    	pwm_settingB[7] = PWM_CH17_IS;
  
    	// PE0
    	pwm_settingE[0] = PWM_CH32_IS;
    	// PE1
    	pwm_settingE[1] = PWM_CH31_IS;
    	// PE2
    	pwm_settingE[2] = PWM_CH30_IS;
    	// PE3
    	pwm_settingE[3] = PWM_CH29_IS;
    	// PE4
    	pwm_settingE[4] = PWM_CH28_IS;
    	// PE5
    	pwm_settingE[5] = PWM_CH27_IS;
    	// PE6
    	pwm_settingE[6] = PWM_CH26_IS;
    	// PE7
    	pwm_settingE[7] = PWM_CH25_IS;
    	break;
    
    case 2:
	   // PA0
    	pwm_settingA[0] = PWM_CH1_IS;
    	// PA1
    	pwm_settingA[1] = PWM_CH17_IS;
    	// PA2
    	pwm_settingA[2] = PWM_CH2_IS;
    	// PA3
    	pwm_settingA[3] = PWM_CH18_IS;
    	// PA4
    	pwm_settingA[4] = PWM_CH3_IS;
    	// PA5
    	pwm_settingA[5] = PWM_CH19_IS;
   	// PA6
    	pwm_settingA[6] = PWM_CH4_IS;
    	// PA7
    	pwm_settingA[7] = PWM_CH20_IS;
  
    	// PC0
    	pwm_settingC[0] = PWM_CH24_IS;
    	// PC1
    	pwm_settingC[1] = PWM_CH8_IS;
    	// PC2
    	pwm_settingC[2] = PWM_CH23_IS;
    	// PC3
    	pwm_settingC[3] = PWM_CH7_IS;
    	// PC4
    	pwm_settingC[4] = PWM_CH22_IS;
    	// PC5
    	pwm_settingC[5] = PWM_CH6_IS;
    	// PC6
    	pwm_settingC[6] = PWM_CH21_IS;
    	// PC7
    	pwm_settingC[7] = PWM_CH5_IS;
  
    	// PB0
    	pwm_settingB[0] = PWM_CH28_IS;
    	// PB1
    	pwm_settingB[1] = PWM_CH12_IS;
	 	// PB2
    	pwm_settingB[2] = PWM_CH27_IS;
    	// PB3
    	pwm_settingB[3] = PWM_CH11_IS;
    	// PB4
    	pwm_settingB[4] = PWM_CH26_IS;
    	// PB5
    	pwm_settingB[5] = PWM_CH10_IS;
    	// PB6
    	pwm_settingB[6] = PWM_CH25_IS;
    	// PB7
    	pwm_settingB[7] = PWM_CH9_IS;
  
    	// PE0
    	pwm_settingE[0] = PWM_CH32_IS;
    	// PE1
    	pwm_settingE[1] = PWM_CH16_IS;
    	// PE2
    	pwm_settingE[2] = PWM_CH31_IS;
    	// PE3
    	pwm_settingE[3] = PWM_CH15_IS;
    	// PE4
    	pwm_settingE[4] = PWM_CH30_IS;
    	// PE5
    	pwm_settingE[5] = PWM_CH14_IS;
    	// PE6
    	pwm_settingE[6] = PWM_CH29_IS;
    	// PE7
    	pwm_settingE[7] = PWM_CH13_IS;
    	break;
    	
    default:
      // PA0
    	pwm_settingA[0] = PWM_CH1_IS;
    	// PA1
    	pwm_settingA[1] = PWM_CH2_IS;
    	// PA2
    	pwm_settingA[2] = PWM_CH3_IS;
    	// PA3
    	pwm_settingA[3] = PWM_CH4_IS;
    	// PA4
    	pwm_settingA[4] = PWM_CH5_IS;
    	// PA5
    	pwm_settingA[5] = PWM_CH6_IS;
   	// PA6
    	pwm_settingA[6] = PWM_CH7_IS;
    	// PA7
    	pwm_settingA[7] = PWM_CH8_IS;
  
    	// PC0
    	pwm_settingC[0] = PWM_CH6_IS;
    	// PC1
    	pwm_settingC[1] = PWM_CH15_IS;
    	// PC2
    	pwm_settingC[2] = PWM_CH14_IS;
    	// PC3
    	pwm_settingC[3] = PWM_CH13_IS;
    	// PC4
    	pwm_settingC[4] = PWM_CH12_IS;
    	// PC5
    	pwm_settingC[5] = PWM_CH11_IS;
    	// PC6
    	pwm_settingC[6] = PWM_CH10_IS;
    	// PC7
    	pwm_settingC[7] = PWM_CH9_IS;
  
    	// PB0
    	pwm_settingB[0] = PWM_CH24_IS;
    	// PB1
    	pwm_settingB[1] = PWM_CH23_IS;
	 	// PB2
    	pwm_settingB[2] = PWM_CH22_IS;
    	// PB3
    	pwm_settingB[3] = PWM_CH21_IS;
    	// PB4
    	pwm_settingB[4] = PWM_CH20_IS;
    	// PB5
    	pwm_settingB[5] = PWM_CH19_IS;
    	// PB6
    	pwm_settingB[6] = PWM_CH18_IS;
    	// PB7
    	pwm_settingB[7] = PWM_CH17_IS;
  
    	// PE0
    	pwm_settingE[0] = PWM_CH32_IS;
    	// PE1
    	pwm_settingE[1] = PWM_CH31_IS;
    	// PE2
    	pwm_settingE[2] = PWM_CH30_IS;
    	// PE3
    	pwm_settingE[3] = PWM_CH29_IS;
    	// PE4
    	pwm_settingE[4] = PWM_CH28_IS;
    	// PE5
    	pwm_settingE[5] = PWM_CH27_IS;
    	// PE6
    	pwm_settingE[6] = PWM_CH26_IS;
    	// PE7
    	pwm_settingE[7] = PWM_CH25_IS;
    	break;
   }
      
}

void channels_run(void) {

	if (PWM_CH1_IS != pwm[CH1][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH1) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH1) == PWMCHANGESOFT) {
	      if (PWM_CH1_IS > pwm[CH1][0]) {
	        PWM_CH1_IS--;
	      } else {
	        PWM_CH1_IS++;
	      }
	    } else {
	      PWM_CH1_IS = pwm[CH1][0];
	    }
	  }
	}

	if (PWM_CH2_IS != pwm[CH2][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH2) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH2) == PWMCHANGESOFT) {
	      if (PWM_CH2_IS > pwm[CH2][0]) {
	        PWM_CH2_IS--;
	      } else {
	        PWM_CH2_IS++;
	      }
	    } else {
	      PWM_CH2_IS = pwm[CH2][0];
	    }
	  }
	}

	if (PWM_CH3_IS != pwm[CH3][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH3) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH3) == PWMCHANGESOFT) {
	      if (PWM_CH3_IS > pwm[CH3][0]) {
	        PWM_CH3_IS--;
	      } else {
	        PWM_CH3_IS++;
	      }
	    } else {
	      PWM_CH3_IS = pwm[CH3][0];
	    }
	  }
	}

	if (PWM_CH4_IS != pwm[CH4][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH4) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH4) == PWMCHANGESOFT) {
	      if (PWM_CH4_IS > pwm[CH4][0]) {
	        PWM_CH4_IS--;
	      } else {
	        PWM_CH4_IS++;
	      }
	    } else {
	      PWM_CH4_IS = pwm[CH4][0];
	    }
	  }
	}

	if (PWM_CH5_IS != pwm[CH5][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH5) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH5) == PWMCHANGESOFT) {
	      if (PWM_CH5_IS > pwm[CH5][0]) {
	        PWM_CH5_IS--;
	      } else {
	        PWM_CH5_IS++;
	      }
	    } else {
	      PWM_CH5_IS = pwm[CH5][0];
	    }
	  }
	}

	if (PWM_CH6_IS != pwm[CH6][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH6) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH6) == PWMCHANGESOFT) {
	      if (PWM_CH6_IS > pwm[CH6][0]) {
	        PWM_CH6_IS--;
	      } else {
	        PWM_CH6_IS++;
	      }
	    } else {
	      PWM_CH6_IS = pwm[CH6][0];
	    }
	  }
	}

	if (PWM_CH7_IS != pwm[CH7][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH7) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH7) == PWMCHANGESOFT) {
	      if (PWM_CH7_IS > pwm[CH7][0]) {
	        PWM_CH7_IS--;
	      } else {
	        PWM_CH7_IS++;
	      }
	    } else {
	      PWM_CH7_IS = pwm[CH7][0];
	    }
	  }
	}

	if (PWM_CH8_IS != pwm[CH8][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH8) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH8) == PWMCHANGESOFT) {
	      if (PWM_CH8_IS > pwm[CH8][0]) {
	        PWM_CH8_IS--;
	      } else {
	        PWM_CH8_IS++;
	      }
	    } else {
	      PWM_CH8_IS = pwm[CH8][0];
	    }
	  }
	}

	if (PWM_CH9_IS != pwm[CH9][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH9) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH9) == PWMCHANGESOFT) {
	      if (PWM_CH9_IS > pwm[CH9][0]) {
	        PWM_CH9_IS--;
	      } else {
	        PWM_CH9_IS++;
	      }
	    } else {
	      PWM_CH9_IS = pwm[CH9][0];
	    }
	  }
	}

	if (PWM_CH10_IS != pwm[CH10][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH10) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH10) == PWMCHANGESOFT) {
	      if (PWM_CH10_IS > pwm[CH10][0]) {
	        PWM_CH10_IS--;
	      } else {
	        PWM_CH10_IS++;
	      }
	    } else {
	      PWM_CH10_IS = pwm[CH10][0];
	    }
	  }
	}

	if (PWM_CH11_IS != pwm[CH11][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH11) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH11) == PWMCHANGESOFT) {
	      if (PWM_CH11_IS > pwm[CH11][0]) {
	        PWM_CH11_IS--;
	      } else {
	        PWM_CH11_IS++;
	      }
	    } else {
	      PWM_CH11_IS = pwm[CH11][0];
	    }
	  }
	}

	if (PWM_CH12_IS != pwm[CH12][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH12) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH12) == PWMCHANGESOFT) {
	      if (PWM_CH12_IS > pwm[CH12][0]) {
	        PWM_CH12_IS--;
	      } else {
	        PWM_CH12_IS++;
	      }
	    } else {
	      PWM_CH12_IS = pwm[CH12][0];
	    }
	  }
	}

	if (PWM_CH13_IS != pwm[CH13][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH13) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH13) == PWMCHANGESOFT) {
	      if (PWM_CH13_IS > pwm[CH13][0]) {
	        PWM_CH13_IS--;
	      } else {
	        PWM_CH13_IS++;
	      }
	    } else {
	      PWM_CH13_IS = pwm[CH13][0];
	    }
	  }
	}

	if (PWM_CH14_IS != pwm[CH14][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH14) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH14) == PWMCHANGESOFT) {
	      if (PWM_CH14_IS > pwm[CH14][0]) {
	        PWM_CH14_IS--;
	      } else {
	        PWM_CH14_IS++;
	      }
	    } else {
	      PWM_CH14_IS = pwm[CH14][0];
	    }
	  }
	}

	if (PWM_CH15_IS != pwm[CH15][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH15) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH15) == PWMCHANGESOFT) {
	      if (PWM_CH15_IS > pwm[CH15][0]) {
	        PWM_CH15_IS--;
	      } else {
	        PWM_CH15_IS++;
	      }
	    } else {
	      PWM_CH15_IS = pwm[CH15][0];
	    }
	  }
	}

	if (PWM_CH16_IS != pwm[CH16][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH16) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH16) == PWMCHANGESOFT) {
	      if (PWM_CH16_IS > pwm[CH16][0]) {
	        PWM_CH16_IS--;
	      } else {
	        PWM_CH16_IS++;
	      }
	    } else {
	      PWM_CH16_IS = pwm[CH16][0];
	    }
	  }
	}

	if (PWM_CH17_IS != pwm[CH17][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH17) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH17) == PWMCHANGESOFT) {
	      if (PWM_CH17_IS > pwm[CH17][0]) {
	        PWM_CH17_IS--;
	      } else {
	        PWM_CH17_IS++;
	      }
	    } else {
	      PWM_CH17_IS = pwm[CH17][0];
	    }
	  }
	}

	if (PWM_CH18_IS != pwm[CH18][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH18) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH18) == PWMCHANGESOFT) {
	      if (PWM_CH18_IS > pwm[CH18][0]) {
	        PWM_CH18_IS--;
	      } else {
	        PWM_CH18_IS++;
	      }
	    } else {
	      PWM_CH18_IS = pwm[CH18][0];
	    }
	  }
	}

	if (PWM_CH19_IS != pwm[CH19][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH19) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH19) == PWMCHANGESOFT) {
	      if (PWM_CH19_IS > pwm[CH19][0]) {
	        PWM_CH19_IS--;
	      } else {
	        PWM_CH19_IS++;
	      }
	    } else {
	      PWM_CH19_IS = pwm[CH19][0];
	    }
	  }
	}

	if (PWM_CH20_IS != pwm[CH20][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH20) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH20) == PWMCHANGESOFT) {
	      if (PWM_CH20_IS > pwm[CH20][0]) {
	        PWM_CH20_IS--;
	      } else {
	        PWM_CH20_IS++;
	      }
	    } else {
	      PWM_CH20_IS = pwm[CH20][0];
	    }
	  }
	}

	if (PWM_CH21_IS != pwm[CH21][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH21) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH21) == PWMCHANGESOFT) {
	      if (PWM_CH21_IS > pwm[CH21][0]) {
	        PWM_CH21_IS--;
	      } else {
	        PWM_CH21_IS++;
	      }
	    } else {
	      PWM_CH21_IS = pwm[CH21][0];
	    }
	  }
	}

	if (PWM_CH22_IS != pwm[CH22][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH22) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH22) == PWMCHANGESOFT) {
	      if (PWM_CH22_IS > pwm[CH22][0]) {
	        PWM_CH22_IS--;
	      } else {
	        PWM_CH22_IS++;
	      }
	    } else {
	      PWM_CH22_IS = pwm[CH22][0];
	    }
	  }
	}

	if (PWM_CH23_IS != pwm[CH23][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH23) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH23) == PWMCHANGESOFT) {
	      if (PWM_CH23_IS > pwm[CH23][0]) {
	        PWM_CH23_IS--;
	      } else {
	        PWM_CH23_IS++;
	      }
	    } else {
	      PWM_CH23_IS = pwm[CH23][0];
	    }
	  }
	}

	if (PWM_CH24_IS != pwm[CH24][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH24) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH24) == PWMCHANGESOFT) {
	      if (PWM_CH24_IS > pwm[CH24][0]) {
	        PWM_CH24_IS--;
	      } else {
	        PWM_CH24_IS++;
	      }
	    } else {
	      PWM_CH24_IS = pwm[CH24][0];
	    }
	  }
	}

	if (PWM_CH25_IS != pwm[CH25][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH25) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH25) == PWMCHANGESOFT) {
	      if (PWM_CH25_IS > pwm[CH25][0]) {
	        PWM_CH25_IS--;
	      } else {
	        PWM_CH25_IS++;
	      }
	    } else {
	      PWM_CH25_IS = pwm[CH25][0];
	    }
	  }
	}

	if (PWM_CH26_IS != pwm[CH26][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH26) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH26) == PWMCHANGESOFT) {
	      if (PWM_CH26_IS > pwm[CH26][0]) {
	        PWM_CH26_IS--;
	      } else {
	        PWM_CH26_IS++;
	      }
	    } else {
	      PWM_CH26_IS = pwm[CH26][0];
	    }
	  }
	}

	if (PWM_CH27_IS != pwm[CH27][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH27) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH27) == PWMCHANGESOFT) {
	      if (PWM_CH27_IS > pwm[CH27][0]) {
	        PWM_CH27_IS--;
	      } else {
	        PWM_CH27_IS++;
	      }
	    } else {
	      PWM_CH27_IS = pwm[CH27][0];
	    }
	  }
	}

	if (PWM_CH28_IS != pwm[CH28][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH28) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH28) == PWMCHANGESOFT) {
	      if (PWM_CH28_IS > pwm[CH28][0]) {
	        PWM_CH28_IS--;
	      } else {
	        PWM_CH28_IS++;
	      }
	    } else {
	      PWM_CH28_IS = pwm[CH28][0];
	    }
	  }
	}

	if (PWM_CH29_IS != pwm[CH29][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH29) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH29) == PWMCHANGESOFT) {
	      if (PWM_CH29_IS > pwm[CH29][0]) {
	        PWM_CH29_IS--;
	      } else {
	        PWM_CH29_IS++;
	      }
	    } else {
	      PWM_CH29_IS = pwm[CH29][0];
	    }
	  }
	}

	if (PWM_CH30_IS != pwm[CH30][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH30) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH30) == PWMCHANGESOFT) {
	      if (PWM_CH30_IS > pwm[CH30][0]) {
	        PWM_CH30_IS--;
	      } else {
	        PWM_CH30_IS++;
	      }
	    } else {
	      PWM_CH30_IS = pwm[CH30][0];
	    }
	  }
	}

	if (PWM_CH31_IS != pwm[CH31][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH31) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH31) == PWMCHANGESOFT) {
	      if (PWM_CH31_IS > pwm[CH31][0]) {
	        PWM_CH31_IS--;
	      } else {
	        PWM_CH31_IS++;
	      }
	    } else {
	      PWM_CH31_IS = pwm[CH31][0];
	    }
	  }
	}

	if (PWM_CH32_IS != pwm[CH32][0]) {
	  if ( ( sysTimer % (get_pwmmode_speed(runmode, CH32) * TIMERFREQ) ) == 0) {
	    if (get_pwmmode_changemode(runmode, CH32) == PWMCHANGESOFT) {
	      if (PWM_CH32_IS > pwm[CH32][0]) {
	        PWM_CH32_IS--;
	      } else {
	        PWM_CH32_IS++;
	      }
	    } else {
	      PWM_CH32_IS = pwm[CH32][0];
	    }
	  }
	}
  
  RUNPWM = 0;
  
}