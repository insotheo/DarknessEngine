cmake_minimum_required(VERSION 3.10)

project(Glad C)

file(GLOB ALL_SOURCES
    src/glad.c
)

add_library(glad STATIC ${ALL_SOURCES})

target_include_directories(glad PRIVATE include/)