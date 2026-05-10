#pragma once

#include <string>

#include "../../Utils/RGB.hpp"

class Shader {
 public:
  Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
  ~Shader();
  void Use();
  void SetColor(const RGB& color);
  void Bind();

 private:
  unsigned int shaderProgram;
  unsigned int vertexShader, fragmentShader;
};
