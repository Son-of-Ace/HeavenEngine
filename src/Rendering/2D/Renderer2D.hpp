#pragma once

#include "../Shader/Shader.hpp"
#include "../Mesh/Mesh.hpp"

class Renderer2D {
 public:
  // Setup
  Renderer2D();

  void Init();
  void Render();

  // Primitive Shapes
  void DrawTriangle();
  void DrawRectangle();

 private:
  Mesh triangleOneMesh;
  Mesh triangleTwoMesh;

  Shader redShader;
  Shader orangeShader;
};
