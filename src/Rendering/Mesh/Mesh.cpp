#include <memory>

#include "Mesh.hpp"

Mesh::Mesh(const float* vertices, size_t vertexBufferSize, const uint32_t* indices, size_t indexCount) {
  vertexCount = vertexBufferSize / (6 * sizeof(float));

  // Use EBO
  if (indices && indexCount > 0) {
    vao.Bind();
    vbo = std::make_unique<VertexBuffer>(vertexBufferSize, GL_STATIC_DRAW);
    vbo->Bind(GL_ARRAY_BUFFER);
    vbo->SetData(GL_ARRAY_BUFFER, vertices);

    // Positions
    vao.AddAttribute(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    vao.EnableAttribute(0);

    // Colors
    vao.AddAttribute(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    vao.EnableAttribute(1);
  }
  // Use VBO
  else {
    vao.Bind();
    vbo = std::make_unique<VertexBuffer>(vertexBufferSize, GL_STATIC_DRAW);
    vbo->Bind(GL_ARRAY_BUFFER);
    vbo->SetData(GL_ARRAY_BUFFER, vertices);

    // Positions
    vao.AddAttribute(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    vao.EnableAttribute(0);

    // Colors
    vao.AddAttribute(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    vao.EnableAttribute(1);
  }
}

void Mesh::Draw() {
  if (ebo) {
  } else {
    vao.Bind();
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
  }
}
