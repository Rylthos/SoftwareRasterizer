.PHONY: all engine examples clean test lsp

all: engine examples test

engine:
	$(MAKE) -C engine

test:
	$(MAKE) -C engine test

examples:
	$(MAKE) -C examples

clean:
	$(MAKE) -C examples clean
	$(MAKE) -C engine clean

lsp:
	compiledb -n make -B
