#include <string>

#include "SceneManager.hpp"

namespace HE::Core {

const Scene* SceneManager::GetCurrentScene() const {
  return mainScene;
}

void SceneManager::LoadScene(const std::string& sceneName, SceneLoadMode loadMode = SceneLoadMode::Single) {
  auto it = scenes.find(sceneName);
  if (it == scenes.end()) {
    return;
  }

  Scene& scene = it->second;

  if (loadMode == SceneLoadMode::Single) {
    loadedScenes.clear();
    mainScene = &scene;
    loadedScenes.insert(&scene);

  } else if (loadMode == SceneLoadMode::Additive) {
    if (!loadedScenes.contains(&scene)) {
      loadedScenes.insert(&scene);
    }
  }
}

void SceneManager::AddScene(Scene&& scene) {
  scenes.try_emplace(scene.sceneName, std::move(scene));
}

void SceneManager::RemoveScene(const std::string& sceneName) {
  scenes.erase(sceneName);
}

}  // namespace HE::Core
