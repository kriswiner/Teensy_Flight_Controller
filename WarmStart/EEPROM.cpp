#include "Arduino.h"
#include "EEPROM.h"

EEPROM::EEPROM()
{
}

uint8_t EEPROM::calculate_sum(uint8_t *cb , uint8_t siz)
{
  uint8_t sum=0x55;  // checksum init
  while(--siz) sum += *cb++;  // Calculate checksum (without checksum byte)
  return sum;
}

uint8_t EEPROM::readGlobalSet()
{
  eeprom_read_block((void*)&global_conf, (void*)0, sizeof(global_conf));

  // If checksum flunks, load defaults
  if(EEPROM::calculate_sum((uint8_t*)&global_conf, (sizeof(global_conf)-1)) != global_conf.checksum)
  {
    global_conf.currentSet = 0;
    for (uint8_t i=0; i<3; i++)
    {
      global_conf.accZero_max[i] = 512;
      global_conf.accZero_min[i] = -512;
      global_conf.magZero[i] = 0;
    }
    global_conf.grav = 512;
    global_conf.checksum = EEPROM::calculate_sum((uint8_t*)&global_conf, (sizeof(global_conf) - 1));
    EEPROM::writeGlobalSet(1);
    delay(10);
    return 1;
  } else
  {
    return 0;
  }
}

void EEPROM::readSenParams()
{
  eeprom_read_block((void*)&WS_params, (void*)(sizeof(global_conf)), sizeof(WS_params));
}

void EEPROM::writeGlobalSet(uint8_t b)
{
  global_conf.checksum = EEPROM::calculate_sum((uint8_t*)&global_conf, (sizeof(global_conf) - 1));
  eeprom_write_block((const void*)&global_conf, (void*)0, sizeof(global_conf));
}

void EEPROM::writeSenParams()
{
  eeprom_write_block((const void*)&WS_params, (void*)(sizeof(global_conf)), sizeof(WS_params));
}
