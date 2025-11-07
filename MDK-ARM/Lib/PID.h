#ifndef ___PID_H_
#define ___PID_H_
typedef struct 
{  
    float Kp;       // 比例系数  
    float Ki;       // 积分系数  
    float Kd;       // 微分系数  
    float setpoint; // 设定值  
    float integral; // 积分项  
    float prev_error; // 上一次误差  
} PID_Controller; 
void PID_Init(PID_Controller *pid, float Kp, float Ki, float Kd, float setpoint);
float PID_Compute(PID_Controller *pid, float measured_value);
#endif // !___PID_H_
