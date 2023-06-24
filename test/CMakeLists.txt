set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(
my_test
${CMAKE_CURRENT_SOURCE_DIR}/sample_test.cc
)

target_link_libraries(
my_test
sample
gtest_main
gtest
pthread
)
