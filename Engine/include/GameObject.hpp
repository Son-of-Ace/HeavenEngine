#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <typeindex>

#include "Transform.hpp"

namespace HE {

class GameObject {
 public:
  GameObject() = default;
  GameObject(const std::string& objecName) {
    AddComponent<Transform>();
    m_Name = objecName;
  }

  Transform& transform() {
    return *GetComponent<Transform>();
  }

  uint64_t GetID() {
    return m_ID;
  }

  void SetID() {
    m_CurrentID++;
    m_ID = m_CurrentID;
  }

  template <typename T>
  std::shared_ptr<T> AddComponent() {
    std::type_index id = typeid(T);

    if (m_Components.contains(id)) {
      return nullptr;
    }

    std::shared_ptr<T> comp = std::make_shared<T>();
    m_Components[id] = comp;

    return comp;
  }

  template <typename T>
  void RemoveComponent() {
    std::type_index id = typeid(T);
    m_Components.erase(id);
  }

  template <typename T>
  std::shared_ptr<T> GetComponent() {
    std::type_index id = typeid(T);

    auto it = m_Components.find(id);
    if (it == m_Components.end()) {
      return nullptr;
    }

    return std::static_pointer_cast<T>(it->second);
  }

  template <typename T>
  bool HasComponent() {
    std::type_index id = typeid(T);
    return m_Components.contains(id);
  }

 private:
  std::unordered_map<std::type_index, std::shared_ptr<Component>> m_Components;
  uint64_t m_ID;
  uint64_t m_CurrentID;
  std::string m_Name;
};

}  // namespace HE
