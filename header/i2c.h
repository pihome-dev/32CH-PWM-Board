#define I2CADDR0 0x42
#define I2CADDR1 0x44
#define I2CADDR2 0x46
#define I2CADDR3 0x48
#define I2CADDR4 0x4A
#define I2CADDR5 0x4C
#define I2CADDR6 0x4E
#define I2CADDR7 0x50

int i2caddr1;
int i2caddr2;
int i2caddr3;

int i2caddrret;

void i2c_readaddr_init(void);
int i2c_readaddr(void);

volatile uint8_t i2cdata[i2c_buffer_size];
volatile int i2cbuf;

volatile uint8_t i2cmodenr;
volatile uint8_t i2cchnr;
volatile uint8_t i2cpwmval;
volatile uint8_t i2cpwmspeed;
volatile uint8_t i2cpwmchange;

volatile uint8_t i2csenddata[50];
volatile int ic2sendbuf;
volatile uint8_t i2creadmodenr;
