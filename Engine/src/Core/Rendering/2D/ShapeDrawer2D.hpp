#pragma once

#include <cstdint>
#include <vector>

#include <glm/ext/vector_float2.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/vector_float4.hpp>

#include "Transform.hpp"
#include "Material.hpp"

namespace HE {

class ShapeDrawer {
 public:
  void DrawQuad(const HE::Transform& transform, const HE::Material& material);
  void DrawLine(glm::vec3 start, glm::vec3 end, Color color);

  void Clear();

  std::vector<float>& GetVertices();
  std::vector<uint32_t>& GetIndices();
  uint32_t GetTriangleIndexCount();

 private:
  std::vector<float> m_Vertices;
  std::vector<uint32_t> m_Indices;
  uint32_t m_TriangleIndexCount = 0;
};

}  // namespace HE
