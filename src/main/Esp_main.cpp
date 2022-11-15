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
#include "Router.hpp"

extern "C"
{
    void app_main();
}

void app_main(void)
{
    Router router;
    // WifiDriver wifi;
    //Servo servo;
    // sleep(3);
    // wifi.startWifi();
    // lcd.myDemo();
    // sleep(3);
    UltrasonicSensor ultrasonic(router);
    Lcd lcd(router);

    while (true)
    {
        usleep(10000);
    }
}