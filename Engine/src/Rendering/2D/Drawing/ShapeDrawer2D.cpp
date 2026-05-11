#include <cmath>
#include <cstdint>
#include <vector>

#include <glm/ext/matrix_float2x2.hpp>
#include <glm/ext/vector_float2.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/vector_float4.hpp>

#include "ShapeDrawer2D.hpp"

namespace HeavenEngine::Rendering::Engine2D {

std::vector<float>& ShapeDrawer::GetVertices() {
  return vertices;
}

std::vector<uint32_t>& ShapeDrawer::GetIndices() {
  return indices;
}

void ShapeDrawer::DrawQuad(const Transform2D& transform, const Material& material) {
  uint32_t offset = vertices.size() / 9;

  // clang-format off
  glm::vec2 local[4] = {
      { -0.5f, -0.5f },
      {  0.5f, -0.5f },
      {  0.5f,  0.5f },
      { -0.5f,  0.5f }
  };

  glm::vec4 colors[4] = {
    material.color,
    material.color,
    material.color,
    material.color
  };

  glm::vec2 uvs[4] = {
    { 0.0f, 0.0f },
    { 1.0f, 0.0f },
    { 1.0f, 1.0f },
    { 0.0f, 1.0f }
  };

  glm::mat2 rot = {
    { cos(transform.rotation), -sin(transform.rotation) },
    { sin(transform.rotation),  cos(transform.rotation) },
  };
  // clang-format on

  for (int i = 0; i < 4; i++) {
    glm::vec2 vertexPos = local[i];
    glm::vec4 vertexColor = colors[i];
    glm::vec2 uvPos = uvs[i];

    glm::vec2 world = transform.position + rot * (vertexPos * transform.scale);

    vertices.push_back(world.x);
    vertices.push_back(world.y);
    vertices.push_back(0.0f);

    vertices.push_back(vertexColor.r);
    vertices.push_back(vertexColor.g);
    vertices.push_back(vertexColor.b);
    vertices.push_back(vertexColor.a);

    vertices.push_back(uvPos.x);
    vertices.push_back(uvPos.y);
  }

  // Indices
  indices.push_back(offset + 0);
  indices.push_back(offset + 1);
  indices.push_back(offset + 2);

  indices.push_back(offset + 0);
  indices.push_back(offset + 2);
  indices.push_back(offset + 3);
}

// void ShapeDrawer::DrawTriangle(const Transform2D& transform) {
//   uint32_t offset = vertices.size() / 3;

//   // Top
//   vertices.push_back(pos.x);
//   vertices.push_back(pos.y + size.y);
//   vertices.push_back(0.0f);

//   // Bottom Left
//   vertices.push_back(pos.x - size.x * 0.5f);
//   vertices.push_back(pos.y);
//   vertices.push_back(0.0f);

//   // Bottom Right
//   vertices.push_back(pos.x + size.x * 0.5f);
//   vertices.push_back(pos.y);
//   vertices.push_back(0.0f);

//   indices.push_back(offset + 1);
//   indices.push_back(offset + 2);
//   indices.push_back(offset + 0);
// }

}  // namespace HeavenEngine::Rendering::Engine2D
