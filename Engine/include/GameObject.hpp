#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <typeindex>

#include "Transform.hpp"

namespace HE {

class GameObject {
 public:
  GameObject(const std::string& objecName) {
    AddComponent<Transform>();
    name = objecName;
  }

  std::string name;

  Transform& transform() {
    return *GetComponent<Transform>();
  }

  template <typename T>
  std::shared_ptr<T> AddComponent() {
    std::type_index id = typeid(T);

    if (components.contains(id)) {
      return nullptr;
    }

    std::shared_ptr<T> comp = std::make_shared<T>();
    components[id] = comp;

    return comp;
  }

  template <typename T>
  void RemoveComponent() {
    std::type_index id = typeid(T);
    components.erase(id);
  }

  template <typename T>
  std::shared_ptr<T> GetComponent() {
    std::type_index id = typeid(T);

    auto it = components.find(id);
    if (it == components.end()) {
      return nullptr;
    }

    return std::static_pointer_cast<T>(it->second);
  }

  template <typename T>
  bool HasComponent() {
    std::type_index id = typeid(T);
    return components.contains(id);
  }

 private:
  std::unordered_map<std::type_index, std::shared_ptr<Component>> components;
};

}  // namespace HE
