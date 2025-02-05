#pragma once

#include <memory>

namespace BENG
{
    class Scene;
    class SceneSystem
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