#ifndef crazyflie_h
#define crazyflie_h

// Crazyflie utility variables
#include "utils/pin_names.h"
#include "utils/parameters.h"

// Crazyflie 2.0 hardware abstraction layer
// #include "drivers/mpu9250.h"    // IMU sensor

// Flow deck hardware abstraction layer
// #include "drivers/vl53l0x.h"    // Range sensor
// #include "drivers/pmw3901.h"    // Optical flow sensor

// Crazyflie 2.1 hardware abstraction layer
#include "drivers/bmi088.h"     // IMU sensor

// Flow deck v2 hardware abstraction layer
#include "drivers/vl53l1x.h"    // Range sensor
#include "drivers/pmw3901.h"    // Optical flow sensor

//mixer lab 06
#include "modules/mixer.h"

//estimador de alt lab 07
#include "modules/attitude_estimator.h"

//controlador de alt lab 08
#include "modules/attitude_controller.h"

//estimador vertical lab 09
#include "modules/vertical_estimator.h"

//controlador vert lab 10
#include "modules/vertical_controller.h" 

//estimador horiz lab 11
#include "modules/horizontal_estimator.h" 

//controlador horiz lab 12
#include "modules/horizontal_controller.h" 


#endif