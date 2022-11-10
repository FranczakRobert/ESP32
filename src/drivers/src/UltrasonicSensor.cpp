#include "UltrasonicSensor.hpp"
#include "ultrasonic.hpp"

#define MAX_DISTANCE_CM 200
#define TRIGGER_GPIO 5
#define ECHO_GPIO 18
#define DIVISOR_CM 58
UltrasonicSensor::UltrasonicSensor(){init(); startThread();}
UltrasonicSensor::~UltrasonicSensor(){stopThread();}

void UltrasonicSensor::init()
{
        sensor.trigger_pin = static_cast<gpio_num_t>(TRIGGER_GPIO);
        sensor.echo_pin = static_cast<gpio_num_t>(ECHO_GPIO);

    ultrasonic_init(&sensor);

}

void UltrasonicSensor::run()
{
        uint32_t distance;
        esp_err_t res = ultrasonic_measure_raw(&sensor, MAX_DISTANCE_CM * DIVISOR_CM, &distance);
        // if (res != ESP_OK)
        // {
        //     printf("Error %d: ", res);
        //     switch (res)
        //     {
        //         case ESP_ERR_ULTRASONIC_PING:
        //             printf("Cannot ping (device is in invalid state)\n");
        //             break;
        //         case ESP_ERR_ULTRASONIC_PING_TIMEOUT:
        //             printf("Ping timeout (no device found)\n");
        //             break;
        //         case ESP_ERR_ULTRASONIC_ECHO_TIMEOUT:
        //             printf("Echo timeout (i.e. distance too big)\n");
        //             break;
        //         default:
        //             printf("%s\n", esp_err_to_name(res));
        //     }
        // }
        // else
        if(distance/100 < 200)
            printf("Distance: %lu cm\n", distance/100);

        vTaskDelay(pdMS_TO_TICKS(500));
}