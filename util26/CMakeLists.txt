cmake_minimum_required(VERSION 3.21)

project(util26)

add_library(util26 src/files.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_compile_features(glman PUBLIC cxx_std_20)
