#pragma once

#include "BMEngine/SceneSystem.h"

#include "raylib.h"

namespace BENG
{
    struct GameConf
    {
        char const *winTitle = "My Game";
        int winHeight = 1920;
        int winWidth = 1080;
        Color clearColor = WHITE;
        int targetFPS = 60;
    };

    class Game
    {
        public:
            Game();

            void Setup(const GameConf& conf);
            void Start();

            SceneSystem * GetSceneSystem();

        private:
            GameConf m_gameConf;
            std::unique_ptr<SceneSystem> m_sceneSystem;

            void Initialize();
            void ProcessInput();
            void Update(float dt);
            void Draw();
            void Cleanup();
    };

    inline Game s_Game;
}
