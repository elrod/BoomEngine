#pragma once

#include "raylib.h"

#include <unordered_map>
#include <memory>

namespace BENG
{
    class GameObject;
    
    class Scene
    {
        public:
            Scene();
            ~Scene();

            void AddGameObject(std::unique_ptr<GameObject> go, const std::string& parent_name);
            void RemoveGameObject(const std::string& name);
            GameObject* FindGameObject(const std::string& name);

            void Init();
            void Update(float dt);

            Camera2D* Get2DCamera() const;
            Camera3D* Get3DCamera() const;
    
        private:
            std::unordered_map<std::string, std::unique_ptr<GameObject>> m_sceneGraph;
            std::unique_ptr<Camera2D> m_2DCamera;
            std::unique_ptr<Camera3D> m_3DCamera;
    };
}