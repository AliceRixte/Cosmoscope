#include <iostream>

#include "CSC_FuncTree.h"
#include "CSC_CosmosDrawer.h"

#include "CallbackExamples.h"
#include "CSC_CallbackTools.h"

using namespace cosmoscope;

int main(int argc, char* argv[])
{
    cosmoscope::Style invisible = cosmoscope::Style{
        cosmoscope::Color{ 0.,0.,0.,0. },
        cosmoscope::BrushStyle{-1.,0.}
    };

    cosmoscope::Color red{ 0.9,0.1,0.2,0.5};
    cosmoscope::BrushStyle soft_brush{ 0.0,0.5 };

    cosmoscope::FuncTree ftree;

    ftree.AddMonochromeFunc(-1, createCircle(200.0, 1.0), invisible);
    ftree.AddMonochromeFunc(0,  createCircle(150.0,1/150.0), invisible);
    ftree.AddMonochromeFunc(1, createCircle(60.0,-1.0),cosmoscope::Style{red,soft_brush});// &style1); 

    //ftree.AddMonochromeFunc(-1, createCircle(300,1/401.0), cosmoscope::Style{1.,0.,0.,1.,-1.});
    //ftree.AddPolychromeFunc(0, createCircle(190,1/170.0), &style3);

    cosmoscope_SDL::CosmosDrawer cosmosDrawer1{ "Cosmoscope",1000,1000,&ftree};

    while (cosmosDrawer1.IsWindowOpen()) {
        cosmosDrawer1.ProcessEvents();
        cosmosDrawer1.UpdateFrame();
    }

    return 0;
}