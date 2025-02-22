cmake_minimum_required(VERSION 3.10)

set(CXX_STANDARD_REQUIRED ON)
set(CXX_STANDARD 17)

project(DarknessEngine)

set(PRIVATE_INCLUDE
src/
../vendor/GLFW/include
../vendor/glm/glm/
)

set(PUBLIC_INCLUDE
../vendor/ImGui/src/
include/DarknessEngine/
include/vendor_imgui/
)

set(PRIVATE_LINK
glfw
imgui
glm
)

set(PRIVATE_DEFINITIONS
GLFW_INCLUDE_NONE
IMGUI_IMPL_OPENGL_LOADER_CUSTOM
)

file(GLOB SOURCES
src/Core/*.cpp
src/Renderer/*.cpp
src/ImGui/*.cpp
)

file(GLOB HEADERS
src/pch.h
)

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    list(APPEND PRIVATE_DEFINITIONS "DE_CONFIG_DEBUG")
endif()

if(WIN32)
    file(GLOB WIN_SOURCES
    src/Platform/Windows/*.cpp
    )
    list(APPEND SOURCES ${WIN_SOURCES})

    set(WIN_PUBLIC_INCLUDE include/platform_Windows/)
    list(APPEND PUBLIC_INCLUDE ${WIN_PUBLIC_INCLUDE})
endif()


########################################################################
#ENGINE PROPERTIES
set(ENGINE_RENDERER DE_RENDERER_OPENGL) #options: DE_RENDERER_OPENGL
########################################################################

if("${ENGINE_RENDERER}" STREQUAL "DE_RENDERER_OPENGL")
    find_package(OpenGL REQUIRED)     

    file(GLOB OPENGL_SOURCES
    src/Platform/OpenGL/*.cpp
    )
    list(APPEND SOURCES ${OPENGL_SOURCES})

    set(OPENGL_LINK
    glad
    OpenGL::GL
    )
    list(APPEND PRIVATE_LINK ${OPENGL_LINK})

    file(GLOB OPENGL_PRIVATE_INCLUDE
    ../vendor/GLAD/include
    )
    list(APPEND PRIVATE_INCLUDE ${OPENGL_PRIVATE_INCLUDE})

    set(OPENGL_PUBLIC_INCLUDE
    include/platform_OpenGL/
    )
    list(APPEND PUBLIC_INCLUDE ${OPENGL_PUBLIC_INCLUDE})

endif()

list(APPEND PRIVATE_DEFINITIONS ${ENGINE_RENDERER})

########################################################################
    
add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})
    
target_precompile_headers(${PROJECT_NAME} PRIVATE src/pch.h)
    
target_link_libraries(${PROJECT_NAME} PRIVATE ${PRIVATE_LINK})

target_include_directories(${PROJECT_NAME}
PRIVATE ${PRIVATE_INCLUDE}
PUBLIC ${PUBLIC_INCLUDE}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE ${PRIVATE_DEFINITIONS})