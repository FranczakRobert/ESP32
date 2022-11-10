set(COMPONENT_SRCS 
"ultrasonic.cpp"
)

set(COMPONENT_ADD_INCLUDEDIRS 
$ENV{IDF_PATH}/components/driver/include
$ENV{IDF_PATH}/components/esp_timer/include
$ENV{IDF_PATH}/components/esp_rom/include/esp32/rom/
"."
)

register_component()
