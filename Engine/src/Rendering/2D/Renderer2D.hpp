#pragma once

#include <glm/ext/vector_float4.hpp>
#include <glm/glm.hpp>

#include "../Shader/Shader.hpp"
#include "../Mesh/Mesh.hpp"

class Renderer2D {
 public:
  // Setup
  Renderer2D();

  void Init();
  void Render();

  // Primitive Shapes
  void DrawQuad(const glm::vec2& pos, const glm::vec2& size, const glm::vec4& color);
  void DrawTriangle();

  // TODO:
  // Collects data on a CPU buffer. DOES NOT DRAW ANYTHING!
  void BeginFrame();
  // This is what actually uses those buffers to draw vertices on the GPU!
  void EndFrame();

  // Example:
  /*
    Renderer2D.BeginFrame();

    Renderer2D.DrawQuad();
    Renderer2D.DrawQuad();
    Renderer2D.DrawQuad();

    Renderer2D.EndFrame();
  */

 private:
  Mesh triangleOneMesh;
  Mesh triangleTwoMesh;
  Mesh triangleThreeMesh;

  Shader fragment;
};
