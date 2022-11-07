#ifndef LCD_HPP
#define LCD_HPP
#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_log.h"
#include "driver/i2c.h"
#include "ErrorCode.hpp"
#include "unistd.h"
#define SLAVE_ADDRESS_LCD 0x27

#define I2C_NUM I2C_NUM_0
class Lcd
{
private:
    i2c_config_t conf;
    esp_err_t i2c_master_init();
    void lcd_send_cmd (char cmd);
    void lcd_send_data (char data);
    void lcd_clear (void);
    void lcd_put_cur(int row, int col);
    void lcd_init (void);
    void lcd_send_string (char *str);

public:
    Lcd();
    ~Lcd();
    void myDemo();
};


#endif //LCD_HPP
