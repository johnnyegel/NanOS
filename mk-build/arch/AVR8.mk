###############################################################################
#
# NanOS - Common include file for the AVR8 architecture
#
###############################################################################

# Define C flags needed
CPPFLAGS += -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Wall 
