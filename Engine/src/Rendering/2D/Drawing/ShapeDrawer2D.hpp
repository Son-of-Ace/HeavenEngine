#pragma once

#include <cstdint>
#include <vector>

#include <glm/ext/vector_float2.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/vector_float4.hpp>

#include "../../General/Transform/Transform.hpp"
#include "../../General/Material/Material.hpp"

using namespace HeavenEngine::General::Material;
using namespace HeavenEngine::General::Transform;

namespace HeavenEngine::Rendering::Engine2D {

class ShapeDrawer {
 public:
  void DrawQuad(const Transform& transform, const Material& material);
  void DrawTriangle(const Transform& transform);

  std::vector<float>& GetVertices();
  std::vector<uint32_t>& GetIndices();

 private:
  std::vector<float> vertices;
  std::vector<uint32_t> indices;
};

}  // namespace HeavenEngine::Rendering::Engine2D
