set(IMGUI_SOURCES
    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/backends/imgui_impl_glfw.cpp
    external/imgui/backends/imgui_impl_opengl3.cpp
)

file(GLOB_RECURSE EDITOR_SOURCES
    "src/*.cpp"
    "src/*.hpp"
)

add_executable(HeavenEditor
    ${EDITOR_SOURCES}
    ${IMGUI_SOURCES}
)

target_include_directories(HeavenEditor PRIVATE
    src
    external/imgui
    external/imgui/backends
)

target_link_libraries(HeavenEditor PRIVATE HeavenEngineLib)
