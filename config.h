#define F_CPU         						16000000L  							// Systemtakt in Hz

#define F_PWM 									200                         					// PWM-Frequenz in Hz
#define PWM_STEPS 							100                         					// PWM-Schritte pro Zyklus(1..255)
#define T_PWM 									(F_CPU/(F_PWM*PWM_STEPS))   					// Systemtakte pro PWM-Takt

// Timer
#define TIMERFREQ								10				   				// Timerfrequenz in ms
#define TIMERPRE								256								// Timer Prescaler

#define i2c_buffer_size 					50

#define OUTSORTING							2

//// OUTSORTING
// 
// => 1 (Default)
// CH1  | CH3  | CH5  | CH7  | CH9  | CH11 | CH13 | CH15 | CH17 | CH19 | CH21 | CH23 | CH25 | CH27 | CH29 | CH31
// CH2  | CH4  | CH6  | CH8  | CH10 | CH12 | CH14 | CH16 | CH18 | CH20 | CH22 | CH24 | CH26 | CH28 | CH30 | CH32

// => 2
// CH1  | CH2  | CH3  | CH4  | CH5  | CH6  | CH7  | CH8  | CH9  | CH10 | CH11 | CH12 | CH13 | CH14 | CH15 | CH16
// CH17 | CH18 | CH19 | CH20 | CH21 | CH22 | CH23 | CH24 | CH25 | CH26 | CH27 | CH28 | CH29 | CH30 | CH31 | CH32
