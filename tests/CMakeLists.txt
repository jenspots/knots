include(CTest)

file(GLOB TESTS "*.c")

foreach(TEST IN LISTS TESTS)
    cmake_path(GET TEST FILENAME NAME)
    add_executable(${NAME} ${TEST})
    target_link_libraries(${NAME} PUBLIC knots)
    add_test(NAME ${NAME} COMMAND ${NAME})
endforeach()
