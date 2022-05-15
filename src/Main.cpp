#include <iostream>

#include "GL/glew.h"
#include <SDL_opengl.h>

#include "CSC_FuncTree.h"
#include "CSC_CosmosWindowSDL.h"
//#include "Brushes.h"

#include "CallbackExamples.h"
#include "CSC_CallbackTools.h"

#include "boost/geometry.hpp"
#include "boost/geometry/geometries/geometries.hpp"

const GLint WIDTH = 800, HEIGHT = 600;

namespace bg = boost::geometry;

using CartesianPoint = boost::geometry::model::point<double, 3, boost::geometry::cs::cartesian>;
using PolarPoint = boost::geometry::model::point<double, 3, boost::geometry::cs::spherical<boost::geometry::degree>>;

using namespace cosmoscope;
using namespace cosmoscopeSDL;

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
    }

    /*SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    SDL_Window* glwin = SDL_CreateWindow("CosmoscopeGL", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);

    SDL_GLContext context = SDL_GL_CreateContext(glwin);

    glewExperimental = GL_TRUE;

    if (GLEW_OK != glewInit()) {
        std::cout << "Error in glew initialisation"<< std::endl;
        return EXIT_FAILURE;
    }
    glViewport(0, 0, WIDTH, HEIGHT);*/

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
    cosmoscope::Color white{ 1.0,1.0,1.0,0.5 };
    cosmoscope::Color green{ 0.1,0.9,0.2,1.0 };
    cosmoscope::Color yellow{ 1.0,0.9,0.2,1.0 };
    cosmoscope::BrushStyle soft_brush{ 0.7,0.0 };
    cosmoscope::BrushStyle hard_brush{ 1.0,0.9 };

    cosmoscope::Style soft_red{ red,soft_brush };
    cosmoscope::Style soft_green{ green,soft_brush };
    cosmoscope::Style soft_yellow{ yellow,soft_brush };

    cosmoscope::FuncTree ftree;

   // ftree.AddMonochromeFunc(-1, createCircle(200.0, 1.0), invisible);
   // ftree.AddMonochromeFunc(0,  createCircle(150.0,1/150.0), invis ible);
   //  ftree.AddMonochromeFunc(1, createCircle(60.0,-1.0),cosmoscope::Style{red,soft_brush});// &style1); 

 

    float zoom = 0.35;
    float resolution = 0.4/128.0;
    ftree.AddTimedMonochromeFunc(-1,timeMultiplier(resolution), createCircle(1.0 * zoom, 0.1344567), invisible);
    ftree.AddMonochromeFunc(0,  createCircle(0.6 *zoom,1/5.0), invisible);
    ftree.AddTimedMonochromeFunc(1, timeMultiplier(4),createCircle(0.3 * zoom, -1 / 5.0),Style {white,soft_brush});
    //ftree.AddMonochromeFunc(2, createCircle(0.3 * zoom, -1 / 32.0 * resolution), invisible);
   // ftree.AddPolychromeFunc(2, createCircle(0.4 * zoom,8.752*128 * resolution), styleRedBlue);//cosmoscope::Style{ r,soft_brush });
   
    //ftree.AddMonochromeFunc(-1, createCircle(300,1/401.0), cosmoscope::Style{1.,0.,0.,1.,-1.});
    //ftree.AddPolychromeFunc(0, createCircle(190,1/170.0), &style3);

    int padx = 0;
    int pady = 0;
    int height = 1000;
    int width = 1000;
    SDL_Rect draw_area{ 0,0,width,height };
    cosmoscopeSDL::CosmosDrawerSDL cosmos_drawer{draw_area};
    cosmoscopeSDL::CosmovertorSDL cosmovertor {cosmoscopeSDL::Point{ width / 2.0 + padx, height / 2.0 + pady },
        sqrt(width * width + height * height) / 2.0, 100.0 };
    cosmoscope::Scheduler scheduler{ std::move(ftree) };

    WindowManager*  cosmosWindow = new CosmosWindowSDL{"Cosmoscope",width,height,scheduler, cosmovertor, cosmos_drawer};
    
    while (cosmosWindow->IsWindowOpen()) {
        cosmosWindow->ProcessEvents();
        cosmosWindow->UpdateFrame();
    }
    delete cosmosWindow;
    SDL_Quit();

    return 0;
}