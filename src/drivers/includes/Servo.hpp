#ifndef SERVO_HPP
#define SERVO_HPP

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_attr.h"
#include "esp_check.h"
#include "esp_private/esp_clk.h"
#include "ErrorCode.hpp"
#include "esp_log.h"
#include "mcpwm_prelude.h"

class Servo
{
public:
    Servo();
    ~Servo();

    void run();
    
};


#endif //Servo