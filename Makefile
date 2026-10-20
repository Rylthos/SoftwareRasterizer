include config.mk

.PHONY: all engine examples clean test lsp debug release

all: engine examples test lsp

debug:
	$(MAKE) BUILD=debug all

release:
	$(MAKE) BUILD=release all

engine:
	$(MAKE) -C engine BUILD=$(BUILD)

test:
	$(MAKE) -C engine test BUILD=$(BUILD)

examples: engine
	$(MAKE) -C examples BUILD=$(BUILD)

clean:
	$(MAKE) -C examples clean
	$(MAKE) -C engine clean
	rm -rf $(BASE_BUILD_DIR)
	rm -rf $(BASE_BIN_DIR)

lsp:
	compiledb -n make -B
