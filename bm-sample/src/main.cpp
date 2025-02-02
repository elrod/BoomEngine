#include "BMEngine/RenderingSystem.h"
#include "BMEngine/SceneSystem.h"
#include "BMEngine/Scene.h"
#include "BMEngine/GameObject.h"
#include "BMEngine/Game.h"
#include "BMEngine/ModelRenderer.h"
#include "BMEngine/GridRenderer.h"

#include <iostream>
#include <string>
#include <memory>

#include "raylib.h"

#if defined PLATFORM_DESKTOP
    #define GLSL_VERSION            330
#else
    #define GLSL_VERSION            100
#endif

#if defined __APPLE__ && PLATFORM_OSX
    #include <mach-o/dyld.h>
#endif


using namespace BENG;

std::string get_executable_path() {
#if defined __APPLE__ && PLATFORM_OSX
    char buffer[PATH_MAX];
    uint32_t bufsize = sizeof(buffer);
    if (_NSGetExecutablePath(buffer, &bufsize) == 0) {
        return std::string(buffer);
    }
#endif
    return "";
}

// TODO: There should be a serialized asset describing the scene and the 
// SceneSystem should actually create the scene starting from the serialized scene asset
std::unique_ptr<Scene> make_sample_scene()
{
    std::unique_ptr<Scene> sampleScene = std::make_unique<Scene>();

    {
        auto cam3D = sampleScene->Get3DCamera();
        if(cam3D != nullptr)
        {
            cam3D->position = {4.0f, 4.0f, 4.0f};
            cam3D->target = {0.0f, 1.0f, 0.0f};
            cam3D->up = {0.0f, 1.0f, 0.0f};
            cam3D->fovy = 45.0f;
            cam3D->projection = CAMERA_PERSPECTIVE;
        }    
    }

    // TODO: move this resource loading logic to some kind of Resource System
    std::string basePath = get_executable_path();
    std::string modelPath = "";
    if (!basePath.empty()) {
        // Assuming the resources directory is sibling to the executable
        modelPath = basePath.substr(0, basePath.find_last_of('/')) + "/resources/models/monkey.obj";
    }
    else
    {
        modelPath = "/resources/models/monkey.obj";
    }

    std::cout << modelPath << std::endl;

    Model model = LoadModel(modelPath.c_str());
    if (model.meshCount == 0) {
        TraceLog(LOG_ERROR, "Failed to load model.");
        exit(1);
    }

    std::unique_ptr<GameObject> monkeyObj = std::make_unique<GameObject>("Monkey");
    {
        std::shared_ptr<ModelRenderer> modelRenderer = std::make_shared<ModelRenderer>(model, "ModelRenderer");
        monkeyObj->AddComponent(modelRenderer);
        s_Game.GetRenderingSystem()->Register(modelRenderer);
    }

    std::unique_ptr<GameObject> gridObj = std::make_unique<GameObject>("Grid");
    {
        std::shared_ptr<GridRenderer> gridRenderer = std::make_shared<GridRenderer>(10, 1.0f, "GridRenderer");
        gridObj->AddComponent(gridRenderer);
        s_Game.GetRenderingSystem()->Register(gridRenderer);
    }
    
    sampleScene->AddGameObject(std::move(gridObj));

    return sampleScene;
}

int main()
{
    // TODO: Create this from an .INI file
    GameConf conf;

    conf.winTitle = "Boom Engine Sample App";
    conf.winWidth = 640;
    conf.winHeight = 480;
    conf.clearColor = DARKGRAY;
    conf.targetFPS = 60;

    s_Game.Setup(conf);
    
    s_Game.GetSceneSystem()->LoadScene(std::move(make_sample_scene()));
    s_Game.Start();

    return 0;
}