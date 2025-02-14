#pragma once

#include <string>
#include <unordered_map>

#include "BMEngine/GameSystem.h"

#include "raylib.h"

namespace BENG {

    class ResourcesSystem : public GameSystem 
    {
        public:
            ResourcesSystem(){}
            ~ResourcesSystem(){}
            Model LoadModel(const std::string& path);
            Shader LoadShader(const std::string& vsPath, const std::string& fsPath);
            Texture2D LoadTexture(const std::string& path);

        private:
            std::string ResolvePath(const std::string& path);
            std::string get_executable_path();

            std::unordered_map<std::string, Model> m_Models;
            std::unordered_map<std::string, Shader> m_Shaders;
            std::unordered_map<std::string, Texture2D> m_Textures;

            std::string m_BasePath;
    };

}