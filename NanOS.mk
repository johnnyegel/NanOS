###############################################################################
#
# NanOS - MAIN Make file for NanOS projects
#
# This file should be included from the Makefile from any NanOS project
# in order to compile the complete NanOS based project. It handles building
# of all platform specific sources, drivers, etc. adapted for the platform
# and board defined in the Project make file.
# 
# Before including this file, the following variables should be defined
# from the project Makefile:
#
#	PROJECT  - Defines the name of the project, which is used for output files 
#
#	PLATFORM - Defines the platform the project should be built for
#
#	VARIANT  - (optional) Defines the platform variant the project 
#			   should be built for
#
#	SOURCES  - Defines a list of source files to compile in your project
#
###############################################################################

# Macro used to get the current relative path
_GET_CURRENT_DIR = $(dir $(lastword $(MAKEFILE_LIST)))
NANOS_ROOT := $(_GET_CURRENT_DIR)

# Check mandatory variables first
ifndef PROJECT
    $(error error: Build variable PROJECT is not defined)
endif
ifndef PLATFORM
    $(error error: Build variable PLATFORM is not defined)
endif
ifndef SOURCES
    $(error error: Build variable SOURCES is not defined)
endif

# Display build system info
#------------------------------------------------------------------------------
$(info INFO: NanOS BUILD System v1.0)
$(info INFO:=================================================================)
$(info INFO: Project:  $(PROJECT))
$(info INFO: Platform: $(PLATFORM))

ifdef VARIANT
    $(info INFO: Variant:  $(VARIANT))
endif
$(info INFO:=================================================================)
#------------------------------------------------------------------------------

# Include the main build file
include $(NANOS_ROOT)mk-build/nanos_build.mk
 