cmake_minimum_required(VERSION 3.21)

project(glman)

add_library(glman src/shaderMan.cpp)

target_link_libraries(glman glad util26)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include)


target_compile_features(glman PUBLIC cxx_std_20)




