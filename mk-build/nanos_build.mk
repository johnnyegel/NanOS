###############################################################################
#
# NanOS - MAIN Make file for NanOS projects Building
#
# This file must be included to build sources and create the output
#
###############################################################################
NANOS_MKROOT := $(_GET_CURRENT_DIR)

#------------------------------------------------------------------------------
# Define the NanOS core sources
NANOS_SRC = $(NANOS_ROOT)src-core

#------------------------------------------------------------------------------
# Define compiler defaults if not already defined
CC 				   ?= gcc

# Compiler options defaults if not already defined
OPTIMIZATION       ?= s
F_CPU              ?=
C_STANDARD         ?= gnu99

CFLAGS             ?=  # C Compiler flags
CXXFLAGS           ?=  # C++ Compiler flags
CPPFLAGS           ?=  # Pre-Processor Compiler flags

#CC_FLAGS           ?=

#CPP_STANDARD       ?= gnu++98
#CPP_FLAGS          ?=
#ASM_FLAGS          ?=
#OBJDIR             ?= .
#OBJECT_FILES       ?=
#DEBUG_FORMAT       ?= dwarf-2
#DEBUG_LEVEL        ?= 2
#LINKER_RELAXATIONS ?= Y

# Default output directory
OUTPUT			   ?= output 
OBJDIR             ?= $(OUTPUT)/build
#------------------------------------------------------------------------------
# Include the Platform and Arch specific include
#------------------------------------------------------------------------------

# Create the platform specific include path
platformPath := ${PLATFORM}
ifdef VARIANT
    platformPath := $(platformPath)/${VARIANT}
endif

# Include the board specific config
boardIncludePath := $(NANOS_MKROOT)board/$(platformPath).mk
$(info INFO: Including Platform Make file: $(boardIncludePath))
include $(boardIncludePath)

ifdef ARCH
	archIncludePath := $(NANOS_MKROOT)arch/$(ARCH).mk
    $(info INFO: Including Architecture specific Make file: $(archIncludePath))
    include $(archIncludePath)
endif

#------------------------------------------------------------------------------
# If a cross compiler is specified, append this to compiler variable
ifdef CROSS
	CC := $(CROSS)-$(CC)
endif

all: build
	@echo "Build completed successfully..."

build:
	@echo "Build me"

clean:
	@echo "Cleaning output directory..."
	#echo rm -rfv $(strip $(OUTPUT))
	@echo "Clean COMPLETED successfully..."

.PHONY: all

