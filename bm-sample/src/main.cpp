#include "BMEngine/Game.h"

using namespace BENG;

int main()
{
    // TODO: Create this from an .INI file
    GameConf conf;

    conf.winTitle = "Boom Engine Sample App";
    conf.winWidth = 800;
    conf.winHeight = 600;
    conf.clearColor = DARKGRAY;
    conf.targetFPS = 60;

    s_Game.Setup(conf);
    
    s_Game.Start();

    return 0;
}