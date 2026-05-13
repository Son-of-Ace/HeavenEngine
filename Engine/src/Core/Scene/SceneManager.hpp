#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>

#include "Scene.hpp"

namespace HE::Core {

enum class SceneLoadMode { Additive, Single };

class SceneManager {
 public:
  const Scene* GetCurrentScene() const;
  void LoadScene(const std::string& sceneName, SceneLoadMode loadMode);
  void AddScene(Scene&& scene);
  void RemoveScene(const std::string& sceneName);

 private:
  std::unordered_map<std::string, Scene> scenes;
  std::unordered_set<Scene*> loadedScenes;
  Scene* mainScene = nullptr;
};

}  // namespace HE::Core
