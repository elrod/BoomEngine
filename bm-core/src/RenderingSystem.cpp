#include "BMEngine/RenderingSystem.h"
#include "BMEngine/Renderer.h"

using namespace BENG;


void RenderingSystem::Register(std::shared_ptr<Renderer> renderer)
{
    switch (renderer->GetRendererType())
    {
        case RendererMode::RENDER_3D :
            m_3DRenderers[renderer->GetName()] = renderer;
            break;
        case RendererMode::RENDER_2D :
            m_2DRenderers[renderer->GetName()] = renderer;
            break;
        default:
            break;
    }
}

void RenderingSystem::Deregister(std::shared_ptr<Renderer> renderer)
{
    std::string name = renderer->GetName();

    switch (renderer->GetRendererType())
    {
        case RendererMode::RENDER_3D :
            auto it = m_3DRenderers.find(name);
            if(it != m_3DRenderers.end())
            {
                m_3DRenderers.erase(name);
            }            
            break;
        case RendererMode::RENDER_2D :
            auto it = m_2DRenderers.find(name);
            if(it != m_2DRenderers.end())
            {
                m_2DRenderers.erase(name);
            }            
            break;
        default:
            break;
    }
}

void BENG::RenderingSystem::Draw2D()
{
    for (const auto & [ name, renderer ] : m_2DRenderers) {
        renderer->Render();
    }
}

void BENG::RenderingSystem::Draw3D()
{
    for (const auto & [ name, renderer ] : m_3DRenderers) {
        renderer->Render();
    }
}
