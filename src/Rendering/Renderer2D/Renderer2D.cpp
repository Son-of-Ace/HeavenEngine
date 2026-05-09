#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Renderer2D.hpp"

Renderer2D::Renderer2D()
    : redShader("../shaders/vertex.glsl", "../shaders/RedFragment.glsl"),
      orangeShader("../shaders/vertex.glsl", "../shaders/OrangeFragment.glsl") {}

void Renderer2D::Init() {
  // clang-format off
  // Triangle
  float triangle1[] = {
     // Positions       // Colors
    -0.0f, -1.0f, 0.0f, 1.0f, 0.5f, 0.0f,
     1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f,
     0.5f,  0.0f, 0.0f, 0.1f, 0.1f, 0.2f
  };

  float triangle2[] = {
     // Positions       // Colors
    -1.0f, -1.0f, 0.0f, 0.1f, 0.8f, 0.9f,
     0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
    -0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 0.0f
  };
  // clang-format on

  // Vars
  // Buffers
  glGenVertexArrays(2, VAOs);
  glGenBuffers(2, VBOs);

  glBindVertexArray(VAOs[0]);
  glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(triangle1), triangle1, GL_STATIC_DRAW);

  // Positions
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // Colors
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glBindVertexArray(VAOs[1]);
  glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(triangle2), triangle2, GL_STATIC_DRAW);

  // Positions
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // Color
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);
}

void Renderer2D::Render() {
  glClear(GL_COLOR_BUFFER_BIT);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  redShader.Use();
  glBindVertexArray(VAOs[0]);
  glDrawArrays(GL_TRIANGLES, 0, 3);

  orangeShader.Use();
  glBindVertexArray(VAOs[1]);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}
