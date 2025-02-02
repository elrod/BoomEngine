#pragma once

#include <string>
#include <memory>
#include <unordered_map>

namespace BENG
{
    class Renderer;

    class RenderingSystem 
    {
        public:
            RenderingSystem(){}
            ~RenderingSystem(){}

            enum RendererMode
            {
                RENDER_2D,
                RENDER_3D
            };
            
            void Register(std::shared_ptr<Renderer> renderer);
            void Deregister(std::shared_ptr<Renderer> renderer);
            void Draw2D();
            void Draw3D();

        private:
            std::unordered_map<std::string, std::shared_ptr<Renderer>> m_3DRenderers;
            std::unordered_map<std::string, std::shared_ptr<Renderer>> m_2DRenderers;
    };
}
