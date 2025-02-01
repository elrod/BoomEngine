#pragma once

#include "BMEngine/Scene.h"

#include <memory>

namespace BENG
{
    class SceneSystem
    {
        public:
            void LoadScene(std::unique_ptr<Scene> scene);
            Scene *GetCurrentScene() const;

        private:
            std::unique_ptr<Scene> m_currentScene;

    };
}