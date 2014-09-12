###############################################################################
#
# NanOS - Make file for Arduino Micro boards
#
###############################################################################

# Include common for all Arduino board
include $(_GET_CURRENT_DIR)_common.mk

# Define MCU and USB frequency
MCU = atmega32u4
F_USB = $(F_CPU)

