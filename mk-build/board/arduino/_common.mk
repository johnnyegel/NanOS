###############################################################################
#
# NanOS - Common make file for Arduino boards
#
###############################################################################

# Define architecture and CPU frequency for Arduino boards
ARCH = AVR8
F_CPU = 16000000

# Cross compiler to use
CROSS = avr

# Define Arduino specific C_FLAGS 
CFLAGS += -ffunction-sections -fdata-sections