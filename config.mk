CC = clang
AR = ar

ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))

INCLUDES = -I$(ROOT_DIR)/engine/include

BUILD ?= release

OS := $(shell uname -s)

ifeq ($(BUILD),debug)
	OPT_FLAGS = -g -O0 -DDEBUG
	BASE_BUILD_DIR = $(ROOT_DIR)/build/debug
	BASE_BIN_DIR = $(ROOT_DIR)/bin/debug
else
	OPT_FLAGS = -O3 -DNDEBUG
	BASE_BUILD_DIR = $(ROOT_DIR)/build/release
	BASE_BIN_DIR = $(ROOT_DIR)/bin/release
endif

ifeq ($(OS),Linux)
	LIBS = -Wno-unused-command-line-argument -lm
else
	LIBS =
endif

BASE_OBJ_DIR=$(BASE_BUILD_DIR)/obj
BASE_LIB_DIR=$(BASE_BUILD_DIR)/lib

ENGINE_LIB_NAME=librasterizer.a
ENGINE_LIB=$(BASE_LIB_DIR)/$(ENGINE_LIB_NAME)

CFLAGS = -Wall -Wextra -Wpedantic -std=c23 $(OPT_FLAGS) $(INCLUDES) $(LIBS)
