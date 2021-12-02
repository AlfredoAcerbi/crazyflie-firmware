#ifndef mixer_h
#define mixer_h

#include "mbed.h"
#include "crazyflie.h"

class Mixer
{
    public:
    Mixer();
        //actuate motors with desired total trust force (N) and torques (N.m)
        void actuate(float f_t , float tau_phi , float tau_theta , float tau_psi);

        //arm e desarm
        void arm();
        void desarm();

    private:
        //motors PWM outputs
        PwmOut motor_1, motor_2, motor_3, motor_4;
        //angular vel (rad/s)
        float omega_1, omega_2, omega_3, omega_4;
        //convert N and N.m to rad/s
        void mixer (float f_t , float tau_phi , float tau_theta , float tau_psi);
        //convert rad/s to PWM
        float control_motor(float omega);

        bool estado;
    
};

#endif