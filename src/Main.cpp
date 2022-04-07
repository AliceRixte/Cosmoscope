#include <SDL.h>
#include <iostream>
#include "CSC_FuncTree.h"
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



    cosmoscope_SDL::CosmosDrawer cosmosDrawer1{ "Cosmoscope",900,900,&ftree};
    cosmoscope_SDL::CosmosDrawer cosmosDrawer2{ "Cosmoscope",900,900,&ftree };


    while (cosmosDrawer1.IsWindowOpen()&& cosmosDrawer2.IsWindowOpen()) {
        cosmosDrawer1.ProcessEvents();
        cosmosDrawer1.UpdateFrame();

        cosmosDrawer2.ProcessEvents();
        cosmosDrawer2.UpdateFrame();

    }

    return 0;
}