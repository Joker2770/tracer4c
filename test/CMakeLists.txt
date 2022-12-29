add_executable(test_1
    test_1.c)

target_link_libraries(test_1
    tracer4c)

add_test(NAME Test_1 COMMAND test_1)