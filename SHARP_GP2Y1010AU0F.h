#ifndef SHARP_GP2Y1010AU0F_H
#define SHARP_GP2Y1010AU0F_H

#include "SensorGrid.h"

#define DUST_SENSOR_LED_POWER 12
#define DUST_SENSOR_SAMPLING_TIME 280
#define DUST_SENSOR_DELTA_TIME 40
#define DUST_SENSOR_SLEEP_TIME 9680
#define DUST_SENSOR_VCC 3.3
#define DUST_SENSOR_LED_ON LOW
#define DUST_SENSOR_LED_OFF HIGH

extern float dustSenseVoMeasured;
extern float dustSenseCalcVoltage;
extern float dustDensity;
extern uint8_t SHARP_GP2Y1010AU0F_DUST_PIN;

void setupDustSensor();
float readDustSensor();

#endif