cmake_minimum_required(VERSION 3.21)

project(main)

add_executable(main main.cpp)
# We need hello.h and the hello library
target_link_libraries(main
    PRIVATE hello)

# Tell C++ compiler to use C++20 features. We don't actually use any of them.
target_compile_features(main PUBLIC cxx_std_20)