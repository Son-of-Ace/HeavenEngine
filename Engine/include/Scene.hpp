#pragma once

#include <memory>
#include <string>
#include <vector>

#include "GameObject.hpp"

namespace HE {

class Scene {
 public:
  Scene();

  GameObject CreateObject(const std::string& objectName);
  const std::string GetSceneID() const;

 private:
  std::vector<std::shared_ptr<GameObject>> m_SceneObjects;
  std::string m_SceneID;
};

}  // namespace HE
