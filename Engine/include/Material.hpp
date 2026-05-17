#pragma once

#include <cstdint>
#include <glm/ext/vector_float4.hpp>

namespace HE {

struct Material {
  glm::vec4 color;
  uint32_t textureID;
};

}  // namespace HE
