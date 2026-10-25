include ../../config.mk

RENDERER_OBJ_DIR=$(OBJ_DIR)/renderer

MATH_LIB=$(LIB_DIR)/libmath.a
GENERIC_LIB=$(LIB_DIR)/libgeneric.a

SRC=$(shell find src -name "*.c")
OBJ=$(patsubst src/%.c,$(RENDERER_OBJ_DIR)/%.o,$(SRC))
DEPS=$(OBJS:.o=.d)

CFLAGS += -Iinclude -I../math/include -I../generic/include

TARGET = $(LIB_DIR)/librenderer.a

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ) $(MATH_LIB) $(GENERIC_LIB)
	@mkdir -p $(LIB_DIR)
	$(AR) rcs $@ $(OBJ)

$(RENDERER_OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(RENDERER_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(RENDERER_OBJ_DIR) $(TARGET)

$(MATH_LIB):
	$(MAKE) -C ../ math

$(GENERIC_LIB):
	$(MAKE) -C ../ generic
