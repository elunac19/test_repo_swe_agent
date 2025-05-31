clean:
	rm -rf build

build:
	cmake -B build
	cmake --build build
