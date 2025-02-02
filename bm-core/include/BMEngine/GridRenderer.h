#pragma once

#include "raylib.h"

#include "BMEngine/Renderer.h"
#include "BMEngine/RenderingSystem.h"

namespace BENG{
    class GridRenderer : public Renderer
    {
        public:
            GridRenderer(int32_t slices, float spacing , std::string name) : Renderer(name)
            {
                m_Slices = slices;
                m_Spacing = spacing;
            }

            void Render() override;

        private:
            int32_t m_Slices;
            float m_Spacing;
    };
}