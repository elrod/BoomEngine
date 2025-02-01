#include <memory>
#include "BMEngine/SceneSystem.h"
#include "BMEngine/Scene.h"

using namespace BENG;

void SceneSystem::LoadScene(std::unique_ptr<Scene> scene)
{
    if(m_currentScene != nullptr)
    {
        m_currentScene.release();
    }
    m_currentScene = std::move(scene);
}

Scene* SceneSystem::GetCurrentScene() const
{
    return m_currentScene.get();
}