cmake_minimum_required(VERSION 3.10)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_executable(my_app main.cc)
add_subdirectory(sample)
add_subdirectory(factory_method)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

target_link_libraries(
my_app
PUBLIC "-pthread"
sample
factory_method
)
