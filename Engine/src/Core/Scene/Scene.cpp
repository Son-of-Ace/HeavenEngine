#include "Scene.hpp"

namespace HE {

Scene::Scene() {
}

const std::string Scene::GetSceneID() const {
  return m_SceneID;
}

GameObject Scene::CreateObject(const std::string& objectName) {
  GameObject go{""};
  go = HE::GameObject(objectName);
  go.transform().position = {0.0f, 0.5f, 0.0f};
  go.transform().scale = {1.0f, 1.0f, 0.0f};

  m_SceneObjects.push_back(std::make_shared<GameObject>(go));

  return go;
}

}  // namespace HE
