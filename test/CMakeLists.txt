# test
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(sample_test ${CMAKE_CURRENT_SOURCE_DIR}/sample_test.cc)
target_link_libraries(sample_test gtest gtest_main pthread)
