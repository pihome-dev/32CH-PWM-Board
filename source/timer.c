#include "../header/system.h"

void systemTimer_init(void) {
  
  TCCR3B |= (1<<WGM32);      //CTC mode
  TCCR3B |= (1<<CS32);       //Prescaler 256 

  OCR3A = ( (F_CPU / TIMERPRE) / 1000) * TIMERFREQ;
  
  TCNT3 = 0;

  // Compare Interrupt erlauben
  ETIMSK |= (1<<OCIE3A);
}

ISR (TIMER3_COMPA_vect)
{
  // PWM Flag
  RUNPWM = 1;
  // Systemtimer
  sysTimer = sysTimer + TIMERFREQ;
  // Statustimer
  stateTimer+= 10;
  
  if (sysTimer > 1000) {
    sysTimer = 0;
    timerTick = 1;
  }

}

void pwmtimer_init(void) {
  TCCR1B = 1;             // Timer läuft mit vollem Systemtakt
  TIMSK |= (1<<OCIE1A);   // Interrupt freischalten
}

ISR(TIMER1_COMPA_vect) {
	 
    static uint8_t pwm_cnt=0;
    uint8_t tmpA=0, iA=0, jA=1;
    
    uint8_t tmpB=0, iB=0, jB=1;
    uint8_t tmpC=0, iC=0, jC=1;
    uint8_t tmpE=0, iE=0, jE=1;

    OCR1A += (uint16_t)T_PWM;

    for (; iA<8; iA++) {    
    	if (pwm_settingA[iA] > pwm_cnt) tmpA |= jA;
            jA<<=1;
	 }
	 
	 for (; iB<8; iB++) {    
    	if (pwm_settingB[iB] > pwm_cnt) tmpB |= jB;
            jB<<=1;
	 }
	 
	 for (; iC<8; iC++) {    
    	if (pwm_settingC[iC] > pwm_cnt) tmpC |= jC;
            jC<<=1;
	 }
	 
	 for (; iE<8; iE++) {    
    	if (pwm_settingE[iE] > pwm_cnt) tmpE |= jE;
            jE<<=1;
	 }
	
	
    PWM_PORTA = tmpA;                         // PWMs aktualisieren
    PWM_PORTB = tmpB;                         // PWMs aktualisieren
    PWM_PORTC = tmpC;                         // PWMs aktualisieren
    PWM_PORTE = tmpE;                         // PWMs aktualisieren
    
    if (pwm_cnt==(uint8_t)(PWM_STEPS-1))
        pwm_cnt=0;
    else
        pwm_cnt++;
}