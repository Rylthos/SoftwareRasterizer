CC = clang
AR = ar

ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))

INCLUDES = -I$(ROOT_DIR)/engine/include

BUILD ?= release

OS := $(shell uname -s)

ifeq ($(BUILD),debug)
	OPT_FLAGS = -g -O0 -DDEBUG
	BUILD_DIR = $(ROOT_DIR)/build/debug
	BIN_DIR = $(ROOT_DIR)/bin/debug
else
	OPT_FLAGS = -O3 -DNDEBUG
	BUILD_DIR = $(ROOT_DIR)/build/release
	BIN_DIR = $(ROOT_DIR)/bin/release
endif

ifeq ($(OS),Linux)
	LIBS = -Wno-unused-command-line-argument -lm
else
	LIBS =
endif

OBJ_DIR=$(BUILD_DIR)/obj
LIB_DIR=$(BUILD_DIR)/lib

CFLAGS = -Wall -Wextra -Wpedantic -std=c23 -MMD -MP $(OPT_FLAGS) $(INCLUDES) $(LIBS)
