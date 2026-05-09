#pragma once

#include <string>

#include "../Shader/Shader.hpp"

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
  std::string vertexSource;
  std::string redFragment;
  std::string oragneFragment;

  const char* vertexShaderSource;
  const char* redFragmentSource;
  const char* orangeFragmentSource;

  unsigned int VBOs[2], VAOs[2], EBO;

  unsigned int vertexShader;
  unsigned int redFragmentShader, orangeFragmentShader;
  unsigned int redShaderProgram, orangeShaderProgram;

  Shader redShader;
  Shader orangeShader;
};
