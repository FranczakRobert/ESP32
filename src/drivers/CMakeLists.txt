set(COMPONENT_SRCS 
"src/WifiDriver.cpp"
)

set(COMPONENT_ADD_INCLUDEDIRS 
$ENV{IDF_PATH}/components/nvs_flash/include
$ENV{IDF_PATH}/components/spi_flash/include
$ENV{IDF_PATH}/components/esp_event/include
$ENV{IDF_PATH}/components/esp_wifi/include
$ENV{IDF_PATH}/components/esp_netif/include

"includes"
"../utils"
)

register_component()