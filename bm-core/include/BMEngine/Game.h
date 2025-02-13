#pragma once

#include <unordered_map>
#include <typeindex>

#include "BMEngine/GameSystem.h"

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
            ~Game();

            void Setup(const GameConf& conf);
            void Start();

            template<typename TSystemType>
            TSystemType* GetSystem() const
            {
                auto it = m_Systems.find(std::type_index(typeid(TSystemType)));
                if (it != m_Systems.end()) {
                    return static_cast<TSystemType*>(it->second.get());
                }
                return nullptr;
            }

        private:
            GameConf m_gameConf;
            std::unordered_map<std::type_index, std::unique_ptr<GameSystem>> m_Systems;

            void Initialize();
            void ProcessInput();
            void Update(float dt);
            void Draw();
            void Cleanup();
    };

    inline Game s_Game;
}
