#include "BMEngine/GameObject.h"
#include "BMEngine/GameObjectComponent.h"

using namespace BENG;

void GameObject::AddComponent(std::shared_ptr<GameObjectComponent> component)
{
    m_Components[component->GetName()] = component;
}

void GameObject::RemoveComponent(const std::string& name)
{
    auto it = m_Components.find(name);
    if(it != m_Components.end())
    {
        m_Components.erase(name);
    }
}

GameObjectComponent* GameObject::GetComponent(const std::string& name) const
{
    auto it = m_Components.find(name);
    return it != m_Components.end() ? it->second.get() : nullptr;
}

void GameObject::Start()
{
    for (const auto & [ compName, comp ] : m_Components) {
        comp->Start();
    }
}

void GameObject::Update(float dt)
{
    for (const auto & [ compName, comp ] : m_Components) {
        comp->Update(dt);
    }
}

std::string GameObject::GetName() const
{
    return m_Name;
}