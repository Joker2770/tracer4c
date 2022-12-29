add_executable(test_1 test_1.c)
add_executable(test_2 test_2.c)

target_link_libraries(test_1 tracer4c)
target_link_libraries(test_2 tracer4c)

add_test(NAME Test_1 COMMAND test_1)
add_test(NAME Test_2 COMMAND test_2)
