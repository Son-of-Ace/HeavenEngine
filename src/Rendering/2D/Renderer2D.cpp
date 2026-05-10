#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Renderer2D.hpp"
#include "../../Utils/RGB.hpp"

// clang-format off
  // Triangle
  float triangle1[] = {
     // Positions 
    -0.0f, -1.0f, 0.0f,
     1.0f, -1.0f, 0.0f,
     0.5f,  0.0f, 0.0f
  };

  float triangle2[] = {
     // Positions
    -1.0f, -1.0f, 0.0f,
     0.0f, -1.0f, 0.0f,
    -0.5f,  0.0f, 0.0f
  };

  float triangle3[] = {
     // Positions
    -0.5f,  0.0f, 0.0f,
     0.0f, -1.0f, 0.0f,
     0.5f,  0.0f, 0.0f
  };

Renderer2D::Renderer2D()
    : fragment("../shaders/Vertex.glsl", "../shaders/Fragment.glsl"),
      triangleOneMesh(triangle1, sizeof(triangle1)),
      triangleTwoMesh(triangle2, sizeof(triangle2)),
      triangleThreeMesh(triangle3, sizeof(triangle3)) {}
// clang-format on

// Drawing Shapes
void Renderer2D::DrawRectangle() {}

void Renderer2D::DrawTriangle() {}

// Rendering
void Renderer2D::BeginFrame() {}

void Renderer2D::EndFrame() {}

void Renderer2D::Init() {}

void Renderer2D::Render() {
  glClear(GL_COLOR_BUFFER_BIT);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  fragment.Use();
  fragment.SetColor(RGB::rgb(255, 0, 0));
  triangleOneMesh.Draw();

  fragment.Use();
  fragment.SetColor(RGB::rgb(255, 140, 0));
  triangleTwoMesh.Draw();

  fragment.Use();
  fragment.SetColor(RGB::rgb(14, 154, 218));
  triangleThreeMesh.Draw();
}
