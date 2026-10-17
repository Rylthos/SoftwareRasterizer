CC = clang
AR = ar

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -Iinclude

BUILD_DIR=../build
OBJ_DIR=$(BUILD_DIR)/obj/engine
LIB_DIR=$(BUILD_DIR)/lib

TARGET=$(LIB_DIR)/librasterizer.a

SRC=$(wildcard src/*/*.c)
OBJ=$(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRC))
HEADERS=$(wildcard include/*.h)

.PHONY: all clean

all: $(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p $(LIB_DIR)
	$(AR) rcs $@ $^


$(OBJ_DIR)/%.o: src/%.c $(HEADERS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
