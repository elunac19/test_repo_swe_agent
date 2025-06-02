clean:
	rm -rf build

build:
	cmake -B build
	cmake --build build

test_pokemon:
	ctest --test-dir build -V -R pokemon_test