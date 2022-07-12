#define		eeDataDefaultExist	87
#define		eeDataAutosaveTime	30

void eeprom_write_default(uint16_t data);
void eeprom_write_default_data(void);
uint16_t getEEDefaultExist(void);
void eeprom_load_default_data(void);

volatile int eeprom_autosave_enable;
volatile int eeprom_changed;
volatile int eeprom_changed_timer;
void eeprom_autosave(void);

void eeprom_write_autosave(void);