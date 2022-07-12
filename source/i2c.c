#include "../header/system.h"

void i2c_readaddr_init(void) {

	I2CADDRDDR &= ~(1 << I2CADDR1PIN);
	I2CADDRDDR &= ~(1 << I2CADDR2PIN);
	I2CADDRDDR &= ~(1 << I2CADDR3PIN);
	
	I2CADDRPORT |= (1<<I2CADDR1PIN);
	I2CADDRPORT |= (1<<I2CADDR2PIN);
	I2CADDRPORT |= (1<<I2CADDR3PIN);

}

int i2c_readaddr(void) {

	if ( I2CADDRPIND & (1<<PINC2) ) {
  		i2caddr1 = 1;
	} else {
		i2caddr1 = 0;	
	}
	
	if ( I2CADDRPIND & (1<<PINC1) ) {
  		i2caddr2 = 1;
	} else {
		i2caddr2 = 0;	
	}
	
	if ( I2CADDRPIND & (1<<PINC0) ) {
  		i2caddr3 = 1;
	} else {
		i2caddr3 = 0;	
	}
	
	// 000
	if (i2caddr1 == 0 && i2caddr2 == 0 && i2caddr3 == 0) {
	  i2caddrret = 1;
	}
	
	// 100
	if (i2caddr1 == 1 && i2caddr2 == 0 && i2caddr3 == 0) {
	  i2caddrret = 2;
	}
	
	// 110
	if (i2caddr1 == 1 && i2caddr2 == 1 && i2caddr3 == 0) {
	  i2caddrret = 3;
	}
	
	// 111
	if (i2caddr1 == 1 && i2caddr2 == 1 && i2caddr3 == 1) {
	  i2caddrret = 4;
	}
	
	// 101
	if (i2caddr1 == 1 && i2caddr2 == 0 && i2caddr3 == 1) {
	  i2caddrret = 5;
	}
	
	// 001
	if (i2caddr1 == 0 && i2caddr2 == 0 && i2caddr3 == 1) {
	  i2caddrret = 6;
	}
	
	// 010
	if (i2caddr1 == 0 && i2caddr2 == 1 && i2caddr3 == 0) {
	  i2caddrret = 7;
	}
	
   // 011
	if (i2caddr1 == 0 && i2caddr2 == 1 && i2caddr3 == 1) {
	  i2caddrret = 8;
	}
	
	return i2caddrret;
}