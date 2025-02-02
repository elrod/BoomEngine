#pragma once

#include <memory>
#include <unordered_map>

#include "BMEngine/Renderer.h"

namespace BENG
{
    enum RendererMode
    {
        RENDER_2D,
        RENDER_3D
    };

    class RenderingSystem 
    {
        public:
            void Register(std::shared_ptr<Renderer> renderer);
            void Deregister(std::shared_ptr<Renderer> renderer);
            void Draw2D();
            void Draw3D();

        private:
            std::unordered_map<std::string, std::shared_ptr<Renderer>> m_3DRenderers;
            std::unordered_map<std::string, std::shared_ptr<Renderer>> m_2DRenderers;
    };
}
