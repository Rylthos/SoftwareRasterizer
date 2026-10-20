include ../config.mk

OBJ_DIR=$(BASE_OBJ_DIR)/examples
BIN_DIR=$(BASE_BIN_DIR)/examples

SRC=$(wildcard *.c)
BIN=$(patsubst %.c,$(BIN_DIR)/%,$(SRC))
HEADERS=$(wildcard ../engine/include/*/*.h)

.PHONY: all clean

all: $(BIN)

$(ENGINE_LIB):
	$(MAKE) -C ../engine

$(BIN_DIR)/%: %.c $(ENGINE_LIB) $(HEADERS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< $(ENGINE_LIB) -o $@

clean:
	rm -rf $(BIN_DIR)
