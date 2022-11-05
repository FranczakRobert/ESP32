#include "Servo.hpp"
#include "esp_log.h"
#define SERVO_TIMEBASE_RESOLUTION_HZ 1000000  // 1MHz, 1us per tick
#define SERVO_TIMEBASE_PERIOD        20000    // 20000 ticks, 20ms
#define SERVO_PIN 18

#define SERVO_MIN_PULSEWIDTH_US 500  // Minimum pulse width in microsecond
#define SERVO_MAX_PULSEWIDTH_US 2500  // Maximum pulse width in microsecond
#define SERVO_MIN_DEGREE        -90   // Minimum angle
#define SERVO_MAX_DEGREE        90    // Maximum angle

static const char *TAG = "Servo";

Servo::Servo()
{
    printf("Hi! I'm SERVO! \n");
    init();
    startThread();
};

Servo::~Servo(){};

static inline uint32_t example_angle_to_compare(int angle)
{
    return (angle - SERVO_MIN_DEGREE) * (SERVO_MAX_PULSEWIDTH_US - SERVO_MIN_PULSEWIDTH_US) / (SERVO_MAX_DEGREE - SERVO_MIN_DEGREE) + SERVO_MIN_PULSEWIDTH_US;
}

ErrorCode Servo::init()
{
    // TIMERS
    sTimer.group_id = 0;
    sTimer.clk_src = MCPWM_TIMER_CLK_SRC_DEFAULT;
    sTimer.resolution_hz = SERVO_TIMEBASE_RESOLUTION_HZ;
    sTimer.count_mode = MCPWM_TIMER_COUNT_MODE_UP;
    sTimer.period_ticks = SERVO_TIMEBASE_PERIOD;
    ESP_ERROR_CHECK(mcpwm_new_timer(&sTimer,&retTimer));

    // OPERATORS
    configOperator.group_id = 0;
    ESP_ERROR_CHECK(mcpwm_new_operator(&configOperator,&retOper));
    ESP_ERROR_CHECK(mcpwm_operator_connect_timer(retOper, retTimer));

    // COMPAEATORS
    configComperator.flags.update_cmp_on_tez = true;
    ESP_ERROR_CHECK(mcpwm_new_comparator(retOper,&configComperator,&retCmpr));

    // GENERATORS
    configGenerator.gen_gpio_num = SERVO_PIN;
    ESP_ERROR_CHECK(mcpwm_new_generator(retOper, &configGenerator,&retGen));

    ESP_ERROR_CHECK(mcpwm_comparator_set_compare_value(retCmpr, example_angle_to_compare(0)));

    ESP_LOGI(TAG, "Set generator action on timer and compare event");
    // go high on counter empty
    ESP_ERROR_CHECK(mcpwm_generator_set_actions_on_timer_event(retGen,
                    MCPWM_GEN_TIMER_EVENT_ACTION(MCPWM_TIMER_DIRECTION_UP, MCPWM_TIMER_EVENT_EMPTY, MCPWM_GEN_ACTION_HIGH),
                    MCPWM_GEN_TIMER_EVENT_ACTION_END()));
    // go low on compare threshold
    ESP_ERROR_CHECK(mcpwm_generator_set_actions_on_compare_event(retGen,
                    MCPWM_GEN_COMPARE_EVENT_ACTION(MCPWM_TIMER_DIRECTION_UP, retCmpr, MCPWM_GEN_ACTION_LOW),
                    MCPWM_GEN_COMPARE_EVENT_ACTION_END()));

    ESP_LOGI(TAG, "Enable and start timer");
    ESP_ERROR_CHECK(mcpwm_timer_enable(retTimer));
    ESP_ERROR_CHECK(mcpwm_timer_start_stop(retTimer, MCPWM_TIMER_START_NO_STOP));

    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    ESP_ERROR_CHECK(uart_driver_install(CONFIG_ESP_CONSOLE_UART_NUM, 256, 0, 0, NULL, 0));
    esp_vfs_dev_uart_use_driver(CONFIG_ESP_CONSOLE_UART_NUM);
    esp_vfs_dev_uart_port_set_rx_line_endings(CONFIG_ESP_CONSOLE_UART_NUM, ESP_LINE_ENDINGS_CR);
    esp_vfs_dev_uart_port_set_tx_line_endings(CONFIG_ESP_CONSOLE_UART_NUM, ESP_LINE_ENDINGS_CRLF);

    return E_OK;
}

void Servo::run()
{
    ESP_LOGI(TAG, "Angle of rotation: %d", angle);
    ESP_ERROR_CHECK(mcpwm_comparator_set_compare_value(retCmpr, example_angle_to_compare(angle)));
    //Add delay, since it takes time for servo to rotate, usually 200ms/60degree rotation under 5V power supply
    vTaskDelay(pdMS_TO_TICKS(10));
    // if ((angle + step) > 90 || (angle + step) < -90) {
    //     step *= -1;
    // }
    //  angle += step;
    scanf("%d",&angle);
}
