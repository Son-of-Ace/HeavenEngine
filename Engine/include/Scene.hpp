#pragma once

#include <memory>
#include <string>

#include "GameObject.hpp"

namespace HE {

class Scene {
 public:
  Scene();

  GameObject CreateObject(const std::string& objectName);
  void DeleteObject(uint64_t objectID);

 private:
  std::unordered_map<uint64_t, std::shared_ptr<GameObject>> m_SceneObjects;
  uint64_t m_CurrentID;
};

}  // namespace HE
