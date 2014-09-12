/*
 * ledblink.c
 *
 *	Simple NanOS example creating a task that blinks a LED
 *
 *  Created on: Sep 10, 2014
 *      Author: johnny
 */

#include <stddef.h>
#include <stdbool.h>
#include <nanos.h>

/**
 * Task function that toggles the LED state
 */
void blinkLedTask(void) {
	static bool ledstate = false;
	ledstate = !ledstate;

	// TODO: Implement LED driver for this example to work.
	//       Call Set LED function
}

// Define task list
NANOS_TASKLIST(taskList, {
	NANOS_TASK(blinkLedTask, 1000, 0)
});


int main(void) {
	// Bootstrap our OS
	nanosBootStrap(taskList, NULL);
	return 0;
}
