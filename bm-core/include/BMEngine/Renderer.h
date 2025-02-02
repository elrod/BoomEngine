#pragma once

#include <string>

#include "BMEngine/RenderingSystem.h"
#include "BMEngine/GameObjectComponent.h"

namespace BENG
{
    class Renderer : public GameObjectComponent
    {
        public:
            Renderer(std::string name, RenderingSystem::RendererMode rendererType =  RenderingSystem::RendererMode::RENDER_3D) : GameObjectComponent(name) 
            {
                m_RendererType = rendererType;
            }
            ~Renderer() {}

            RenderingSystem::RendererMode GetRendererType() const
            {
                return m_RendererType;
            }

            virtual void Render() {};

        private:
            RenderingSystem::RendererMode m_RendererType;
    };
}