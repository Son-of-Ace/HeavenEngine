#pragma once

#include <string>
#include <glm/ext/vector_float4.hpp>
#include <glm/glm.hpp>

class Shader {
 public:
  unsigned int ID;

  Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
  ~Shader();
  void Use();
  void SetColor(const glm::vec4& color);
  void Bind();

 private:
  unsigned int vertexShader, fragmentShader;
};
