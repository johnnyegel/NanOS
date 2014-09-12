/* 
 * File:   main.c
 * Author: johnny
 *
 * Created on September 5, 2014, 7:47 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "nanos.h"

void task1(void) {
    printf("Task 1 Executed");
}

//static const NanOSTask taskListHolder[] = {
//			{ task1, 1000, 100, false },
//			{ task1, 1000, 100, false },
//			{ task1, 1000, 100, false },
//			{ task1, 1000, 100, false },
//			{ task1, 1000, 100, false },
//	};
//
//static const NanOSTaskList normalTaskList = {
//		.count = (sizeof(taskListHolder) / sizeof(NanOSTask)),
//		.tasks = taskListHolder
//	};
//


// Define the normal tasklist
NANOS_TASKLIST(normalTaskList,
	{
		NOS_TASK(task1, 1000, 100),
		NOS_TASK(task1, 1000, 300),
		NOS_TASK(task1, 1000, 500),
		NOS_TASK(task1, 1000, 700),
		NOS_TASK(task1, 1000, 900),
	}
);

//// We don't need Real Time tasks, but they must be defined
//NANOS_DEF_RT_TASKS(rtTasks);

/*
 * 
 */
int main(int argc, char** argv) {

    //printf("NanOS Task list size %u, real time %u\n", normTasks, rtTasks);
	printf("Testing: %u\n", normalTaskList->count);
	printf("Testing: %u\n", (unsigned int)sizeof(NULL));

    nanosBootStrap(normalTaskList, NULL);
    //nanosTest();
    
    return (EXIT_SUCCESS);
}

