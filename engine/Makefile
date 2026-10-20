include ../config.mk

OBJ_DIR=$(BASE_OBJ_DIR)/engine
LIB_DIR=$(BASE_LIB_DIR)

SRC=$(shell find src -name "*.c")
OBJ=$(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRC))
HEADERS=$(shell find . -name "*.h")

.PHONY: all clean test

all: $(ENGINE_LIB)

test:
	$(MAKE) -C tests

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

$(ENGINE_LIB): $(OBJ)
	@mkdir -p $(LIB_DIR)
	$(AR) rcs $@ $^

$(OBJ_DIR)/%.o: src/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
