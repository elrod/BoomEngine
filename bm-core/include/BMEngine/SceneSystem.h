#pragma once

#include "BMEngine/GameSystem.h"

#include <memory>

namespace BENG
{
    class Scene;
    class SceneSystem : public GameSystem
    {
        public:
            SceneSystem(){}
            ~SceneSystem(){}

            void LoadScene(std::unique_ptr<Scene> scene);
            Scene *GetCurrentScene() const;

        private:
            std::unique_ptr<Scene> m_currentScene;

    };
}