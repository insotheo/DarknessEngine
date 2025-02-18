cmake_minimum_required(VERSION 3.10)

project(ImGui)

file(GLOB ALL_SOURCES
    src/*.h
    src/*.cpp
    # src/backends/*.cpp
    # src/backends/*.h
)

add_library(imgui STATIC ${ALL_SOURCES})

target_include_directories(imgui PRIVATE src/)