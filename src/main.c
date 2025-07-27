/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS 1
#define LED0_NODE     DT_ALIAS(led0)
const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
// extern int can_init(void);
int main(void)
{
	gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE); /* 先点亮 */
	printk("hello world! %s\n", CONFIG_BOARD);
	while (1) {
		gpio_pin_toggle_dt(&led);
		k_msleep(50);
	}
	return 0;
}
