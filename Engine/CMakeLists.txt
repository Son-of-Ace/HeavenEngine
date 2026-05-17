file(GLOB_RECURSE ENGINE_SOURCES
    "src/*.cpp"
    "src/*.hpp"
    "external/glad/src/glad.c"
)

add_library(HeavenEngineLib STATIC ${ENGINE_SOURCES})

target_include_directories(HeavenEngineLib
    PUBLIC  include          # exposed to anyone linking this
            external/glad/include
    PRIVATE src              # internal only
            external/stb
)

target_link_libraries(HeavenEngineLib
    PUBLIC OpenGL::GL glfw glm::glm
)

target_compile_definitions(HeavenEngineLib
    PUBLIC HE_ENGINE_ROOT="${CMAKE_SOURCE_DIR}/Engine/"
)
