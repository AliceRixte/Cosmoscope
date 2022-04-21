#include <iostream>

#include "CSC_FuncTree.h"
#include "WindowManager.h"

#include "CallbackExamples.h"
#include "CSC_CallbackTools.h"

#include "boost/geometry.hpp"
#include "boost/geometry/geometries/geometries.hpp"

namespace bg = boost::geometry;

using CartesianPoint = boost::geometry::model::point<double, 3, boost::geometry::cs::cartesian>;
using PolarPoint = boost::geometry::model::point<double, 3, boost::geometry::cs::spherical<boost::geometry::degree>>;

using namespace cosmoscope;

int main(int argc, char* argv[])

{

    using point = bg::model::point <double, 2, bg::cs::cartesian>;
    using linestring = bg::model::linestring<point>;

    linestring ls;
    bg::read_wkt("LINESTRING(0 3, 3 0, 4 0)", ls);
    std::cout << bg::distance(point(0, 0), point(1, 1))<<std::endl;

    PolarPoint pp{45,0,1.41};
    CartesianPoint p{2,2,0 };
    

    bg::transform(pp,p);
    std::cout << bg::dsv(p) << std::endl;
    std::cout << bg::dsv(pp) << std::endl;


    
    
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
    cosmoscopeSDL::CosmovertorSDL cosmovertor{std::move(ftree), sqrt(width * width + height * height) / 2.0,
        cosmoscopeSDL::Point{ static_cast<float>(width / 2.0),static_cast<float>(height / 2.0) }, 100.0 };

    WindowManager windowManager{"Cosmoscope",width,height,cosmos_drawer,cosmovertor};

    while (windowManager.IsWindowOpen()) {
        windowManager.ProcessEvents();
        windowManager.UpdateFrame();
    }


    return 0;
}