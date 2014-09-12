# NanOS - Minimalistic Micro Controller OS

NanOS is intended to become a minimalistic operating system for Micro Controller board,
like the Arduino Uno and similar. In contrast to the standard Arduino SDK, this OS introduces
the concept of Tasks and Events in order to handle process flow. This makes it much more 
convenient to implement more complex firmware where multiple tasks needs to be executed
with specific timing.

The main design goals for the OS is:
* Implemented in pure C, optimized using assembler where applicable.
* Extensible to multiple platforms and boards
* Minimalistic and Fast, suitable for very restricted platform
* Reliable Task scheduling

Currently the operating system is non-operational, and there is still some work do be done.

Features currently planned:
* Task Scheduler for application tasks
* Task Scheduler for Real-Time tasks (with optional high precition timing)
* Event engine for Event driven Tasks
* Serial driver for supported arduino boards (Uno and Micro)
* Peripheral drivers for:
** 1-wire serial Temperature sensors
** Motor controller
** TFT LCD display

