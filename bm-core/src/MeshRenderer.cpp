#include "raylib.h"
#include "raymath.h"


#include "BMEngine/MeshRenderer.h"

using namespace BENG;

void MeshRenderer::Render()
{
    DrawMesh(m_Mesh, m_Material, MatrixTranslate(0.0f,0.0f,0.0f));
}