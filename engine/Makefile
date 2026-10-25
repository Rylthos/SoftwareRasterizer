.PHONY: all math generic renderer test clean

all: renderer

math:
	$(MAKE) -C math

generic:
	$(MAKE) -C generic

renderer: math generic
	$(MAKE) -C renderer

test: math generic renderer
	$(MAKE) -C tests

clean:
	$(MAKE) -C math clean
	$(MAKE) -C generic clean
	$(MAKE) -C renderer clean
	$(MAKE) -C tests clean
