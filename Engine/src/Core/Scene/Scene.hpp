#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Core/GameObject/GameObject.hpp"

namespace HE::Core {

class Scene {
 public:
  std::string sceneName;

  void CreateObject();
  void FindObjectByName();

 private:
  std::vector<std::unique_ptr<GameObject>> sceneObjects;
};

}  // namespace HE::Core
