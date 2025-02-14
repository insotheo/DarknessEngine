cmake_minimum_required(VERSION 3.10)

set(CXX_STANDARD_REQUIRED ON)
set(CXX_STANDARD 17)

project(DarknessEngine)

file(GLOB SOURCES
src/Core/*.cpp
)

file(GLOB HEADERS
src/pch.h
)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME}
PRIVATE src/
PUBLIC include/
)