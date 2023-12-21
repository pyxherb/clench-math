cmake_minimum_required (VERSION 3.13)

project(clench-math VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory("example")

install(DIRECTORY include DESTINATION .)
