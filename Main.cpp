#include <SDL.h>
#include <iostream>
#include "FuncTree.h"
#include <cmath>
#include "brushes.h"
#include "CosmosToSDL.h"
#include "CallbackExamples.h"
#include "CosmosDrawer.h"




#include <filesystem>
#include <string>

namespace fs = std::filesystem;

using std::filesystem::current_path;
using namespace cosmoscope;

int main(int argc, char* argv[])
{
    cosmoscope::FuncTree ftree{ cosmoscope::Position{450,450} };
    ftree.AddMonochromeFunc(-1, &line, cosmoscope::CoorSystem::Polar, cosmoscope::Style{ 1.,0.,0.,1.,-1. });
    ftree.AddPolychromeFunc(0, &circle, cosmoscope::CoorSystem::Polar, &style2);
    ftree.AddMonochromeFunc(1, &circle4, cosmoscope::CoorSystem::Polar, cosmoscope::Style{ 0.9,0.1,0.2,1., });
    // ftree.AddPolychromeFunc(1, &circle3, cosmoscope::CoorSystem::Polar, &style1);
     //ftree.AddPolychromeFunc(2, &circle3, cosmoscope::CoorSystem::Polar, &style2);



    cosmoscope_SDL::CosmosDrawer cosmosDrawer{ "Cosmoscope",900,900,&ftree};


    while (cosmosDrawer.m_isAppRunning) {
        cosmosDrawer.ProcessEvents();
        cosmosDrawer.UpdateFrame();

    }

    return 0;
}