#include "../config.h"
#include "../pins.h"

#include <avr/io.h>
#include <avr/wdt.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#include <util/twi.h>
#include <stdint.h>
#include <avr/eeprom.h>
#include <stdio.h>
#include <string.h>

#include <compat/twi.h>

#include <stdlib.h>
#include <avr/pgmspace.h>
#include <util/crc16.h>

#include <util/delay.h>

#include "channels.h"
#include "modes.h"
#include "twislave.h"
#include "i2c.h"
#include "timer.h"
#include "eeprom.h"
#include "sysled.h"
#include "functions.h"

volatile int RUNPWM;

volatile int softreset;