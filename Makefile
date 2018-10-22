PIP ?= pip
CMAKE_FLAGS ?= ""

build:
	mkdir -p build/
	(cd build/;	cmake ${CMAKE_FLAGS} ../)
	make -C build/ -j
	cd ..

install: build
	$(PIP) install . --user --upgrade

uninstall:
	$(PIP) uninstall sdf

clean:; rm -rf build

.PHONY: install uninstall build clean
