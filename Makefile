TARGET=system
MCU=atmega128
SOURCES=source/system.c source/timer.c source/channels.c source/modes.c source/i2c.c source/twislave.c source/eeprom.c source/sysled.c source/functions.c

PROGRAMMER=usbasp

LFUSE=0xCF
HFUSE=0xD9

#without Watchog
#EFUSE=0xFF

#with watchdog
EFUSE=0xFE

#auskommentieren für automatische Wahl
#PORT=-P/dev/ttyS0
#BAUD=-B115200

#Ab hier nichts verändern
OBJECTS=$(SOURCES:.c=.o)
CFLAGS=-c -Os
LDFLAGS=

all: hex eeprom

hex: $(TARGET).hex

eeprom: $(TARGET)_eeprom.hex

$(TARGET).hex: $(TARGET).elf
	avr-objcopy -O ihex -j .data -j .text $(TARGET).elf $(TARGET).hex

$(TARGET)_eeprom.hex: $(TARGET).elf
	avr-objcopy -O ihex -j .eeprom --change-section-lma .eeprom=1 $(TARGET).elf $(TARGET)_eeprom.hex

$(TARGET).elf: $(OBJECTS)
	avr-gcc $(LDFLAGS) -mmcu=$(MCU) $(OBJECTS) -o $(TARGET).elf

.c.o:
	avr-gcc $(CFLAGS) -mmcu=$(MCU) $< -o $@

size:
	avr-size --mcu=$(MCU) -C $(TARGET).elf

program:
	avrdude -p $(MCU) -c $(PROGRAMMER) -Uflash:w:$(TARGET).hex:a

fuses:
	avrdude -p $(MCU) -c $(PROGRAMMER) -B 5 -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m

clean_tmp:
	rm -rf *.o
	rm -rf *.elf

clean:
	rm -rf source/*.o
	rm -rf source/*.elf
	rm -rf source/*.hex
	rm -rf *.hex
	rm -rf *.elf
