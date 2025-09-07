/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/kernel.h>
#include "fault_monitoring_module.h"
#include "statemachine.h"
#include "zephyr/device.h"
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>
#include <lib/motor/motor.h>
#include <fault_monitoring_module.h>
#include <zephyr/sys/reboot.h>
/* 1000 msec = 1 sec */
#define LED0_NODE DT_ALIAS(led0)
const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int main(void)
{
	const struct device *motor0 = DEVICE_DT_GET(DT_NODELABEL(motor0));
	const struct motor_data *m_data = motor0->data;
	gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE); /* 先点亮 */

	int ret;
	// float bus_volcurur[2];
	// fmm_t *bus_vol_fmm = m_data->fault[0];
	// fmm_t *buf_curr_fmm = m_data->fault[1];
	// fmm_init(bus_vol_fmm, 60.0f, 48.0f, 5, 5, NULL);
	// fmm_init(buf_curr_fmm, 5.0f, 0.0f, 5, 5, NULL);

	// static int16_t fault_fsm = 0;
	static uint32_t conut = 0;
	k_msleep(200);
	while (1) {
		if (conut++ > 500) {
			conut = 0;
			gpio_pin_toggle_dt(&led);
		}
		// motor_get_bus_voltage_current(motor0, &bus_volcurur[0], &bus_volcurur[1]);
		// motor_set_vol(motor0, bus_volcurur);

		// fmm_monitoring(bus_vol_fmm, bus_volcurur[0]);
		// fmm_monitoring(buf_curr_fmm, bus_volcurur[1]);

		DISPATCH_FSM(m_data->mode_state_mec);

		k_msleep(1);
	}
	return ret;
}
