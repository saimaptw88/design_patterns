set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

file(GLOB SOURCES "/design_pattern/test/*.cc")
add_executable(my_test ${SOURCES})
target_link_libraries(
my_test
mod
sample
gtest
gtest_main
pthread
)
