cmake_minimum_required(VERSION 3.10)

set(CXX_STANDARD_REQUIRED ON)
set(CXX_STANDARD 17)

project(DarknessEngine)

set(PRIVATE_INCLUDE
src/
../vendor/GLFW/include
../vendor/GLAD/include
../vendor/glm/glm/
)

set(PUBLIC_INCLUDE
include/
../vendor/ImGui/src/
)

set(PRIVATE_LINK
opengl32
glfw
glad
imgui
glm
)

set(PRIVATE_DEFINITIONS
GLFW_INCLUDE_NONE
IMGUI_IMPL_OPENGL_LOADER_CUSTOM
)

file(GLOB SOURCES
src/Core/*.cpp
src/ImGui/*.cpp
src/ImGui/ImGuiKeyTranslator.h
src/Platform/OpenGL/*.cpp
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
PUBLIC ${PUBLIC_INCLUDE}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE ${PRIVATE_DEFINITIONS})