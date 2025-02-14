cmake_minimum_required(VERSION 3.10)

set(CXX_STANDARD_REQUIRED ON)
set(CXX_STANDARD 17)

project(Sandbox)

file(GLOB SOURCES
src/main.cpp
)

file(GLOB HEADERS
src/*.h
)


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE DarknessEngine)