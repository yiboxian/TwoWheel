// PID控制器结构体  
typedef struct 
{  
    float Kp;       // 比例系数  
    float Ki;       // 积分系数  
    float Kd;       // 微分系数  
    float setpoint; // 设定值  
    float integral; // 积分项  
    float prev_error; // 上一次误差  
} PID_Controller;  
 
// PID控制器初始化函数  
void PID_Init(PID_Controller *pid, float Kp, float Ki, float Kd, float setpoint) 
{  
    pid->Kp = Kp;  
    pid->Ki = Ki;  
    pid->Kd = Kd;  
    pid->setpoint = setpoint;  
    pid->integral = 0.0f;  
    pid->prev_error = 0.0f;  
}  
 
// PID控制器计算函数  
float PID_Compute(PID_Controller *pid, float measured_value) 
{  
    float error = pid->setpoint - measured_value; // 计算误差  
    pid->integral += error; // 更新积分项  
    float derivative = error - pid->prev_error; // 计算微分项  
    pid->prev_error = error; // 更新上一次误差  
    float output = pid->Kp * error + 
                   pid->Ki * pid->integral +
                   pid->Kd * derivative; // 计算PID输出  
    return output;  
}
/* 增量式PID控制器结构体  
 
typedef struct
 {  
    float Kp;       // 比例系数  
    float Ki;       // 积分系数  
    float Kd;       // 微分系数  
    float prev_error; // 上一次误差  
    float prev_prev_error; // 上上一次误差  
} IncrementalPID_Controller;  

// 增量式PID控制器初始化函数  
void IncrementalPID_Init(IncrementalPID_Controller *pid, float Kp, float Ki, float Kd) {  
    pid->Kp = Kp;  
    pid->Ki = Ki;  
    pid->Kd = Kd;  
    pid->prev_error = 0.0f;  
    pid->prev_prev_error = 0.0f;  
}  
 
// 增量式PID控制器计算函数  
float IncrementalPID_Compute(IncrementalPID_Controller *pid, float setpoint, float measured_value) 
{  
    float error = setpoint - measured_value; // 计算当前误差  
    float delta_error = error - pid->prev_error; // 计算误差变化量  
    float increment= pid->Kp * (error - pid->prev_error) +   
                      pid->Ki *  error +   
                      pid->Kd * (delta_error - pid->prev_prev_error); // 计算增量  
 
///也有资料的说增量式pid应该是这样的（微分项不同），我没有研究太深，这里贴出来，仅供参考
    float increment= pid->Kp *(pid.error-pid.error_next)+
                     pid->Ki *pid.error+
                     pid->Kd *(pid.error-2*pid.error_next+pid.error_last);  

    return increment; // 返回增量值  
} 
    */