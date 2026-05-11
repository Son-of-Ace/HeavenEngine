#include <cstdint>

#include <glm/ext/vector_float4.hpp>

namespace HeavenEngine::General::Material {

struct Material {
  glm::vec4 color;
  uint32_t textureID;
};

}  // namespace HeavenEngine::General::Material
