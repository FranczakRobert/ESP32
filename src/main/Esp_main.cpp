#include <stdio.h>
#include <unistd.h>
#include <cstdio>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "WifiDriver.hpp"
#include "Thread.hpp"
#include "Servo.hpp"

extern "C"
{
    void app_main();
}

void app_main(void)
{
    //WifiDriver wifi;
    //Thread thread;

    //wifi.startWifi();
    Servo servo;
    
    while (true)
    {
        usleep(10000);
    }
}