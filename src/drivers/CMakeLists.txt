set(COMPONENT_SRCS 
"src/WifiDriver.cpp"
"src/Servo.cpp"
"src/Lcd.cpp"

)

set(COMPONENT_ADD_INCLUDEDIRS 
$ENV{IDF_PATH}/components/nvs_flash/include
$ENV{IDF_PATH}/components/spi_flash/include
$ENV{IDF_PATH}/components/esp_event/include
$ENV{IDF_PATH}/components/esp_wifi/include
$ENV{IDF_PATH}/components/esp_netif/include
$ENV{IDF_PATH}/components/driver/include/driver
$ENV{IDF_PATH}/components/driver/include
$ENV{IDF_PATH}/components/console
$ENV{IDF_PATH}/components/vfs/include
$ENV{IDF_PATH}/components/fatfs/vfs
$ENV{IDF_PATH}/components/fatfs/src
$ENV{IDF_PATH}/components/wear_levelling/include
$ENV{IDF_PATH}/components/esp_ringbuf/include
$ENV{IDF_PATH}/components/driver/deprecated
$ENV{IDF_PATH}/components/esp_adc/deprecated/include

"includes"
"../utils"
)

register_component()