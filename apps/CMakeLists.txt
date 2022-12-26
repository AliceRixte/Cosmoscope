cmake_minimum_required(VERSION 3.21)

project(Cosmoscope)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIR})

message(STATUS "<<${OPENGL_INCLUDE_DIRS}>>")

add_executable(Cosmoscope main.cpp)
target_link_libraries(Cosmoscope ${SDL2_LIBRARIES} )
target_link_libraries(Cosmoscope ${OPENGL_LIBRARIES})
target_link_libraries(Cosmoscope glad glman util26)

target_compile_features(Cosmoscope PUBLIC cxx_std_20)