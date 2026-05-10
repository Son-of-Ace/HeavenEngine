cmake_minimum_required(VERSION 4.2)

project(HeavenEngine)

set(CMAKE_CXX_STANDARD 26)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(HeavenEngine
    Engine/src/main.cpp
    Engine/src/Application/Application.cpp
    Engine/src/Rendering/2D/Renderer2D.cpp
    Engine/src/Rendering/Shader/Shader.cpp
    Engine/src/Rendering/Buffer/VertexBuffer.cpp
    Engine/src/Rendering/Buffer/IndexBuffer.cpp
    Engine/src/Rendering/Buffer/VertexArray.cpp
    Engine/src/Rendering/Mesh/Mesh.cpp
    Engine/src/Utils/RGB.cpp
    Engine/external/glad/src/glad.c
)

target_include_directories(HeavenEngine PRIVATE
    Engine/external/glad/include
)

target_link_libraries(HeavenEngine
    OpenGL::GL
    glfw
    glm::glm
)