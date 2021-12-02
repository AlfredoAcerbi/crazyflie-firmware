#include "mixer.h"

Mixer::Mixer() : motor_1(MOTOR1) , motor_2(MOTOR2) , motor_3(MOTOR3) , motor_4(MOTOR4)
{
    motor_1.period(1.0/500);
    motor_2.period(1.0/500);
    motor_3.period(1.0/500);
    motor_4.period(1.0/500);
    motor_1 = 0.0;
    motor_2 = 0.0;
    motor_3 = 0.0;
    motor_4 = 0.0;
}

void Mixer::arm()
{
  estado = true;
}
void Mixer::desarm()
{
    estado = false;
    motor_1 = 0.0;
    motor_2 = 0.0;
    motor_3 = 0.0;
    motor_4 = 0.0;

}

//actuate motors with desired N and N.m
void Mixer::actuate(float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    if (estado == true) {
    mixer(f_t , tau_phi , tau_theta , tau_psi);
    motor_1 = control_motor(omega_1);
    motor_2 = control_motor(omega_2);
    motor_3 = control_motor(omega_3);
    motor_4 = control_motor(omega_4);
    }
}

//convert N and N.m to rad/s
void Mixer::mixer(float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    float a = 1/(4*kl);
    float b = 1/(4*kl*l);
    float c = 1/(4*kd);
    omega_1 = sqrt(a*f_t - b*tau_phi - b*tau_theta - c*tau_psi);
    omega_2 = sqrt(a*f_t - b*tau_phi + b*tau_theta + c*tau_psi);
    omega_3 = sqrt(a*f_t + b*tau_phi + b*tau_theta - c*tau_psi);
    omega_4 = sqrt(a*f_t + b*tau_phi - b*tau_theta + c*tau_psi);
}

//convert rad/s to PWM
float Mixer::control_motor(float omega)
{
    float PWM = (a2*pow(omega, 2)) + (a1*omega);
    return PWM;
}