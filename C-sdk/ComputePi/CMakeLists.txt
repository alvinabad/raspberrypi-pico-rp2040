cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(pico_computepi C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

if (TARGET tinyusb_device)
    add_executable(computepi
        computepi.c
    )

    # Pull in our pico_stdlib which pulls in commonly used features
    target_link_libraries(computepi pico_stdlib)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(computepi 1)
    pico_enable_stdio_uart(computepi 0)

    # create map/bin/hex file etc.
    pico_add_extra_outputs(computepi)
elseif(PICO_ON_DEVICE)
    message(WARNING "not building computepi because TinyUSB submodule is not initialized in the SDK")
endif()
