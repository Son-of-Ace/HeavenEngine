#pragma once

#include <fstream>
#include <sstream>

namespace HE {

static std::string LoadShader(const std::string& filePath) {
  std::ifstream file(filePath);

  if (!file.is_open()) {
    throw std::runtime_error("ERROR: Could not open file at: " + filePath);
  }

  std::fflush(stdout);

  std::stringstream buffer;
  buffer << file.rdbuf();
  return buffer.str();
}

}  // namespace HE
