#pragma once

#include <Color.hpp>
#include <cstdint>
#include <glm/ext/vector_float4.hpp>

namespace HE {

struct Material {
  Color color;
  uint32_t textureID;
};

}  // namespace HE
