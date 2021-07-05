#ifndef _TWISLAVE_H
#define _TWISLAVE_H

#include "system.h"

void init_twi_slave();

int i2c_tda_number;
int i2c_tda_data;
int i2c_tmp_data;

#if (__GNUC__ * 100 + __GNUC_MINOR__) < 304
	#error "This library requires AVR-GCC 3.4.5 or later, update to newer AVR-GCC compiler !"
#endif

#if (i2c_buffer_size > 254)
	#error Buffer zu gross gewaehlt! Maximal 254 Bytes erlaubt.
#endif

#if (i2c_buffer_size < 2)
	#error Buffer muss mindestens zwei Byte gross sein!
#endif



#endif
