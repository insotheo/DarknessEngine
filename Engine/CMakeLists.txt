cmake_minimum_required(VERSION 3.10)

project(Engine)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(DarknessEngine)
add_subdirectory(Sandbox)
#modules
add_subdirectory(vendor/GLFW)
add_subdirectory(vendor/Glad)