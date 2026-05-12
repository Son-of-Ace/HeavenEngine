#pragma once

#include <glm/ext/vector_float3.hpp>

namespace HeavenEngine::General::Transform {

struct Transform {
  glm::vec3 position{0.0f};
  glm::vec3 rotation{0.0f};
  glm::vec3 scale{1.0f};
};

}
