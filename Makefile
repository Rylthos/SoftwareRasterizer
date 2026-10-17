.PHONY: all engine examples clean lsp

all: engine examples

engine:
	$(MAKE) -C engine

examples:
	$(MAKE) -C examples

clean:
	$(MAKE) -C examples clean
	$(MAKE) -C engine clean

lsp:
	compiledb -n make -B
