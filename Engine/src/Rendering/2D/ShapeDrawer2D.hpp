#pragma once

#include <cstdint>
#include <vector>

#include <glm/ext/vector_float2.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/vector_float4.hpp>

#include "Components/Transform.hpp"
#include "Material/Material.hpp"

namespace HE::Renderer {

class ShapeDrawer {
 public:
  void DrawQuad(const HE::Core::Transform& transform, const HE::Core::Material& material);
  void DrawTriangle(const HE::Core::Transform& transform);

  std::vector<float>& GetVertices();
  std::vector<uint32_t>& GetIndices();

 private:
  std::vector<float> vertices;
  std::vector<uint32_t> indices;
};

}  // namespace HE::Renderer
