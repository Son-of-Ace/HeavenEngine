set(IMGUI_SOURCES
    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/backends/imgui_impl_glfw.cpp
    external/imgui/backends/imgui_impl_opengl3.cpp
)

file(GLOB_RECURSE ENGINE_SOURCES
    "src/*.cpp"
    "src/*.hpp"
    "external/glad/src/glad.c"
)

add_library(HeavenEngineLib STATIC
    ${ENGINE_SOURCES}
    ${IMGUI_SOURCES}
)

target_include_directories(HeavenEngineLib
    PUBLIC  include          # exposed to anyone linking this
            external/glad/include
            external/imgui
            external/imgui/backends
    PRIVATE src              # internal only
            external/stb
)

target_link_libraries(HeavenEngineLib
    PUBLIC OpenGL::GL glfw glm::glm
)

target_compile_definitions(HeavenEngineLib
    PUBLIC HE_ENGINE_ROOT="${CMAKE_SOURCE_DIR}/Engine/"
)
