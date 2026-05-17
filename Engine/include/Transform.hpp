#pragma once

#include <glm/ext/vector_float3.hpp>

#include "Component.hpp"

namespace HE {

class Transform : public Component {
 public:
  glm::vec3 position{0.0f};
  glm::vec3 rotation{0.0f};
  glm::vec3 scale{1.0f};
};

}  // namespace HE
