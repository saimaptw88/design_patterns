cmake_minimum_required(VERSION 3.10)
project(DESIGN_PATTERNS)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
add_test(NAME MyTest COMMAND bash -c "
./test/my_test;
")
