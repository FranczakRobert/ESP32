set(COMPONENT_SRCS 
"ultrasonic.cpp"
)

set(COMPONENT_ADD_INCLUDEDIRS 
$ENV{IDF_PATH}/components/driver/include
"."
)

register_component()
