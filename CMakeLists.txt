cmake_minimum_required(VERSION 3.20)
project(HeavenEngine)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm CONFIG REQUIRED)

add_subdirectory(Engine)
add_subdirectory(Editor)
