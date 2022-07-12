#include "../header/system.h"

int main(void) {
  
  wdt_disable();
  
  // Initialisiere System LED (Status LED)
  stateled_init();
  systemstate = STATE_IDLE;
  
  // Initialisiere I2C
  i2c_readaddr_init();
  init_twi_slave(i2c_readaddr());  
  
  // Initialisiere PWM Channels
  channels_init();
  
  // Initialisiere PWM Timer
  pwmtimer_init();
  
  // Initialisiere PWM Modes
  modes_init();
  
  // Initialisiere PWM Functions
  functions_init();
  
  softreset = 0;
  
  // Enable Watchdog
  wdt_enable(WDTO_2S);
  
  // EEPROM
  if (getEEDefaultExist() != (uint16_t) eeDataDefaultExist) {
  	 eeprom_write_default_data();
  }
  
  eeprom_load_default_data();
  
  systemTimer_init();
  
  ismode = 0;
  runmode = 1;
  
  sei();
  
  systemstate = STATE_RUN;
  
  while (1) {
  	 
  	 if (softreset == 0) {
      wdt_reset();
  	 }
  	 
  	 if (RUNPWM == 1) {
  	   channels_run();
    }
  	 
  	 channels_update();
  	 
  	 // Systemled
    stateled();
    // Systemled end
  	 
    // System
    if (ismode != runmode || modedatachange == 1) {
      for (int i = 0; i < 32; i++) {
        pwm[i][0] = pwmmode[runmode][i][0];
      }
      modedatachange = 0;
      ismode = runmode;
    }
    
    if (i2cbuf != 0) {
    	
    	switch(i2cdata[1]) {

  	 	  case 1:															// Change Channel Value in selected Mode  | 1, Change, Modenumber, Channelnumber, Value(0-PWM_STEPS(255))
  	 	  																		// 1 1 1 (Mode) 1 (Channel) 100 (Value)
  	 	  	 i2cmodenr = i2cdata[2];
  	 	  	 i2cchnr = i2cdata[3];
  	 	  	 i2cpwmval = i2cdata[4];
  	 	  	 if (i2cmodenr >= 1 && i2cmodenr <= PWMMODENUMS && i2cchnr >= 1 && i2cchnr <= CHANNELNUMS && i2cpwmval >= 0 && i2cpwmval <= PWM_STEPS) {
  	 	  	 	i2cchnr = i2cchnr - 1;
  	 	  	 	
  	 	  	   set_pwmmode_value(i2cmodenr, i2cchnr, i2cpwmval);
  	 	  	   eeprom_autosave();
  	 	  	   
  	 	  	   if (runmode == i2cmodenr) {
  	 	  	     modedatachange = 1;
  	 	  	   }
  	 	  	 }
  	 	  	 
  	 	    break;
  	 	    
  	 	  case 2:															// Change Runmode  | 1, Change, Modenumber
  	 	  																		// 1 2 1 (Mode)
  	 	  	 if (i2cdata[2] >= 0 && i2cdata[2] <= PWMMODENUMS) {
  	 	  	   runmode = i2cdata[2];
  	 	  	 }
  	 	  	 
  	 	    break;
  	 	    
  	 	  case 3:															// Change Channel Changespeed in selected Mode  | 1, Changespeed, Modenumber, Channelnumber, Speed(Val * TIMERFREQ))
  	 	  																		// 1 3 1 (Mode) 1 (Channel) 3 (Speed) 1 (Changemode)
  	 	  	 i2cmodenr = i2cdata[2];
  	 	  	 i2cchnr = i2cdata[3];
  	 	  	 i2cpwmspeed = i2cdata[4];
  	 	  	 i2cpwmchange = i2cdata[5];
  	 	  	 if (i2cmodenr >= 1 && i2cmodenr <= PWMMODENUMS && i2cchnr >= 1 && i2cchnr <= CHANNELNUMS && i2cpwmspeed >= 1 && i2cpwmspeed <= 5 && i2cpwmchange >= 0 && i2cpwmchange <= 1) {
  	 	  	   i2cchnr = i2cchnr - 1;
  	 	  	   
  	 	  	   set_pwmmode_speedchange(i2cmodenr, i2cchnr, i2cpwmspeed, i2cpwmchange);
  	 	  	   eeprom_autosave();
  	 	  	   
  	 	  	   if (runmode == i2cmodenr) {
  	 	  	     modedatachange = 1;
  	 	  	   }
  	 	  	 }
  	 	  	 
  	 	    break;
  	 	    
  	 	  case 5:															// Read Channel Mode Value  | 1,  Modenumber
  	 	    																	// 1 5 2 (Modenr)
  	 	    i2creadmodenr = i2cdata[2];
  	 	    if (i2creadmodenr >= 1 && i2creadmodenr <= PWMMODENUMS) {
  	 	    	int a = 1;
  	 	    	for (int i = 0; i < 32; i++) {
  	 	        i2csenddata[a] = pwmmode[i2creadmodenr][i][0];
  	 	        a++;
  	 	      }
  	 	      i2csenddata[0] = a;
  	 	      ic2sendbuf = 0;
  	 	   } else {
  	 	     i2csenddata[0] = 0;
  	 	   }
  	 	    
  	 	    break;
  	 	    
  	 	  case 6:															// Read Channel Mode Changespeed  | 1,  Modenumber
  	 	    																	// 1 6 2 (Modenr)
  	 	    i2creadmodenr = i2cdata[2];
  	 	    if (i2creadmodenr >= 1 && i2creadmodenr <= PWMMODENUMS) {
  	 	    	int a = 1;
  	 	    	for (int i = 0; i < 32; i++) {
  	 	        i2csenddata[a] = pwmmode[i2creadmodenr][i][1];
  	 	        a++;
  	 	      }
  	 	      i2csenddata[0] = a;
  	 	      ic2sendbuf = 0;
  	 	   } else {
  	 	     i2csenddata[0] = 0;
  	 	   }
  	 	    
  	 	    break;
  	 	    
  	 	  case 7:															// Read Channel Mode Changemode  | 1,  Modenumber
  	 	    																	// 1 7 2 (Modenr)
  	 	    i2creadmodenr = i2cdata[2];
  	 	    if (i2creadmodenr >= 1 && i2creadmodenr <= PWMMODENUMS) {
  	 	    	int a = 1;
  	 	    	for (int i = 0; i < 32; i++) {
  	 	        i2csenddata[a] = pwmmode[i2creadmodenr][i][2];
  	 	        a++;
  	 	      }
  	 	      i2csenddata[0] = a;
  	 	      ic2sendbuf = 0;
  	 	   } else {
  	 	     i2csenddata[0] = 0;
  	 	   }
  	 	    
  	 	    break;
  	 	    
  	 	  case 8:															// Reboot
  	 	  																		// 1 8 1
  	 	  	 if (i2cdata[2] == 1) {
  	 	  	   softreset = 1;
  	 	  	 }
  	 	  	 break;
  	 	    
  	 	  case 9:															// Factory Reset
  	 	  																		// 1 9 1
  	 	  	 if (i2cdata[2] == 1) {
  	 	  	   eeprom_write_default(56);
  	 	  	   softreset = 1;
  	 	    }
  	 	  	 break;
  	 	  	 
  	 	  default:
  	 	    break;
  	 	}
      i2cbuf = 0;
    }
    
	 if (timerTick == 1) {
	   timerTick = 0;
	   
	   if (eeprom_changed == 1) {
	     if (eeprom_changed_timer < eeDataAutosaveTime) {
	       eeprom_changed_timer++;
	     } else {
	       eeprom_write_autosave();
	       eeprom_changed = 0;
	       eeprom_changed_timer = 0;
	     }
	   }
	 }
  
  }

}
