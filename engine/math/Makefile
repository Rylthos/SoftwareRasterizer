include ../../config.mk

MATH_OBJ_DIR=$(OBJ_DIR)/math

SRC=$(shell find src -name "*.c")
OBJ=$(patsubst src/%.c,$(MATH_OBJ_DIR)/%.o,$(SRC))
DEPS=$(OBJS:.o=.d)

CFLAGS += -Iinclude

TARGET = $(LIB_DIR)/libmath.a

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(LIB_DIR)
	$(AR) rcs $@ $^

$(MATH_OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(MATH_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(MATH_OBJ_DIR) $(TARGET)
