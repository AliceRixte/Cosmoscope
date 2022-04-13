#include <iostream>

#include "CSC_FuncTree.h"
#include "CosmosDrawer.h"

#include "CallbackExamples.h"
#include "CSC_CallbackTools.h"

using namespace cosmoscope;

int main(int argc, char* argv[])
{
    cosmoscope::FuncTree ftree{ cosmoscope::CartesianPos{495,495},450};
    ftree.AddMonochromeFunc(-1, createCircle(200.0,1.0), cosmoscope::Style{1.,0.,0.,1.,-1.});
    ftree.AddMonochromeFunc(0,  createCircle(150.0,1/150.0), cosmoscope::Style{1.,0.,0.,1.,-1.});
    ftree.AddPolychromeFunc(1, createCircle(60.0,-1.0), &style1); //cosmoscope::Style{ 0.9,0.1,0.2,1.,0.0});

    //ftree.AddMonochromeFunc(-1, createCircle(300,1/401.0), cosmoscope::Style{1.,0.,0.,1.,-1.});
    //ftree.AddPolychromeFunc(0, createCircle(190,1/170.0), &style3);

    cosmoscope_SDL::CosmosDrawer cosmosDrawer1{ "Cosmoscope",1000,1000,&ftree};

    while (cosmosDrawer1.IsWindowOpen()) {
        cosmosDrawer1.ProcessEvents();
        cosmosDrawer1.UpdateFrame();
    }

    return 0;
}