#pragma once

#include <cstdint>
#include <vector>

#include <glm/ext/vector_float2.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/vector_float4.hpp>

#include "../Transform2D.hpp"
#include "../../General/Material/Material.hpp"

using namespace HeavenEngine::General::Material;

namespace HeavenEngine::Rendering::Engine2D {

class ShapeDrawer {
 public:
  void DrawQuad(const Transform2D& transform, const Material& material);
  void DrawTriangle(const Transform2D& transform);

  std::vector<float>& GetVertices();
  std::vector<uint32_t>& GetIndices();

 private:
  std::vector<float> vertices;
  std::vector<uint32_t> indices;
};

}  // namespace HeavenEngine::Rendering::Engine2D
