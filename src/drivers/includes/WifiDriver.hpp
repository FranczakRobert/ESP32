#ifndef WIFIDRIVER_HPP
#define WIFIDRIVER_HPP
#include <cstdio>
#include <mutex>
#include <unistd.h>


#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/event_groups.h>
#include <esp_system.h>
#include <esp_log.h>
#include <nvs_flash.h>
#include <esp_event.h>
#include <esp_wifi.h>

#include "ErrorCode.hpp"

    static EventGroupHandle_t s_wifi_event_group;
    static const char *TAG = "wifi station";
    static int s_retry_num = 0;

class WifiDriver
{
private:
    static void event_handler(void* arg, esp_event_base_t event_base,int32_t event_id, void* event_data);
    void wifi_init_sta(void);
public:
    WifiDriver();
    ~WifiDriver();
    void startWifi();
    
};


#endif //WIFIDRIVER_HPP