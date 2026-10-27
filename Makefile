include config.mk

# .PHONY: all engine examples clean test lsp debug release
.PHONY: all math generic examples test clean lsp debug release

all: examples

debug:
	$(MAKE) BUILD=debug all

release:
	$(MAKE) BUILD=release all

math:
	$(MAKE) -C engine math BUILD=$(BUILD)

generic:
	$(MAKE) -C engine generic BUILD=$(BUILD)

renderer:
	$(MAKE) -C engine renderer BUILD=$(BUILD)

test: math generic renderer
	$(MAKE) -C engine test BUILD=$(BUILD)

examples: renderer
	$(MAKE) -C examples BUILD=$(BUILD)

clean:
	$(MAKE) -C examples clean
	$(MAKE) -C engine clean
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)

lsp:
	compiledb -n make -B
