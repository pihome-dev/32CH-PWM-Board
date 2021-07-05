#define					CH1						0
#define					CH2						1
#define					CH3						2
#define					CH4						3
#define					CH5						4
#define					CH6						5
#define					CH7						6
#define					CH8						7

#define					CH9						8
#define					CH10						9
#define					CH11						10
#define					CH12						11
#define					CH13						12
#define					CH14						13
#define					CH15						14
#define					CH16						15

#define					CH17						16
#define					CH18						17
#define					CH19						18
#define					CH20						19
#define					CH21						20
#define					CH22						21
#define					CH23						22
#define					CH24						23

#define					CH25						24
#define					CH26						25
#define					CH27						26
#define					CH28						27
#define					CH29						28
#define					CH30						29
#define					CH31						30
#define					CH32						31

#define					CHANNELNUMS				32

#define					PWMCHANGESOFT			1
#define					PWMCHANGEHARD			0

volatile uint8_t pwm[CHANNELNUMS][2];

volatile uint8_t pwm_settingA[8];                    // Einstellungen für die einzelnen PWM-Kanäle
volatile uint8_t pwm_settingB[8];                    // Einstellungen für die einzelnen PWM-Kanäle
volatile uint8_t pwm_settingC[8];                    // Einstellungen für die einzelnen PWM-Kanäle
volatile uint8_t pwm_settingE[8];                    // Einstellungen für die einzelnen PWM-Kanäle

void channels_init(void);
void channels_update(void);
void channels_run(void);

volatile uint8_t PWM_CH1_IS;
volatile uint8_t PWM_CH2_IS;
volatile uint8_t PWM_CH3_IS;
volatile uint8_t PWM_CH4_IS;
volatile uint8_t PWM_CH5_IS;
volatile uint8_t PWM_CH6_IS;
volatile uint8_t PWM_CH7_IS;
volatile uint8_t PWM_CH8_IS;

volatile uint8_t PWM_CH9_IS;
volatile uint8_t PWM_CH10_IS;
volatile uint8_t PWM_CH11_IS;
volatile uint8_t PWM_CH12_IS;
volatile uint8_t PWM_CH13_IS;
volatile uint8_t PWM_CH14_IS;
volatile uint8_t PWM_CH15_IS;
volatile uint8_t PWM_CH16_IS;

volatile uint8_t PWM_CH17_IS;
volatile uint8_t PWM_CH18_IS;
volatile uint8_t PWM_CH19_IS;
volatile uint8_t PWM_CH20_IS;
volatile uint8_t PWM_CH21_IS;
volatile uint8_t PWM_CH22_IS;
volatile uint8_t PWM_CH23_IS;
volatile uint8_t PWM_CH24_IS;

volatile uint8_t PWM_CH25_IS;
volatile uint8_t PWM_CH26_IS;
volatile uint8_t PWM_CH27_IS;
volatile uint8_t PWM_CH28_IS;
volatile uint8_t PWM_CH29_IS;
volatile uint8_t PWM_CH30_IS;
volatile uint8_t PWM_CH31_IS;
volatile uint8_t PWM_CH32_IS;