#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := auto-home

include $(IDF_PATH)/make/project.mk

CXXFLAGS += -std=gnu++14
