cmake_minimum_required(VERSION 3.10)
project(leet_code)

# Add HelloWorld.cpp as an executable
add_executable(HelloWorld HelloWorld.cpp)

# Automatically add executables for each .cpp file in subfolders
file(GLOB_RECURSE PROBLEM_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} problem_*/**.cpp)
foreach(SRC ${PROBLEM_SOURCES})
    get_filename_component(EXE_NAME ${SRC} NAME_WE)
    string(REPLACE "/" "_" EXE_NAME ${SRC})
    add_executable(${EXE_NAME} ${SRC})
endforeach()
