#include "mbed.h"
#include "crazyflie.h"

Mixer mixer;

int main()
{
    wait(3);
    mixer.arm();
    mixer.actuate(0.7*m*g , 0 , 0 , 0);
    wait(5);
    mixer.desarm();
    mixer.actuate(0 , 0 , 0 , 0);
    while(true)
    {
    }
}