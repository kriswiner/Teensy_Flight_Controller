#ifndef types_h
#define types_h

/*************************************************************************************************/
/*************                                                                     ***************/
/*************                 Enumerators and Structure Variables                 ***************/
/*************                                                                     ***************/
/*************************************************************************************************/

// Set initial input parameters
enum Ascale {
  AFS_2G = 0,
  AFS_4G,
  AFS_8G,
  AFS_16G
};

enum Gscale {
  GFS_250DPS = 0,
  GFS_500DPS,
  GFS_1000DPS,
  GFS_2000DPS
};

enum Mscale {
  MFS_14BITS = 0, // 0.6 mG per LSB
  MFS_16BITS      // 0.15 mG per LSB
};

enum Posr {
  P_OSR_00 = 0,  // no op
  P_OSR_01,
  P_OSR_02,
  P_OSR_04,
  P_OSR_08,
  P_OSR_16
};

enum Tosr {
  T_OSR_00 = 0,  // no op
  T_OSR_01,
  T_OSR_02,
  T_OSR_04,
  T_OSR_08,
  T_OSR_16
};

enum IIRFilter {
  full = 0,  // bandwidth at full sample rate
  BW0_223ODR,
  BW0_092ODR,
  BW0_042ODR,
  BW0_021ODR // bandwidth at 0.021 x sample rate
};

enum Mode {
  BMP280Sleep = 0,
  forced,
  forced2,
  normal
};

enum SBy {
  t_00_5ms = 0,
  t_62_5ms,
  t_125ms,
  t_250ms,
  t_500ms,
  t_1000ms,
  t_2000ms,
  t_4000ms,
};

struct global_conf_t
{
  uint8_t currentSet;
  int16_t accZero_max[3];
  int16_t accZero_min[3];
  int16_t magZero[3];
  int16_t grav;
  uint8_t checksum; // Last position in structure
};

struct Sentral_WS_params
{
  uint8_t Sen_param[35][4];
};

#endif // types_h
