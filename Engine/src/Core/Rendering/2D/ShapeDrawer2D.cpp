#include <cstdint>
#include <glm/ext/matrix_float4x4.hpp>
#include <vector>

#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/vector_float4.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

#include "ShapeDrawer2D.hpp"

namespace HE {

std::vector<float>& ShapeDrawer::GetVertices() {
  return m_Vertices;
}

std::vector<uint32_t>& ShapeDrawer::GetIndices() {
  return m_Indices;
}

uint32_t ShapeDrawer::GetTriangleIndexCount() {
  return m_TriangleIndexCount;
}

void ShapeDrawer::Clear() {
  m_Vertices.clear();
  m_Indices.clear();
  m_TriangleIndexCount = 0;
}

void ShapeDrawer::DrawQuad(const HE::Transform& transform, const HE::Material& material) {
  uint32_t offset = m_Vertices.size() / 9;

  // clang-format off
  glm::vec3 local[4] = {
      { -0.5f, -0.5f, 0.0f },
      {  0.5f, -0.5f, 0.0f },
      {  0.5f,  0.5f, 0.0f },
      { -0.5f,  0.5f, 0.0f }
  };

  Color colors[4] = {
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
    Color vertexColor = colors[i];
    glm::vec2 uvPos = uvs[i];

    glm::vec3 scaled = vertexPos * transform.scale;
    glm::vec4 rotated = rotationMatrix * glm::vec4(scaled, 1.0f);
    glm::vec3 world = transform.position + glm::vec3(rotated);

    m_Vertices.push_back(world.x);
    m_Vertices.push_back(world.y);
    m_Vertices.push_back(world.z);

    m_Vertices.push_back(vertexColor.r);
    m_Vertices.push_back(vertexColor.g);
    m_Vertices.push_back(vertexColor.b);
    m_Vertices.push_back(vertexColor.a);

    m_Vertices.push_back(uvPos.x);
    m_Vertices.push_back(uvPos.y);
  }

  // Indices
  m_Indices.push_back(offset + 0);
  m_Indices.push_back(offset + 1);
  m_Indices.push_back(offset + 2);

  m_Indices.push_back(offset + 0);
  m_Indices.push_back(offset + 2);
  m_Indices.push_back(offset + 3);
  m_TriangleIndexCount = 6;
}

void ShapeDrawer::DrawLine(glm::vec3 start, glm::vec3 end, Color color) {
  uint32_t offset = m_Vertices.size() / 9;

  auto pushVertex = [&](glm::vec3 pos) {
    m_Vertices.push_back(pos.x);
    m_Vertices.push_back(pos.y);
    m_Vertices.push_back(pos.z);
    m_Vertices.push_back(color.r);
    m_Vertices.push_back(color.g);
    m_Vertices.push_back(color.b);
    m_Vertices.push_back(color.a);
    m_Vertices.push_back(0.0f);
    m_Vertices.push_back(0.0f);
  };

  pushVertex(start);
  pushVertex(end);

  m_Indices.push_back(offset + 0);
  m_Indices.push_back(offset + 1);
}

}  // namespace HE
