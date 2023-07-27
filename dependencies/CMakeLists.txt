
cmake_minimum_required(VERSION 3.11-3.18)

project(savepng)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/SDl_SavePNG/savepng.c")

message(SOURCES = "${SOURCES}")

add_library(savepng ${SOURCES})

target_include_directories(savepng PUBLIC ${SDL2_INCLUDE_DIRS})



target_link_libraries(savepng PRIVATE PNG::PNG)

target_compile_features(savepng PUBLIC cxx_std_20)