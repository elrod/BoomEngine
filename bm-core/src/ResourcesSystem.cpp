#include "BMEngine/ResourcesSystem.h"

namespace BENG {

    Model ResourcesSystem::LoadModel(const std::string& path) {
        auto it = models.find(path);
        if (it != models.end()) {
            return it->second;
        }

        std::string resolvedPath = ResolvePath(path);
        Model model = ::LoadModel(resolvedPath.c_str());
        if (model.meshCount == 0) {
            TraceLog(LOG_ERROR, "Failed to load model: %s", resolvedPath.c_str());
        } else {
            models[path] = model;
        }
        return model;
    }

    Texture2D ResourcesSystem::LoadTexture(const std::string& path) {
        auto it = textures.find(path);
        if (it != textures.end()) {
            return it->second;
        }

        std::string resolvedPath = ResolvePath(path);
        Texture2D texture = ::LoadTexture(resolvedPath.c_str());
        if (texture.id == 0) {
            TraceLog(LOG_ERROR, "Failed to load texture: %s", resolvedPath.c_str());
        } else {
            textures[path] = texture;
        }
        return texture;
    }

    std::string ResourcesSystem::ResolvePath(const std::string& path) {
        if (basePath.empty()) {
            basePath = get_executable_path();
        }
        return basePath.substr(0, basePath.find_last_of('/')) + "/resources/" + path;
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

} // namespace BENG