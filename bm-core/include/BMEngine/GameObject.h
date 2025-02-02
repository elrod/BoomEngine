#pragma once

#include "BMEngine/GameObjectComponent.h"

#include <string>
#include <unordered_map>

namespace BENG
{
    class GameObject
    {
        public:
            GameObject(std::string name) : m_Name(name) {}
            ~GameObject() {}

            void AddComponent(std::shared_ptr<GameObjectComponent> component);
            void RemoveComponent(const std::string& name);
            GameObjectComponent* GetComponent(const std::string& name) const;

            void Start();
            void Update(float dt);

            std::string GetName() const;

        private:
            std::string m_Name;
            std::unordered_map<std::string, std::shared_ptr<GameObjectComponent>> m_Components;
    };
}
