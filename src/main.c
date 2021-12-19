#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/gpio.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

void Serial500(void *param)
{
    while (true)
    {
        printf("500");
        vTaskDelay(500);
    }
}

void Serial1500(void *param)
{
    while (true)
    {
        printf("1500");
        vTaskDelay(1500);
    }
}


int main()
{
    stdio_init_all();

    uint32_t status = xTaskCreate(
        Serial500,
        "500",
        1024,
        NULL,
        tskIDLE_PRIORITY,
        NULL);

    status = xTaskCreate(
        Serial1500,
        "1500",
        1024,
        NULL,
        1,
        NULL);

    vTaskStartScheduler();

    for (;;)
    {
        //should never get here
    }
}
