#ifndef SERVO_HPP
#define SERVO_HPP

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/mcpwm_prelude.h"
#include "esp_system.h"
#include "esp_console.h"
#include "esp_vfs_dev.h"
#include "esp_vfs_fat.h"
#include "driver/uart.h"

#include "driver/adc.h"
#include "esp_adc_cal.h"

#include "ErrorCode.hpp"
#include "Thread.hpp"

class Servo : public Thread
{
    mcpwm_timer_config_t  sTimer;
    mcpwm_timer_handle_t  retTimer = NULL;

    mcpwm_operator_config_t configOperator;
    mcpwm_oper_handle_t retOper = NULL;

    mcpwm_comparator_config_t configComperator;
    mcpwm_cmpr_handle_t retCmpr = NULL;

    mcpwm_generator_config_t configGenerator;
    mcpwm_gen_handle_t retGen = NULL;
    int angle = 0;
    int step = 2;

public:
    Servo();
    ~Servo();
    ErrorCode init();
    void initPotentiometer();
    virtual void run();
    
};


#endif //Servo