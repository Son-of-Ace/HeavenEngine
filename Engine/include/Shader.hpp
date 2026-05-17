#pragma once

#include <string>

#include <glm/ext/vector_float4.hpp>
#include <glm/ext/matrix_float4x4.hpp>

namespace HE {

class Shader {
 public:
  uint32_t ID;

  Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
  ~Shader();
  void Use();
  void SetColor(const glm::vec4& color);
  void SetMat4(const char* valueName, const glm::mat4& value);
  void Bind();

 private:
  uint32_t vertexShader, fragmentShader;
};

}  // namespace HE
