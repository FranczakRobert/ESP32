#include <stdio.h>
#include <stdbool.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <ultrasonic.hpp>
#include <esp_err.h>
#include "Thread.hpp"

#ifndef ULTRASONICSENSOR_HPP
#define ULTRASONICSENSOR_HPP

class UltrasonicSensor : public Thread
{
private:
    ultrasonic_sensor_t sensor;
    void init();
    
public:
    UltrasonicSensor();
    ~UltrasonicSensor();

    void virtual run();
};


#endif //ULTRASONICSENSOR_HPP