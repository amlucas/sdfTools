PIP ?= pip
CMAKE_FLAGS ?= ""

build:
	mkdir -p build/
	(cd build/;	cmake ${CMAKE_FLAGS} ../)
	make -C build/ -j
	cd ..

clean:; rm -rf build

.PHONY: install build clean
