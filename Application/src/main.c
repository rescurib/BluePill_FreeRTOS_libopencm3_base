#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

int main(void) {
    // Enable the clock for GPIOC (where the LED is connected on PC13)
    rcc_periph_clock_enable(RCC_GPIOC);

    // Set GPIO13 (PC13) to output mode, push-pull
    gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
                  GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);

    while (1) {
        // Toggle the LED (PC13)
        gpio_toggle(GPIOC, GPIO13);

        // Simple delay loop
        for (int i = 0; i < 800000; i++) {
            __asm__("nop"); // Do nothing
        }
    }

    return 0;
}
