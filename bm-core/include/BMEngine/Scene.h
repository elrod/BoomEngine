#pragma once

#include "BMEngine/GameObject.h"

#include <unordered_map>
#include <memory>

namespace BENG
{
    class Scene
    {
        public:
            void AddGameObject(std::unique_ptr<GameObject> go, const std::string& parent_name);
            void RemoveGameObject(const std::string& name);
            GameObject* FindGameObject(const std::string& name);

            void Init();
            void Update(float dt);
    
        private:
            std::unordered_map<std::string, std::unique_ptr<GameObject>> m_sceneGraph;
    };
}