#ifndef EEPROM_h
#define EEPROM_h

#include "def.h"
#include "avr/eeprom.h"
#include "Types.h"

extern struct global_conf_t             global_conf;
extern struct Sentral_WS_params         WS_params;
extern int32_t                          debug[4];

class EEPROM
{
  public:
                                        EEPROM();
     uint8_t                            readGlobalSet();
     void                               writeGlobalSet(uint8_t b);
     void                               writeParams(uint8_t b);
     void                               writeSenParams();
     void                               readSenParams();
  private:
     uint8_t                            calculate_sum(uint8_t *cb , uint8_t siz);
};

#endif // EEPROM_h
