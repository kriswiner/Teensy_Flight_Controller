#ifndef Globals_h
#define Globals_h

#include "def.h"
#include "Types.h"

// General purpose variables
int16_t                                 serial_input;
static int16_t                          warm_start = 0;
static int16_t                          warm_start_saved = 0;

// Specify BMP280 configuration
uint8_t                                 Posr = P_OSR_16;
uint8_t                                 Tosr = T_OSR_02;
uint8_t                                 Mode = normal;
uint8_t                                 IIRFilter = BW0_042ODR;
uint8_t                                 SBy = t_62_5ms;

// t_fine carries fine temperature as global value for BMP280
int32_t                                 t_fine;

// Specify sensor full scale
uint8_t                                 Gscale = GFS_250DPS;
uint8_t                                 Ascale = AFS_2G;

// Choose either 14-bit or 16-bit magnetometer resolution
uint8_t                                 Mscale = MFS_16BITS;

// 2 for 8 Hz, 6 for 100 Hz continuous magnetometer data read
uint8_t                                 Mmode = 0x02;

// scale resolutions per LSB for the sensors
float                                   aRes;
float                                   gRes;
float                                   mRes;

// Pin definitions
// These can be changed, 2 and 3 are the Arduinos ext int pins
int                                     intPin = 8;

// LED on the Teensy 3.1
int                                     myLed = 13;

// BMP280 compensation parameters
uint16_t                                dig_T1;
uint16_t                                dig_P1;
int16_t                                 dig_T2;
int16_t                                 dig_T3;
int16_t                                 dig_P2;
int16_t                                 dig_P3;
int16_t                                 dig_P4;
int16_t                                 dig_P5;
int16_t                                 dig_P6;
int16_t                                 dig_P7;
int16_t                                 dig_P8;
int16_t                                 dig_P9;

// stores BMP280 pressures sensor pressure and temperature
double                                  Temperature;
double                                  Pressure;

// pressure and temperature raw count output for BMP280
int32_t                                 rawPress;
int32_t                                 rawTemp;

// MPU9250 variables
// Stores the 16-bit signed accelerometer sensor output
int16_t                                 accelCount[3];

// Stores the 16-bit signed gyro sensor output
int16_t                                 gyroCount[3];

// Stores the 16-bit signed magnetometer sensor output
int16_t                                 magCount[3];

// quaternion data register
float                                   Quat[4] = {0, 0, 0, 0};

// Factory mag calibration and mag bias
float                                   magCalibration[3] = {0, 0, 0};

// Bias corrections for gyro, accelerometer, mag
float                                   gyroBias[3] = {0, 0, 0};
float                                   accelBias[3] = {0, 0, 0};
float                                   magBias[3] = {0, 0, 0};
float                                   magScale[3]  = {0, 0, 0};

// Pressure, temperature raw count output
int16_t                                 tempCount;
int16_t                                 rawPressure;
int16_t                                 rawTemperature;

// Stores the MPU9250 internal chip temperature in degrees Celsius
float                                   temperature;
float                                   pressure;
float                                   altitude;

// holds results of gyro and accelerometer self test
float SelfTest[6];

// Global constants for 9 DoF fusion and AHRS (Attitude and Heading Reference System)
// Gyroscope measurement error in rads/s (start at 40 deg/s)
float                                   GyroMeasError = PI * (40.0f / 180.0f);

// Gyroscope measurement drift in rad/s/s (start at 0.0 deg/s/s)
float                                   GyroMeasDrift = PI * (0.0f  / 180.0f);

// There is a tradeoff in the beta parameter between accuracy and response speed.
// In the original Madgwick study, beta of 0.041 (corresponding to GyroMeasError of 2.7 degrees/s) was found to give optimal accuracy.
// However, with this value, the LSM9SD0 response time is about 10 seconds to a stable initial quaternion.
// Subsequent changes also require a longish lag time to a stable output, not fast enough for a quadcopter or robot car!
// By increasing beta (GyroMeasError) by about a factor of fifteen, the response time constant is reduced to ~2 sec
// I haven't noticed any reduction in solution accuracy. This is essentially the I coefficient in a PID control sense; 
// the bigger the feedback coefficient, the faster the solution converges, usually at the expense of accuracy. 
// In any case, this is the free parameter in the Madgwick filtering and fusion scheme.

// Compute beta
float                                   beta = sqrt(3.0f / 4.0f) * GyroMeasError;

// Compute zeta, the other free parameter in the Madgwick scheme usually set to a small or zero value
float                                   zeta = sqrt(3.0f / 4.0f) * GyroMeasDrift;

// Used to control display output rate
uint32_t                                delt_t = 0;
uint32_t                                count = 0;
uint32_t                                sumCount = 0;
float                                   pitch;
float                                   yaw;
float                                   roll;
float                                   Yaw;
float                                   Pitch;
float                                   Roll;

// Integration interval for both filter schemes
float                                   deltat = 0.0f;
float                                   sum = 0.0f;

// used to calculate integration interval
uint32_t                                lastUpdate = 0;
uint32_t                                firstUpdate = 0;

// used to calculate integration interval
uint32_t                                Now = 0;

// used for param transfer
uint8_t                                 param[4];

// EM7180 sensor full scale ranges
uint16_t                                EM7180_mag_fs;
uint16_t                                EM7180_acc_fs;
uint16_t                                EM7180_gyro_fs;

// variables to hold latest sensor data values 
float                                   ax;
float                                   ay;
float                                   az;
float                                   gx;
float                                   gy;
float                                   gz;
float                                   mx;
float                                   my;
float                                   mz;

// Vector to hold quaternion
float                                   q[4] = {1.0f, 0.0f, 0.0f, 0.0f};

// Vector to hold integral error for Mahony method
float                                   eInt[3] = {0.0f, 0.0f, 0.0f};

global_conf_t                           global_conf;
Sentral_WS_params                       WS_params;

#endif // Globals_h
