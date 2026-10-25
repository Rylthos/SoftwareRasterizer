include ../../config.mk

GENERIC_OBJ_DIR=$(OBJ_DIR)/generic

SRC=$(shell find src -name "*.c")
OBJ=$(patsubst src/%.c,$(GENERIC_OBJ_DIR)/%.o,$(SRC))
DEPS=$(OBJS:.o=.d)

CFLAGS += -Iinclude

TARGET = $(LIB_DIR)/libgeneric.a

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(LIB_DIR)
	$(AR) rcs $@ $^

$(GENERIC_OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(GENERIC_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(GENERIC_OBJ_DIR) $(TARGET)
