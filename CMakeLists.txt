cmake_minimum_required(VERSION 3.14)
project(kata_bst_client_server)

# We want to use the C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(test)
