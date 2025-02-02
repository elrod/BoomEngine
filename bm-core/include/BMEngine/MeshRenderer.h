#pragma once

#include "raylib.h"

#include "BMEngine/Renderer.h"
#include "BMEngine/RenderingSystem.h"


namespace BENG{
    class MeshRenderer : public Renderer
    {
        public:
            MeshRenderer(Mesh mesh, Material material, std::string name) : Renderer(name)
            {
                m_Mesh = mesh;
                m_Material = material;
            }

            void Render() override;

        private:
            Mesh m_Mesh;
            Material m_Material;
    };
}