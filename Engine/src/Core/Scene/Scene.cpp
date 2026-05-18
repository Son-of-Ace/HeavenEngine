#include "Scene.hpp"

namespace HE {

Scene::Scene() {
}

GameObject Scene::CreateObject(const std::string& objectName) {
  GameObject go;
  go = HE::GameObject(objectName);
  go.transform().position = {0.0f, 0.5f, 0.0f};
  go.transform().scale = {1.0f, 1.0f, 0.0f};

  go.SetID();
  m_SceneObjects[m_CurrentID] = std::make_shared<GameObject>(go);

  return go;
}

void Scene::DeleteObject(uint64_t objectID) {
  m_SceneObjects.erase(objectID);
}

}  // namespace HE
