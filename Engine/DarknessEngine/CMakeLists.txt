cmake_minimum_required(VERSION 3.10)

set(CXX_STANDARD_REQUIRED ON)
set(CXX_STANDARD 17)

project(DarknessEngine)

set(PRIVATE_INCLUDE
src/
../vendor/GLFW/include
)

set(PRIVATE_LINK
opengl32
glfw
)

file(GLOB SOURCES
src/Core/*.cpp
)

if(WIN32)
    file(GLOB WIN_SOURCES
    src/Platform/Windows/*.cpp
    )
    list(APPEND SOURCES ${WIN_SOURCES})
endif()

file(GLOB HEADERS
src/pch.h
)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

target_precompile_headers(${PROJECT_NAME} PRIVATE src/pch.h)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PRIVATE_LINK})

target_include_directories(${PROJECT_NAME}
PRIVATE ${PRIVATE_INCLUDE}
PUBLIC include/
)