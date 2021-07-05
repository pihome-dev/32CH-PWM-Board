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
  
  softreset = 0;
  
  // Enable Watchdog
  wdt_enable(WDTO_2S);
  
  // EEPROM
  if (getEEDefaultExist() != (uint16_t) eeDataDefaultExist) {
  	 eeprom_write_default_data();
  }
  
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
  	 	  																		// 1 3 1 (Mode) 1 (Channel) 3 (Speed) 
  	 	  	 i2cmodenr = i2cdata[2];
  	 	  	 i2cchnr = i2cdata[3];
  	 	  	 i2cpwmval = i2cdata[4];
  	 	  	 if (i2cmodenr >= 1 && i2cmodenr <= PWMMODENUMS && i2cchnr >= 1 && i2cchnr <= CHANNELNUMS && i2cpwmval >= 1 && i2cpwmval <= 100) {
  	 	  	 	i2cchnr = i2cchnr - 1;
  	 	  	   
  	 	  	   set_pwmmode_speed(i2cmodenr, i2cchnr, i2cpwmval);
  	 	  	   
  	 	  	   if (runmode == i2cmodenr) {
  	 	  	     modedatachange = 1;
  	 	  	   }
  	 	  	 }
  	 	  	 
  	 	    break;
  	 	    
  	 	  case 4:															// Change Channel Changemode in selected Mode  | 1, Changespeed, Modenumber, Channelnumber, Changemode (1 = Soft, 2 = Hard)
  	 	  																		// 1 4 1 (Mode) 1 (Channel) 1 (Changemode) 
  	 	  	 i2cmodenr = i2cdata[2];
  	 	  	 i2cchnr = i2cdata[3];
  	 	  	 i2cpwmval = i2cdata[4];
  	 	  	 if (i2cmodenr >= 1 && i2cmodenr <= PWMMODENUMS && i2cchnr >= 1 && i2cchnr <= CHANNELNUMS && i2cpwmval >= 1 && i2cpwmval <= 2) {
  	 	  	 	i2cchnr = i2cchnr - 1;
  	 	  	   
  	 	  	   set_pwmmode_changemode(i2cmodenr, i2cchnr, i2cpwmval);
  	 	  	   
  	 	  	   if (runmode == i2cmodenr) {
  	 	  	     modedatachange = 1;
  	 	  	   }
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
  
  }

}
