#include <stdio.h>
#include <stdbool.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <ultrasonic.hpp>
#include <esp_err.h>

#ifndef ULTRASONICSENSOR_HPP
#define ULTRASONICSENSOR_HPP

class UltrasonicSensor
{
private:
    
public:
    UltrasonicSensor();
    ~UltrasonicSensor();
};


#endif //ULTRASONICSENSOR_HPP