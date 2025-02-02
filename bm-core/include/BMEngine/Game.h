#pragma once

#include "raylib.h"

namespace BENG
{
    class SceneSystem;
    class RenderingSystem;

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
            ~Game();

            void Setup(const GameConf& conf);
            void Start();

            SceneSystem* GetSceneSystem();
            RenderingSystem* GetRenderingSystem();

        private:
            GameConf m_gameConf;
            std::unique_ptr<SceneSystem> m_SceneSystem;
            std::unique_ptr<RenderingSystem> m_RenderingSystem;

            void Initialize();
            void ProcessInput();
            void Update(float dt);
            void Draw();
            void Cleanup();
    };

    inline Game s_Game;
}
