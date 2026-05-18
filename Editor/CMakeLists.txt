file(GLOB_RECURSE EDITOR_SOURCES
    "src/*.cpp"
    "src/*.hpp"
)

add_executable(HeavenEditor
    ${EDITOR_SOURCES}
)

target_include_directories(HeavenEditor PRIVATE
    src
)

target_link_libraries(HeavenEditor PRIVATE HeavenEngineLib)
