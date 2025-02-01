#pragma once

#include <string>

namespace BENG
{
    class GameObjectComponent
    {
        public:
            GameObjectComponent(std::string name) : m_Name(name) {}

            virtual void Start(){}
            virtual void Update(float dt) {}

            std::string GetName() 
            {
                return m_Name;
            }

        private:
            std::string m_Name;
    };
}