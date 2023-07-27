
cmake_minimum_required(VERSION 3.11-3.18)

project(lib)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

message(SOURCES = "${SOURCES}")



add_library(lib ${SOURCES})

target_include_directories(lib PUBLIC ${SDL2_INCLUDE_DIRS})
target_include_directories(lib PUBLIC ${OPENGL_INCLUDE_DIR})
target_include_directories(lib PUBLIC ${GLEW_INCLUDE_DIR})


target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/../dependencies)

target_compile_features(lib PUBLIC cxx_std_20)