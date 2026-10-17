CC = clang

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -I../engine/include

BUILD_DIR=../build
BIN_DIR=../bin
ENGINE_LIB=$(BUILD_DIR)/lib/librasterizer.a

SRC=$(wildcard *.c)
BIN=$(patsubst %.c,$(BIN_DIR)/%,$(SRC))
HEADERS=$(wildcard ../engine/include/*.h)

.PHONY: all clean

all: $(BIN)

$(ENGINE_LIB):
	$(MAKE) -C ../engine

$(BIN_DIR)/%: %.c $(ENGINE_LIB) $(HEADERS)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< $(ENGINE_LIB) -o $@

clean:
	rm -rf $(BIN_DIR)
