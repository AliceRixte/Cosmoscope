#include <iostream>

#include "CSC_FuncTree.h"
#include "WindowManager.h"

#include "CallbackExamples.h"
#include "CSC_CallbackTools.h"

using namespace cosmoscope;

int main(int argc, char* argv[])
{
    cosmoscope::Style invisible = cosmoscope::Style{
        cosmoscope::Color{ 0.,0.,0.,0. },
        cosmoscope::BrushStyle{0.0,-1.0}
    };

    cosmoscope::Color red{ 0.9,0.1,0.2,1.0};
    cosmoscope::BrushStyle soft_brush{ 1.0,0.0 };
    cosmoscope::BrushStyle hard_brush{ 1.0,0.9 };

    cosmoscope::FuncTree ftree;

   // ftree.AddMonochromeFunc(-1, createCircle(200.0, 1.0), invisible);
   // ftree.AddMonochromeFunc(0,  createCircle(150.0,1/150.0), invis ible);
   //  ftree.AddMonochromeFunc(1, createCircle(60.0,-1.0),cosmoscope::Style{red,soft_brush});// &style1); 

    float zoom = 5.0;
    ftree.AddMonochromeFunc(-1, createCircle(0.1*zoom, 1.75), invisible);
    ftree.AddMonochromeFunc(0,  createCircle(0.4*zoom,1/150.0), invisible);
    ftree.AddMonochromeFunc(1, createCircle(0.4* zoom, -2.0), cosmoscope::Style{ red,soft_brush });// &style1); 
   
    //ftree.AddMonochromeFunc(-1, createCircle(300,1/401.0), cosmoscope::Style{1.,0.,0.,1.,-1.});
    //ftree.AddPolychromeFunc(0, createCircle(190,1/170.0), &style3);

    int height = 1000;
    int width = 1000;
    cosmoscopeSDL::CosmosDrawerSDL cosmos_drawer;
    cosmoscopeSDL::CosmovertorSDL cosmovertor{&ftree, sqrt(width * width + height * height) / 2.0,
        floatpix::Position{ static_cast<float>(width / 2.0),static_cast<float>(height / 2.0) }, 100.0 };

    WindowManager windowManager{"Cosmoscope",width,height,cosmos_drawer,cosmovertor};

    while (windowManager.IsWindowOpen()) {
        windowManager.ProcessEvents();
        windowManager.UpdateFrame();
    }

    return 0;
}