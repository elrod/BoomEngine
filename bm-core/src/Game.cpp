#include <iostream>

#include "raylib.h"

#include "BMEngine/Game.h"
#include "BMEngine/Scene.h"
#include "BMEngine/SceneSystem.h"

using namespace BENG;

Game::Game() 
{
    m_sceneSystem = std::make_unique<SceneSystem>();

    InitWindow(m_gameConf.winWidth, m_gameConf.winHeight, m_gameConf.winTitle);
    SetTargetFPS(m_gameConf.targetFPS);

}

void Game::Setup(const GameConf& conf)
{
    m_gameConf = conf;
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
    return m_sceneSystem.get();
}

void Game::Initialize() {
    // Initialize game here
    m_sceneSystem->GetCurrentScene()->Init();
    std::cout << "Game initialized!" << std::endl;
}

void Game::ProcessInput() {
    // Input processing code here
    std::cout << "Processing input..." << std::endl;
}

void Game::Update(float dt) {
    // Game logic update code here
    m_sceneSystem->GetCurrentScene()->Update(dt);
    std::cout << "Game updated!" << std::endl;
}

void Game::Draw() {
    // Drawing code here
    BeginDrawing();
        ClearBackground(m_gameConf.clearColor);
    EndDrawing();
    std::cout << "Game drawn!" << std::endl;
}

void Game::Cleanup() {
    // Cleanup code here
    CloseWindow();
    std::cout << "Game cleaned up!" << std::endl;
}