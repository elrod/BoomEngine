#include <iostream>

#include "raylib.h"

#include "BMEngine/Game.h"
#include "BMEngine/Scene.h"
#include "BMEngine/SceneSystem.h"
#include "BMEngine/ResourcesSystem.h"
#include "BMEngine/RenderingSystem.h"

using namespace BENG;

Game::Game() 
{
    m_Systems[std::type_index(typeid(SceneSystem))] = std::make_unique<SceneSystem>();
    m_Systems[std::type_index(typeid(ResourcesSystem))] = std::make_unique<ResourcesSystem>();
    m_Systems[std::type_index(typeid(RenderingSystem))] = std::make_unique<RenderingSystem>();
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

void Game::Initialize()
{
    // Initialize game here
    GetSystem<BENG::SceneSystem>()->GetCurrentScene()->Init();
    std::cout << "Game initialized!" << std::endl;
}

void Game::ProcessInput() {
    // Input processing code here
    std::cout << "Processing input..." << std::endl;
}

void Game::Update(float dt) {
    // Game logic update code here
    GetSystem<BENG::SceneSystem>()->GetCurrentScene()->Update(dt);
    std::cout << "Game updated!" << std::endl;
}

void Game::Draw() {
    // Drawing code here
    BeginDrawing();
        ClearBackground(m_gameConf.clearColor);
        BeginMode2D(*GetSystem<BENG::SceneSystem>()->GetCurrentScene()->Get2DCamera());
            GetSystem<BENG::RenderingSystem>()->Draw2D();
        EndMode2D();
        BeginMode3D(*GetSystem<BENG::SceneSystem>()->GetCurrentScene()->Get3DCamera());
            GetSystem<BENG::RenderingSystem>()->Draw3D();
        EndMode3D();
    EndDrawing();
    std::cout << "Game drawn!" << std::endl;
}

void Game::Cleanup() {
    // Cleanup code here
    CloseWindow();
    std::cout << "Game cleaned up!" << std::endl;
}