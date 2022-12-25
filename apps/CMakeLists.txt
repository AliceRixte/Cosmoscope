cmake_minimum_required(VERSION 3.21)

project(SDL2Test)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIR})

message(STATUS "<<${OPENGL_INCLUDE_DIRS}>>")

add_executable(SDL2Test main.cpp)
target_link_libraries(SDL2Test ${SDL2_LIBRARIES} )
target_link_libraries(SDL2Test ${OPENGL_LIBRARIES})
target_link_libraries(SDL2Test
    glad)

#target_compile_features(SDL2Test PUBLIC cxx_std_20)