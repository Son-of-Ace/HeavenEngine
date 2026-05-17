#pragma once

#include <string>
#include <vector>

namespace HE::Editor {

class Console {
 public:
  static void Log(const std::string& message) {
    m_Logs.push_back(message);
  }

  static void Warn(const std::string& message) {
    std::string warningMsg = "[WARN] " + message;
    m_Logs.push_back(warningMsg);
  }

  static void Error(const std::string& message) {
    std::string errorMsg = "[ERROR] " + message;
    m_Logs.push_back(errorMsg);
  }

  static const std::vector<std::string>& GetLogs() {
    return m_Logs;
  }

 private:
  static inline std::vector<std::string> m_Logs;
};

}  // namespace HE::Editor
