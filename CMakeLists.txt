cmake_minimum_required(VERSION 3.5)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

set(EXTRA_COMPONENT_DIRS "src/main" "src/drivers" "src/utils" "src/pub" "src/externals")

project(ESP)
