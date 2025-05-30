cmake_minimum_required(VERSION 3.10)

# Define your project
project(MyProjectTests LANGUAGES CXX)
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# executables
add_executable(findMax_test test_findMax.cpp)
add_executable(randomSelection_test test_random_selection.cpp)
add_executable(findMin_test test_findMin.cpp) 

target_link_libraries(findMax_test PRIVATE GTest::gtest_main)
target_link_libraries(randomSelection_test PRIVATE GTest::gtest_main)
target_link_libraries(findMin_test PRIVATE GTest::gtest_main)  

add_test(NAME findMax_test COMMAND findMax_test)
add_test(NAME randomSelection_test COMMAND randomSelection_test)
add_test(NAME findMin_test COMMAND findMin_test)  
