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
extern void *as5047_readangle(void);

int main(void)
{
	gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE); /* 先点亮 */
	printk("hello world! %s\n", CONFIG_BOARD);
	k_msleep(500);
	while (1) {
		gpio_pin_toggle_dt(&led);
		as5047_readangle();
		k_msleep(500);
	}
	return 0;
}
