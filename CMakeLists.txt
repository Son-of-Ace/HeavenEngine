cmake_minimum_required(VERSION 4.2)

project(HeavenEngine)

set(CMAKE_CXX_STANDARD 26)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(HeavenEngine
    # Main
    Engine/src/main.cpp
    Engine/src/Application/Application.cpp

    # 2D
    Engine/src/Rendering/2D/Renderer2D.cpp
    Engine/src/Rendering/2D/Drawing/ShapeDrawer2D.cpp

    # Buffers
    Engine/src/Rendering/General/Buffer/VertexBuffer.cpp
    Engine/src/Rendering/General/Buffer/IndexBuffer.cpp
    Engine/src/Rendering/General/Buffer/VertexArray.cpp

    # Shader
    Engine/src/Rendering/General/Shader/Shader.cpp

    # Utils
    Engine/src/Utils/RGB.cpp

    # External
    Engine/external/glad/src/glad.c
)

add_custom_command(TARGET HeavenEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/Engine/shaders
    ${CMAKE_BINARY_DIR}/shaders
)


target_include_directories(HeavenEngine PRIVATE
    Engine/external/glad/include
)

target_link_libraries(HeavenEngine
    OpenGL::GL
    glfw
    glm::glm
)