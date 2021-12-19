cmake_minimum_required(VERSION 3.19)

# initialize the SDK based on PICO_SDK_PATH
include(pico_sdk_import.cmake)
project(output)

# initialize the Pico SDK
pico_sdk_init()

add_executable(output
    src/main.c
)

FILE(GLOB FreeRTOS_src FreeRTOS-Kernel/*.c)

add_library( FreeRTOS STATIC
	${FreeRTOS_src}
	FreeRTOS-Kernel/portable/GCC/ARM_CM0/port.c
	FreeRTOS-Kernel/portable/MemMang/heap_4.c
)

target_include_directories( FreeRTOS PUBLIC
		FreeRTOS-Kernel/include
		include/
		FreeRTOS-Kernel/portable/GCC/ARM_CM0
	)

target_link_libraries( output 
	pico_stdlib 
	hardware_gpio 
	FreeRTOS
	)

	
pico_add_extra_outputs(output)
pico_enable_stdio_usb(output 1)