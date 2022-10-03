set(COMPONENT_SRCS 
"Thread.cpp"
)

set(COMPONENT_ADD_INCLUDEDIRS 
$ENV{IDF_PATH}/components/newlib/platform_include
"."
)

register_component()