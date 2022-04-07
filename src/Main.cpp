#include <iostream>

#include "CSC_FuncTree.h"
#include "CosmosDrawer.h"

#include "CallbackExamples.h"

using namespace cosmoscope;

int main(int argc, char* argv[])
{
    cosmoscope::FuncTree ftree{ cosmoscope::CartesianPos{450,450} };
    ftree.AddMonochromeFunc(-1, &line   , cosmoscope::Style{ 1.,0.,0.,1.,-1. });
    ftree.AddPolychromeFunc(0,  &circle , &style2);
    ftree.AddMonochromeFunc(1,  &circle4, cosmoscope::Style{ 0.9,0.1,0.2,1.,0.0});
    // ftree.AddPolychromeFunc(1, &circle3, cosmoscope::CoorSystem::Polar, &style1);
     //ftree.AddPolychromeFunc(2, &circle3, cosmoscope::CoorSystem::Polar, &style2);

    cosmoscope_SDL::CosmosDrawer cosmosDrawer1{ "Cosmoscope",900,900,&ftree};

    while (cosmosDrawer1.IsWindowOpen()) {
        cosmosDrawer1.ProcessEvents();
        cosmosDrawer1.UpdateFrame();
    }

    return 0;
}