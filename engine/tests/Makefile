include ../../config.mk

TEST_OBJ_DIR=$(OBJ_DIR)/engine/tests
TEST_BIN_DIR=$(BIN_DIR)/engine

MATH_LIB=$(LIB_DIR)/libmath.a
GENERIC_LIB=$(LIB_DIR)/libgeneric.a
RENDERER_LIB=$(LIB_DIR)/librenderer.a

CFLAGS += -I../math/include -I../generic/include -I../renderer/include

SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

TARGET=$(TEST_BIN_DIR)/run_tests

.PHONY: all clean

all: $(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

$(TARGET): $(OBJ) $(RENDERER_LIB) $(GENERIC_LIB) $(MATH_LIB)
	@mkdir -p $(TEST_BIN_DIR)
	$(CC) $(CFLAGS) $^ $(ENGINE_LIB) $(GENERIC_LIB) $(MATH_LIB) -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
