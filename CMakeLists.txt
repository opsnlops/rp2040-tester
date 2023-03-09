cmake_minimum_required(VERSION 3.13)

# Pull in the Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Pull in FreeRTOS
include($ENV{FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

project(rp2040-tester C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

# Set up our includes
include_directories(
        src/
        generated/
        )

# Our source files
file(GLOB sourceFiles
        src/*
        )

add_executable(rp2040-tester
        ${sourceFiles}
        FreeRTOSConfig.h
        )

target_include_directories(rp2040-tester PRIVATE
        .
        ${CMAKE_CURRENT_LIST_DIR}
        )

# pull in common dependencies
target_link_libraries(rp2040-tester
        FreeRTOS-Kernel
        FreeRTOS-Kernel-Heap4
        hardware_dma
        hardware_gpio
        hardware_pio
        hardware_pwm
        hardware_uart
        pico_stdlib
        pico_unique_id
        )

pico_enable_stdio_usb(rp2040-tester 1)
pico_enable_stdio_uart(rp2040-tester 0)

# Create all of the files
pico_add_extra_outputs(rp2040-tester)
