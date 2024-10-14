#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include "FreeRTOS.h"
#include "task.h"

static void led_blink_handler(void* parameters);

int main(void) {

    // -- Estructuras de tareas --
    TaskHandle_t task_1_handle;
    BaseType_t   status;

    // -- Inicialización de HAL --

    rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE8_72MHZ]);

    // Enable the clock for GPIOC (where the LED is connected on PC13)
    rcc_periph_clock_enable(RCC_GPIOC);

    // Set GPIO13 (PC13) to output mode, push-pull
    gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
                  GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);

    status = xTaskCreate(led_blink_handler,"Led Blink",16,NULL,2,&task_1_handle);
    configASSERT(status == pdPASS);

    vTaskStartScheduler();

    while (1) 
    {
       // loop
    }

    return 0;
}

static void led_blink_handler(void* parameters)
{
    // Toggle the LED (PC13)
    gpio_toggle(GPIOC, GPIO13);

    // delay
    vTaskDelay(pdMS_TO_TICKS(1000));
}
