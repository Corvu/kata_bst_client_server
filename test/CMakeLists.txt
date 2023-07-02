enable_testing()
add_subdirectory(googletest)

add_executable(tests bst_test.cpp)
target_link_libraries(tests gtest_main kata_bst_client_server)
add_test(NAME bst_test COMMAND tests)
