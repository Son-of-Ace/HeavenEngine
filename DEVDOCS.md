# Heaven Engine

### Architecture
    Top Level:
        - Renderer

    Low Level:
        - Graphics API

---

### Scenes
    Scene
        - CreateObject()
        - FindObjectByName() - (Probably wont be implemented, or at least in a way without by name).

    SceneManager
        - AddScene()
        - RemoveScene()
        - LoadScene()
        - GetCurrentScene()

---

# Editor

### Architecture
    ImGui
    src

---

### Goals
    UI
        - Being able to add and remove Scenes
        - Being able to add Objects to a Scene
        - Being able to add Components to an Object
        - Play/Editor mode
