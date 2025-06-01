cmake_minimum_required(VERSION 3.10)
project(MyProjectTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
enable_testing()
find_package(GTest REQUIRED)

include_directories(include)

function(add_gtest name src)
    add_executable(${name} ${src})
    target_link_libraries(${name} PRIVATE GTest::gtest_main)
    add_test(NAME ${name} COMMAND ${name})
endfunction()

add_gtest(findMax_test tests/test_findMax.cpp)
add_gtest(findMin_test tests/test_findMin.cpp)
add_gtest(randomSelection_test tests/test_random_selection.cpp)
add_gtest(areaCalc_test tests/test_area_calc.cpp)
add_gtest(pokemon_test tests/test_pokemon.cpp)
add_gtest(statistics_test tests/test_statistics.cpp)