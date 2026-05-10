cmake_minimum_required(VERSION 4.2)

project(HeavenEngine)

set(CMAKE_CXX_STANDARD 26)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(HeavenEngine
    src/main.cpp
    src/Application/Application.cpp
    src/Rendering/2D/Renderer2D.cpp
    src/Rendering/Shader/Shader.cpp
    src/Rendering/Buffer/VertexBuffer.cpp
    src/Rendering/Buffer/IndexBuffer.cpp
    src/Rendering/Buffer/VertexArray.cpp
    src/Rendering/Mesh/Mesh.cpp
    external/glad/src/glad.c
)

target_include_directories(HeavenEngine PRIVATE
    external/glad/include
)

target_link_libraries(HeavenEngine
    OpenGL::GL
    glfw
)