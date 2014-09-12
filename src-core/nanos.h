/**
 * NanOS - A tiny OS for limited CPUs
 * 
 * Nano provides a simple task scheduler which handles task execution
 * at specific intervals or patterns.
 */

#include <stdbool.h>
#include <stdint.h>


/**
 * Counts the number of tasks in a given task list
 */
#define NANOS_COUNT_TASKS(taskList)	(unsigned int)(sizeof(taskList) / sizeof(NanOSTask))

/**
 * Macro used to define a Task list with the given variable name.
 *
 * Task lists are provided to the nanosBootStrap function, which takes up
 * to two lists; a Normal task list and a Real-Time task list.
 *
 * Tasks in a normal task list is executed as close as possible to the specified
 * schedule. Tasks scheduled at the same Tick will be executed, but in sequence.
 *
 * Any Real Time tasks in the list will be executed within the Tick interrupt,
 * and thus as close as possible to real time. They will therefore have a highly
 * predictable execution time.
 *
 * Please take note to the following regarding real-time tasks:
 * - Two tasks scheduled at the same time, will execute in sequence
 * - Keep the number of RealTime tasks to a minimum, as they block other Tasks
 * - RealTime tasks should be SHORT lived.
 * - Long lived real-time tasks MAY cause lost ticks, making the tasks schedule unreliable
 * 		(However all Tasks will still execute, but not at the correct timing)
 * - Use Events to execute long tasks that needs Real Time synchronization.
 *
 * To create a task list named "normalTaskList" the syntax is as follows:
 *
 * NANOS_TASKLIST(normalTaskList,
 *     {
 *		 NOS_TASK(task1, 1000, 100),
 *		 NOS_TASK(task2, 1000, 300),
 *		 NOS_TASK(task3, 1000, 500),
 *		 NOS_TASK(task4, 1000, 700),
 *		 NOS_TASK(task5, 1000, 900),
 *	   }
 * );
 */
#define NANOS_TASKLIST(list, ...)		static const NanOSTask _##list##_temp[] = __VA_ARGS__;\
										static const NanOSTaskList *list = \
												&(NanOSTaskList){ NANOS_COUNT_TASKS(_##list##_temp),\
																  _##list##_temp };

/**
 * Macro used to define a single NanOS task for a task list, and simplifies
 * the syntax for doing so. Tasks are executed according to a specified
 * schedule, and should generally be short lived (use as little CPU as possible).
 *
 * @param _task The Task function to call
 * @param _schedule Number of Ticks between each execution
 * @param _start Number of ticks until first execution of task
 */
#define NANOS_TASK(_task, _schedule, _start)    { .task = _task,\
                                                  .schedule = _schedule,\
                                                  .next = _start,\
                                                  .doExecute = false }

//----------------------------------------------------------------------------
// Type definitions
//----------------------------------------------------------------------------

/**
 * Type definition of a Task Function
 */
typedef void (*NanOSTaskFunc)(void);

/**
 * Structure used to define tasks. Using the Macros is much simpler
 * than declaring the tasks using this struct.
 */
typedef struct {
	const NanOSTaskFunc task;
	const unsigned int schedule;
	unsigned int next;
	bool doExecute;
} NanOSTask;

/**
 * Keeps a task list
 */
typedef struct {
	const unsigned int count;
	NanOSTask *tasks;
} NanOSTaskList;


//----------------------------------------------------------------------------
// Function definitions
//----------------------------------------------------------------------------

/**
 * Called to boot NanOS. The method never returns.
 *
 * The Boot Strap function takes two Task List parameters, one for normal tasks,
 * and one for Real Time tasks. Both of these can be NULL, in case that kind
 * of task list is not used for a platform.
 *
 * @param normalTaskList The normal task list, or NULL if not used
 * @param realTimeTaskList The Real-Time task list, or NULL if not used
 */
void nanosBootStrap(const NanOSTaskList *normalTaskList, const NanOSTaskList *realTimeTaskList);

