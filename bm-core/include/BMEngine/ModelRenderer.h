#pragma once

#include "raylib.h"

#include "BMEngine/Renderer.h"

namespace BENG{
    class ModelRenderer : public Renderer
    {
        public:
            ModelRenderer(Model model, std::string name) : Renderer(name)
            {
                m_Model = model;
            }

            void Render() override;

        private:
            Model m_Model;
    };
}