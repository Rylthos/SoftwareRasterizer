include ../config.mk

EXAMPLES_OBJ_DIR=$(OBJ_DIR)/examples
EXAMPLES_BIN_DIR=$(BIN_DIR)/examples

MATH_LIB=$(LIB_DIR)/libmath.a
GENERIC_LIB=$(LIB_DIR)/libgeneric.a
RENDERER_LIB=$(LIB_DIR)/librenderer.a

CFLAGS += -I../engine/math/include -I../engine/generic/include -I../engine/renderer/include

SRC=$(wildcard *.c)
BIN=$(patsubst %.c,$(EXAMPLES_BIN_DIR)/%,$(SRC))

.PHONY: all clean

all: $(BIN)

$(EXAMPLES_BIN_DIR)/%: %.c $(RENDERER_LIB) $(MATH_LIB) $(GENERIC_LIB)
	@mkdir -p $(EXAMPLES_BIN_DIR)
	$(CC) $(CFLAGS) $< $(RENDERER_LIB) $(MATH_LIB) $(GENERIC_LIB) -o $@

clean:
	rm -rf $(BIN_DIR)

$(RENDERER_LIB):
	$(MAKE) -C ../engine renderer

$(MATH_LIB):
	$(MAKE) -C ../engine math

$(GENERIC_LIB):
	$(MAKE) -C ../engine generic
