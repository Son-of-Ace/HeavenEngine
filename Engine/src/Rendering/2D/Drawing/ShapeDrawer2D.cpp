#include <cstdint>
#include <glm/ext/matrix_float4x4.hpp>
#include <vector>

#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/vector_float4.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

#include "ShapeDrawer2D.hpp"

namespace HeavenEngine::Rendering::Engine2D {

std::vector<float>& ShapeDrawer::GetVertices() {
  return vertices;
}

std::vector<uint32_t>& ShapeDrawer::GetIndices() {
  return indices;
}

void ShapeDrawer::DrawQuad(const Transform& transform, const Material& material) {
  uint32_t offset = vertices.size() / 9;

  // clang-format off
  glm::vec3 local[4] = {
      { -0.5f, -0.5f, 0.0f },
      {  0.5f, -0.5f, 0.0f },
      {  0.5f,  0.5f, 0.0f },
      { -0.5f,  0.5f, 0.0f }
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

  glm::mat4 rotationMatrix = glm::eulerAngleXYZ(transform.rotation.x, transform.rotation.y, -transform.rotation.z);
  // clang-format on

  for (int i = 0; i < 4; i++) {
    glm::vec3 vertexPos = local[i];
    glm::vec4 vertexColor = colors[i];
    glm::vec2 uvPos = uvs[i];

    glm::vec3 scaled = vertexPos * transform.scale;
    glm::vec4 rotated = rotationMatrix * glm::vec4(scaled, 1.0f);
    glm::vec3 world = transform.position + glm::vec3(rotated);

    vertices.push_back(world.x);
    vertices.push_back(world.y);
    vertices.push_back(world.z);

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
