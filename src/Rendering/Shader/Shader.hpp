#pragma once

#include <string>

class Shader {
 public:
  Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
  ~Shader();
  void Use();
  void Bind();

 private:
  unsigned int shaderProgram;
  unsigned int vertexShader, fragmentShader;
};
