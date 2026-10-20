include ../../config.mk

OBJ_DIR=$(BASE_OBJ_DIR)/engine/tests
BIN_DIR=$(BASE_BIN_DIR)/engine

SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
HEADERS=$(wildcard *.h)

TARGET=$(BIN_DIR)/run_tests

.PHONY: all clean

all: $(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

$(ENGINE_LIB):
	$(MAKE) -C ../

$(TARGET): $(OBJ) $(ENGINE_LIB)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ $(ENGINE_LIB) -o $@

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
