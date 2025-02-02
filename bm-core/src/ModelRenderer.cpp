#include "raylib.h"

#include "BMEngine/ModelRenderer.h"

using namespace BENG;

void ModelRenderer::Render()
{
    DrawModel(m_Model, {0.0f,0.0f,0.0f} , 1.0f, WHITE);
}