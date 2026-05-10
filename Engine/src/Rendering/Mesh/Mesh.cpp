#include <cstdint>
#include <memory>

#include "Mesh.hpp"

Mesh::Mesh(const float* vertices, size_t vertexBufferSize, const uint32_t* indices, size_t indexCount) {
  m_vertexCount = vertexBufferSize / (3 * sizeof(float));
  m_indexCount = indexCount;

  // Use EBO
  if (indices && indexCount > 0) {
    m_vao.Bind();
    m_vbo = std::make_unique<VertexBuffer>(vertexBufferSize, GL_STATIC_DRAW);
    m_vbo->Bind(GL_ARRAY_BUFFER);
    m_vbo->SetData(GL_ARRAY_BUFFER, vertices);

    m_ebo = std::make_unique<IndexBuffer>(indexCount * sizeof(uint32_t), GL_STATIC_DRAW);
    m_ebo->Bind(GL_ELEMENT_ARRAY_BUFFER);
    m_ebo->SetData(GL_ELEMENT_ARRAY_BUFFER, indices);

    // Positions
    m_vao.AddAttribute(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    m_vao.EnableAttribute(0);

    /*
    // UV
    m_vao.AddAttribute(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    m_vao.EnableAttribute(2);
    */
  }
  // Use VBO
  else {
    m_vao.Bind();
    m_vbo = std::make_unique<VertexBuffer>(vertexBufferSize, GL_STATIC_DRAW);
    m_vbo->Bind(GL_ARRAY_BUFFER);
    m_vbo->SetData(GL_ARRAY_BUFFER, vertices);

    // Positions
    m_vao.AddAttribute(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    m_vao.EnableAttribute(0);

    /*
    // UV
    m_vao.AddAttribute(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    m_vao.EnableAttribute(2);
    */
  }
}

void Mesh::Draw() {
  if (m_ebo) {
    m_vao.Bind();
    glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, (void*)0);
  } else {
    m_vao.Bind();
    glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);
  }
}
