CC = clang

CFLAGS = -std=c23 -Wall -Wextra -Wpedantic -O2 -I../include -lm -g

BUILD_DIR=../../build
OBJ_DIR=$(BUILD_DIR)/obj/engine/tests
BIN_DIR=../../bin
ENGINE_LIB=$(BUILD_DIR)/lib/librasterizer.a

SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
HEADERS=$(wildcard *.h)

TARGET=$(BIN_DIR)/engine_test

.PHONY: all clean

all: $(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

$(ENGINE_LIB):
	$(MAKE) -C ../

$(TARGET): $(OBJ) $(ENGINE_LIB)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ $(ENGINE_LIB) -o $@

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
