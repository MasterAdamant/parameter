cmake_minimum_required(VERSION 3.14)

project(Parameter VERSION 1.1.1)

set(CXX_STANDARD_REQUIRED 17)

find_package(GTest REQUIRED)

set(SOURCES ./src/parameter.cpp)
set(TESTS 
./tests/test_main.cpp)

enable_testing()

add_executable(Parameter ${TESTS} ${SOURCES})

target_include_directories(Parameter PUBLIC ./include/)

include(GoogleTest)

target_link_libraries(Parameter PRIVATE GTest::gtest GTest::gtest_main)
gtest_discover_tests(Parameter)