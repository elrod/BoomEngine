#include <iostream>

#include "raylib.h"

#include "BMEngine/Game.h"
#include "BMEngine/Scene.h"
#include "BMEngine/SceneSystem.h"
#include "BMEngine/RenderingSystem.h"
#include "BMEngine/ResourcesSystem.h"

using namespace BENG;

Game::Game() 
{
    m_ResourcesSystem = std::make_unique<ResourcesSystem>();
    m_SceneSystem = std::make_unique<SceneSystem>();
    m_RenderingSystem = std::make_unique<RenderingSystem>();
}

Game::~Game()
{
}

void Game::Setup(const GameConf& conf)
{
    m_gameConf = conf;

    InitWindow(m_gameConf.winWidth, m_gameConf.winHeight, m_gameConf.winTitle);
    SetTargetFPS(m_gameConf.targetFPS);

}

void Game::Start() {
    Initialize();
    while (!WindowShouldClose()) {
        ProcessInput();
        Update(GetFrameTime());
        Draw();
    }
    Cleanup();
}

SceneSystem* Game::GetSceneSystem()
{
    return m_SceneSystem.get();
}

ResourcesSystem *BENG::Game::GetResourcesSystem()
{
    return m_ResourcesSystem.get();
}

RenderingSystem *BENG::Game::GetRenderingSystem()
{
    return m_RenderingSystem.get();
}

void Game::Initialize()
{
    // Initialize game here
    m_SceneSystem->GetCurrentScene()->Init();
    std::cout << "Game initialized!" << std::endl;
}

void Game::ProcessInput() {
    // Input processing code here
    std::cout << "Processing input..." << std::endl;
}

void Game::Update(float dt) {
    // Game logic update code here
    m_SceneSystem->GetCurrentScene()->Update(dt);
    std::cout << "Game updated!" << std::endl;
}

void Game::Draw() {
    // Drawing code here
    BeginDrawing();
        ClearBackground(m_gameConf.clearColor);
        BeginMode2D(*m_SceneSystem->GetCurrentScene()->Get2DCamera());
            m_RenderingSystem->Draw2D();
        EndMode2D();
        BeginMode3D(*m_SceneSystem->GetCurrentScene()->Get3DCamera());
            m_RenderingSystem->Draw3D();
        EndMode3D();
    EndDrawing();
    std::cout << "Game drawn!" << std::endl;
}

void Game::Cleanup() {
    // Cleanup code here
    CloseWindow();
    std::cout << "Game cleaned up!" << std::endl;
}