#include "BMEngine/ResourcesSystem.h"
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


using namespace BENG;

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

    Model model = s_Game.GetResourcesSystem()->LoadModel("models/monkey.obj");

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