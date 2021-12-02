# include "attitude_estimator.h"
// Class constructor
AttitudeEstimator::AttitudeEstimator() : imu(IMU_SDA , IMU_SCL)
{
    phi = 0.0;
    theta = 0.0;
    psi = 0.0;
    p = 0.0;
    q = 0.0;
    r = 0.0;
}
// Initialize class
void AttitudeEstimator::init()
{
    imu.init();

    for(int i=0; i<500;i++)

    {
        imu.read();
        pbias = pbias + (imu.gx/500);
        qbias = qbias + (imu.gy/500);
        rbias = rbias + (imu.gz/500);
        wait(dt);
    }
}

// Estimate Euler angles (rad ) and angular velocities ( rad /s)
void AttitudeEstimator::estimate()
{
    imu.read();

    //para o angulo phi: 
    float phi_anterior = phi;
    float theta_anterior = theta;
    float psi_anterior = psi;

    p = imu.gx - pbias;
    q = imu.gy - qbias;
    r = imu.gz - rbias;
    
    float phi_a = atan2(-imu.ay, -imu.az);
    float phi_g = phi_anterior + ( p + sin(phi_anterior)*tan(theta_anterior)*q + cos(phi_anterior)*tan(theta_anterior)*r )*dt;
    phi = (1-alfa)*phi_g + alfa*phi_a;

    //para theta:
    
    
    float theta_a = atan2(imu.ax, -((imu.az>0)-(imu.az<0))*sqrt(pow(imu.ay,2) + pow(imu.az,2)) );
    float theta_g = theta_anterior + ( cos(phi_anterior)*q - sin(phi_anterior)*r )*dt;
    theta = (1-alfa)*theta_g + alfa*theta_a;

    //para psi:
    
    float psi_g = psi_anterior + ( sin(phi_anterior)*(1/cos(theta_anterior))*q + cos(phi_anterior)*(1/cos(theta_anterior))*r )*dt;
    psi = psi_g;

}