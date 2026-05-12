cmake_minimum_required(VERSION 4.2)

project(HeavenEngine)

set(CMAKE_CXX_STANDARD 26)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm CONFIG REQUIRED)


# finds all .h and .cpp files. also compiles "glad.c".
file(GLOB_RECURSE SOURCES
    "Engine/*.hpp"
    "Engine/*.cpp"
)

add_executable(HeavenEngine ${SOURCES}
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
    Engine/src/Rendering/Core
    Engine/src
)

target_link_libraries(HeavenEngine
    OpenGL::GL
    glfw
    glm::glm
)