#pragma once

#include <string>

#include "BMEngine/RenderingSystem.h"
#include "BMEngine/GameObjectComponent.h"

namespace BENG
{
    class Renderer : public GameObjectComponent
    {
        public:
            Renderer(std::string name, RendererMode rendererType = RendererMode::RENDER_3D) : GameObjectComponent(name) 
            {
                m_RendererType = rendererType;
            }

            RendererMode GetRendererType() const
            {
                return m_RendererType;
            }

            virtual void Render() = 0;

        private:
            RendererMode m_RendererType;
    };
}