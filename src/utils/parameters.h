#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m

//a1 e a2 lab 2 parametros do motor
const float a1 = 3.274e-12;
const float a2 = 1.174e-07;

//lab 3 constante de sustentação N.s^2
const float kl = 1.726e-08;

//lab 4  a constante de arrasto N.m.s^2
const float kd = 1.351e-10;

//lab 7
const float wc = 1.0; 
const float dt = 1.0/500.0; 
const float alfa = wc*dt/(1+wc*dt);

//lab 8
const float kp_phi = 240.28;
const float kd_phi = 26.67;
const float kp_theta = 240.28;
const float kd_theta = 26.678;
const float kp_psi = 60.07;
const float kd_psi = 13.33;

//lab 9
const float dt_2 = 1.0/20.0; //20hz
const float wc_2 = 10.0;
const float zeta = sqrt(2) / 2.0;
const float l1 =  wc_2*wc_2;
const float l2 = 2.0*zeta*wc_2;

const float dt_range = 1.0/20.0;

//lab 10
//formulas na aula 8 c OS de 0.005 e TS de 2
//zeta=0.86; wn = 2.33; 
const float kd_lab10 = 4.0;
const float kp_lab10 = 5.4083;

//lab 11
const float radiano = 84*pi/360.0;
const float sigma = (2*tan(radiano/2.0))/(420*dt);

//lab 12
const float kd_lab12 = 4.0;
const float kp_lab12 = 5.4083;


#endif