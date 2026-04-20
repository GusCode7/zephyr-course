#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

/* LED0 está definido en el devicetree del nucleo_f429zi */
#define LED0_NODE DT_ALIAS(led0)
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int main(void)
{
    gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);

    while (1) {
        gpio_pin_toggle_dt(&led);
        k_sleep(K_MSEC(CONFIG_LED_BLINK_SLEEP));
    }
    return 0;
}
