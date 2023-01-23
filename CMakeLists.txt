cmake_minimum_required(VERSION 3.24)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 23)

project(knots LANGUAGES C VERSION 0.0.1)

# ./src
file(GLOB SOURCES "./src/*.c")
message(Source: ${SOURCES})
add_library(knots SHARED ${SOURCES})
set_property(TARGET knots PROPERTY LINKER_LANGUAGE C)
set_property(TARGET knots PROPERTY POSITION_INDEPENDENT_CODE 1)

# ./include
target_include_directories(knots PUBLIC include)

# ./tests
enable_testing()
add_subdirectory(tests)

# Convenience installer
install(FILES ${SOURCES} DESTINATION include/knots)
