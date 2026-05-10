#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Renderer2D.hpp"

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
  
Renderer2D::Renderer2D()
    : redShader("../shaders/vertex.glsl", "../shaders/RedFragment.glsl"),
      orangeShader("../shaders/vertex.glsl", "../shaders/OrangeFragment.glsl"),
      triangleOneMesh(triangle1, sizeof(triangle1)),
      triangleTwoMesh(triangle2, sizeof(triangle2)) {}
// clang-format on

void Renderer2D::Init() {}

void Renderer2D::Render() {
  glClear(GL_COLOR_BUFFER_BIT);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  redShader.Use();
  triangleOneMesh.Draw();

  orangeShader.Use();
  triangleTwoMesh.Draw();
}
