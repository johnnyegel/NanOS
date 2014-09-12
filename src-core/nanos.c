/**
 * NanOS - A tiny OS for limited CPUs
 * 
 * Nano provides a simple task scheduler which handles task execution
 * at specific intervals or patterns.
 */

#include <stdio.h> // TODO: Remove this!

#include <stddef.h>
#include <stdint.h>
#include "nanos.h"

// Keeps tasks for global access
static const NanOSTaskList *_normalTaskList;
static const NanOSTaskList *_realtimeTaskList;

// The tick counter
static unsigned int _tickCount = 0;

/**
 * Called to boot NanOS. The method blocks indefinitly.
 */
void nanosBootStrap(const NanOSTaskList *normalTaskList, const NanOSTaskList *realTimeTaskList) {
	// Simply keep the pointers to the task lists
	_normalTaskList = normalTaskList;
	_realtimeTaskList = realTimeTaskList;
}

/**
 * Inline function used to process the execution flags of a taskList
 */
inline static bool _nanosProcessTaskListSchedule(const NanOSTaskList *taskList) {
	bool isExecution = false;

	unsigned int tix;
	for (tix = 0; tix < taskList->count; tix ++) {
		// Check if we need to set the execution flag
		if (taskList->tasks[tix].next != _tickCount) continue;

		// This task should be executed, so set execution flag
		taskList->tasks[tix].doExecute = true;
		isExecution = true;
	}

	return isExecution;
}


/**
 * Called by the tick interrupt to process task execution and scheduling
 */
inline void _nanosProcessTick() {
	// Increase the tick counter
	++_tickCount;

	// First process execution flags for real time tasks
	if (_nanosProcessTaskListSchedule(_realtimeTaskList)) {
		// Process real time task execution immediately
	}

	// Then process the normal task execution flags
	_nanosProcessTaskListSchedule(_normalTaskList);
}

/**
 * The main loop of NanOS. This executes normal tasks and dispatch events.
 */
void _nanosMainLoop() {

}

