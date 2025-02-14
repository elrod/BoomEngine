#include "BMEngine/ResourcesSystem.h"

#if defined __APPLE__ && PLATFORM_OSX
    #include <mach-o/dyld.h>
#endif

namespace BENG {

    Model ResourcesSystem::LoadModel(const std::string& path) {
        auto it = m_Models.find(path);
        if (it != m_Models.end()) {
            return it->second;
        }

        std::string resolvedPath = ResolvePath(path);
        Model model = ::LoadModel(resolvedPath.c_str());
        if (model.meshCount == 0) {
            TraceLog(LOG_ERROR, "Failed to load model: %s", resolvedPath.c_str());
        } else {
            m_Models[path] = model;
        }
        return model;
    }

    Shader ResourcesSystem::LoadShader(const std::string& vsPath, const std::string& fsPath)
    {
        std::string shaderKey = vsPath + fsPath;
        auto it = m_Shaders.find(shaderKey);
        if (it != m_Shaders.end()) {
            return it->second;
        }

        std::string resolvedVSPath = ResolvePath(vsPath);
        std::string resolvedFSPath = ResolvePath(fsPath);

        Shader shader = ::LoadShader(resolvedVSPath.c_str(), resolvedFSPath.c_str());
        if (shader.id == 0) {
            TraceLog(LOG_ERROR, "Failed to load shader: vs: %s, fs: %s", resolvedVSPath.c_str(), resolvedFSPath.c_str());
        } else {
            m_Shaders[shaderKey] = shader;
        }
        return shader;
    }

    Texture2D ResourcesSystem::LoadTexture(const std::string& path) {
        auto it = m_Textures.find(path);
        if (it != m_Textures.end()) {
            return it->second;
        }

        std::string resolvedPath = ResolvePath(path);
        Texture2D texture = ::LoadTexture(resolvedPath.c_str());
        if (texture.id == 0) {
            TraceLog(LOG_ERROR, "Failed to load texture: %s", resolvedPath.c_str());
        } else {
            m_Textures[path] = texture;
        }
        return texture;
    }

    std::string ResourcesSystem::ResolvePath(const std::string& path) {
        if (m_BasePath.empty()) {
            m_BasePath = get_executable_path();
        }
        return m_BasePath.substr(0, m_BasePath.find_last_of('/')) + "/resources/" + path;
    }

    std::string ResourcesSystem::get_executable_path() {
        #if defined __APPLE__ && PLATFORM_OSX
            char buffer[PATH_MAX];
            uint32_t bufsize = sizeof(buffer);
            if (_NSGetExecutablePath(buffer, &bufsize) == 0) {
                return std::string(buffer);
            }
        #endif
        return "";
    }

}