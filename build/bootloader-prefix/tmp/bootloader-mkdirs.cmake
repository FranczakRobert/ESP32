# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/robertfranczak/esp/esp-idf/components/bootloader/subproject"
  "/Users/robertfranczak/Code/ESP32/ESP/build/bootloader"
  "/Users/robertfranczak/Code/ESP32/ESP/build/bootloader-prefix"
  "/Users/robertfranczak/Code/ESP32/ESP/build/bootloader-prefix/tmp"
  "/Users/robertfranczak/Code/ESP32/ESP/build/bootloader-prefix/src/bootloader-stamp"
  "/Users/robertfranczak/Code/ESP32/ESP/build/bootloader-prefix/src"
  "/Users/robertfranczak/Code/ESP32/ESP/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/robertfranczak/Code/ESP32/ESP/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/robertfranczak/Code/ESP32/ESP/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
