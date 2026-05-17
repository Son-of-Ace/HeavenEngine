#pragma once

#include <glm/glm.hpp>

#include "Transform.hpp"
#include "Material.hpp"

namespace HE {

class Renderer {
 public:
  virtual void BeginFrame(const glm::mat4& viewportProjection) = 0;
  virtual void EndFrame() = 0;
  virtual void DrawQuad(const Transform& transform, const Material& material) = 0;
  virtual void DrawLine(glm::vec3 start, glm::vec3 end, glm::vec4 color) = 0;
};

}  // namespace HE
