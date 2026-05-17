# API Documentation
---

### Scenes:
    const shared_ptr<Scene> SceneManager::GetCurrentScene() const
        - Returns the current main scene.

    void SceneManager::AddScene(Scene& s)
        - Adds a scene to the scene manager.

    void SceneManager::RemoveScene(Scene& s)
        - Removes a scene from the scene manager.

    void SceneManager::LoadScene(const string& sceneName, SceneLoadMode loadMode)
        - Loads a scene for rendering with a load mode for additive or single.

---

### GameObjects:
