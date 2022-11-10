#if !defined(__ESP_IDF_LIB_HELPERS__H__)
#define __ESP_IDF_LIB_HELPERS__H__

#include <freertos/FreeRTOS.h>
#include <esp_idf_version.h>

#if !defined(ESP_IDF_VERSION) || !defined(ESP_IDF_VERSION_VAL)
#error Unknown ESP-IDF/ESP8266 RTOS SDK version
#endif

#define HELPER_ESP32_MIN_VER    ESP_IDF_VERSION_VAL(3, 3, 5)
#define HELPER_ESP8266_MIN_VER  ESP_IDF_VERSION_VAL(3, 3, 0)

#if defined(CONFIG_IDF_TARGET_ESP32) \
        || defined(CONFIG_IDF_TARGET_ESP32S2) \
        || defined(CONFIG_IDF_TARGET_ESP32S3) \
        || defined(CONFIG_IDF_TARGET_ESP32C3)
#define HELPER_TARGET_IS_ESP32     (1)
#define HELPER_TARGET_IS_ESP8266   (0)

#elif defined(CONFIG_IDF_TARGET_ESP8266)
#define HELPER_TARGET_IS_ESP32     (0)
#define HELPER_TARGET_IS_ESP8266   (1)
#else
#error BUG: cannot determine the target
#endif

#if HELPER_TARGET_IS_ESP32 && ESP_IDF_VERSION < HELPER_ESP32_MIN_VER
#error Unsupported ESP-IDF version. Please update!
#endif

#if HELPER_TARGET_IS_ESP8266 && ESP_IDF_VERSION < HELPER_ESP8266_MIN_VER
#error Unsupported ESP8266 RTOS SDK version. Please update!
#endif

#if DEBUG
#define VALUE_TO_STRING(x) #x
#define VALUE(x) VALUE_TO_STRING(x)
#define VAR_NAME_VALUE(var) #var "="  VALUE(var)
#pragma message(VAR_NAME_VALUE(CONFIG_IDF_TARGET_ESP32C3))
#pragma message(VAR_NAME_VALUE(CONFIG_IDF_TARGET_ESP32S2))
#pragma message(VAR_NAME_VALUE(CONFIG_IDF_TARGET_ESP32))
#pragma message(VAR_NAME_VALUE(CONFIG_IDF_TARGET_ESP8266))
#pragma message(VAR_NAME_VALUE(ESP_IDF_VERSION_MAJOR))
#endif

#endif