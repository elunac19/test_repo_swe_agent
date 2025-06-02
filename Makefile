# PARA GENERAR DIFF PATCH
# Recomiendo usar -> git log --graph --oneline --decorate --all             

# git diff <COMMIT>  -- <path>/<filename>  > .patches/fix_<num_partch>_<filename>.patch;  

# Ejemplo: 
# git diff b194940  -- include/pokemon.h  > .patches/fix_4_pokemon.patch;  

help:
	@echo "Comandos disponibles:"
	@echo ""
	@echo "  make build_all               - Genera todo el proyecto en build/"
	@echo "  make clean_all               - Elimina todo el directorio build/"
	@echo ""
	@echo "  make build_<test_name>       - Compila solo el ejecutable del test especificado"
	@echo "  make test_<test_name>        - Ejecuta solo ese test (requiere build previo)"
	@echo ""
	@echo "Tests disponibles:"
	@echo "  findMax      | findMin      | randomSelection"
	@echo "  areaCalc     | pokemon      | statistics"
	@echo "  temperatureAnalyzer | efficiencyCalculator"
	@echo "  score        | divider"
	@echo ""
	@echo "Ejemplos:"
	@echo "  make build_pokemon           - Borra y compila solo el test de pokemon"
	@echo "  make test_pokemon            - Ejecuta solo el test de pokemon"

clean_all:
	rm -rf build

build_all:
	cmake -B build
	cmake --build build

define clean_and_build
	@rm -f build/$(1)
	cmake --build build --target $(1)
endef

# BUILDING ------------------------------------------------------------
build_findMax:
	$(call clean_and_build,findMax_test)

build_findMin:
	$(call clean_and_build,findMin_test)

build_randomSelection:
	$(call clean_and_build,randomSelection_test)

build_areaCalc:
	$(call clean_and_build,areaCalc_test)

build_pokemon:
	$(call clean_and_build,pokemon_test)

build_statistics:
	$(call clean_and_build,statistics_test)

build_temperatureAnalyzer:
	$(call clean_and_build,temperatureAnalyzer_test)

build_efficiencyCalculator:
	$(call clean_and_build,efficiencyCalculator_test)

build_score:
	$(call clean_and_build,score_test)

build_divider:
	$(call clean_and_build,divider_test)

# TESTING ------------------------------------------------------------
test_pokemon:
	ctest --test-dir build -V -R pokemon_test
	
test_findMax:
	ctest --test-dir build -V -R findMax_test

test_findMin:
	ctest --test-dir build -V -R findMin_test

test_randomSelection:
	ctest --test-dir build -V -R randomSelection_test

test_areaCalc:
	ctest --test-dir build -V -R areaCalc_test

test_statistics:
	ctest --test-dir build -V -R statistics_test

test_temperatureAnalyzer:
	ctest --test-dir build -V -R temperatureAnalyzer_test

test_efficiencyCalculator:
	ctest --test-dir build -V -R efficiencyCalculator_test

test_score:
	ctest --test-dir build -V -R score_test

test_divider:
	ctest --test-dir build -V -R divider_test

run_pokemon:
	rm -rf build/pokemon
	g++ -Iinclude src/pokemon.cpp -o build/pokemon -std=c++11
	./build/pokemon