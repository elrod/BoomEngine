#include <memory>

#include "raylib.h"

#include "BMEngine/Scene.h"
#include "BMEngine/GameObject.h"
#include "Scene.h"

using namespace BENG;

Scene::Scene()
{
    m_2DCamera = std::make_unique<Camera2D>();
    m_3DCamera = std::make_unique<Camera3D>();
}

Scene::~Scene()
{
    m_2DCamera.release();
    m_3DCamera.release();
    m_sceneGraph.clear();
}

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
Camera2D *BENG::Scene::Get2DCamera() const
{
    return m_2DCamera.get();
}

Camera3D *BENG::Scene::Get3DCamera() const
{
    return m_3DCamera.get();
}
