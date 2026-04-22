#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

/* Ahora usamos el alias app-led */
#define LED0_NODE DT_ALIAS(app_led)
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int main(void)
{
    gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);

    while (1) {
        gpio_pin_toggle_dt(&led);
        k_sleep(K_MSEC(CONFIG_APP_HEARTBEAT_PERIOD_MS));
    }
    return 0;
}