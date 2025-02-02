#include <iostream>

#include "raylib.h"

#include "BMEngine/GridRenderer.h"

void BENG::GridRenderer::Render()
{
    std::cout << "Render Grid" << std::endl;
    DrawGrid(m_Slices, m_Spacing);
}