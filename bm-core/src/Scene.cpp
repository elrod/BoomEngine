#include "BMEngine/Scene.h"
#include "BMEngine/GameObject.h"

using namespace BENG;

void Scene::AddGameObject(std::unique_ptr<GameObject> go, const std::string& parent_name)
{
    m_sceneGraph[go->GetName()] = std::move(go);
}
void Scene::RemoveGameObject(const std::string& name)
{
    auto it = m_sceneGraph.find(name);
    if(it != m_sceneGraph.end())
    {
        m_sceneGraph.erase(name);
    }
}
GameObject* Scene::FindGameObject(const std::string& name)
{
    auto it = m_sceneGraph.find(name);
    return it != m_sceneGraph.end() ? it->second.get() : nullptr;
}

void Scene::Init()
{
    for (const auto & [ goName, go ] : m_sceneGraph) {
        go->Start();
    }
}

void Scene::Update(float dt)
{
    for (const auto & [ goName, go ] : m_sceneGraph) {
        go->Update(dt);
    }
}