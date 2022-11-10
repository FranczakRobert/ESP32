#include <stdio.h>
#include <unistd.h>
#include <cstdio>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "WifiDriver.hpp"
#include "Thread.hpp"
#include "Servo.hpp"
#include "Lcd.hpp"
#include "UltrasonicSensor.hpp"

extern "C"
{
    void app_main();
}

void app_main(void)
{
    // WifiDriver wifi;
    //Servo servo;
    // sleep(3);
    // wifi.startWifi();
    // Lcd lcd;
    // lcd.myDemo();
    // sleep(3);
    UltrasonicSensor ultrasonic;

    while (true)
    {
        usleep(10000);
    }
}