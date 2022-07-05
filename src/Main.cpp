
#include <iostream>
#include <cmath>


#include "GL/glew.h"
#include <SDL_opengl.h>

#include "CSC_FuncTree.h"
#include "CSC_CosmosWindowSDL.h"
#include "CSC_CosmosWindowGL.h"

#include "CSC_CosmicMachine.h"


#include "CallbackExamples.h"
#include "CSC_CallbackTools.h"

#include "boost/geometry.hpp"
#include "boost/geometry/geometries/geometries.hpp"

const GLint WIDTH = 1700, HEIGHT = 600;

namespace bg = boost::geometry;

using CartesianPoint = boost::geometry::model::point<double, 3, boost::geometry::cs::cartesian>;
using PolarPoint = boost::geometry::model::point<double, 3, boost::geometry::cs::spherical<boost::geometry::degree>>;

using namespace cosmoscope;
using namespace cosmoscopeSDL;
using namespace cosmoscopeGL;
using namespace std;



void testShader(CosmicState& state, const std::unordered_map <std::string, CosmicShader>&  shaders) {
    
    if (shaders.at("main").OlderStateExists(1)) {
        CosmicState older = shaders.at("main").GetOlderState(1);
        state["t"] = older.value("t", 0.0) + 1;
    }    
    cout << "now" << state << endl;
   
}

void sqrShader(CosmicState& state, const std::unordered_map <std::string, CosmicShader>& shaders) {
    state["pos"]["x"] = state.at("t") + pow(state["/pos/x"_json_pointer], 2.0);
    state["/pos/y"_json_pointer] = state.at("t") + pow(state["/pos/x"_json_pointer], 2.0);

}



int main(int argc, char* argv[])
{

    CosmicMachine machine{
        {
            {"t",0.0},
            {"pos",{
                {"x",0.0},
                {"y",0.0}
            }}
        }
    };

    machine.AddShader("main", testShader, { "sqr" }, 2);
    machine.AddShader("sqr", sqrShader, {"main"});
    for (int i = 0; i < 10; i++) {
        machine.NextStep();
       // cout << machine.GetCurrentState() << endl;
    }




    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
    }


    // using point = bg::model::point <double, 2, bg::cs::cartesian>;
    // using linestring = bg::model::linestring<point>;

    // linestring ls;
    // bg::read_wkt("LINESTRING(0 3, 3 0, 4 0)", ls);
    // std::cout << bg::distance(point(0, 0), point(1, 1))<<std::endl;

    // PolarPoint pp{45,0,1.41};
    // CartesianPoint p{2,2,0 };
    // 

    // bg::transform(pp,p);
    // std::cout << bg::dsv(p) << std::endl;
    // std::cout << bg::dsv(pp) << std::endl;


    // 
    // 
    // cosmoscope::Style invisible = cosmoscope::Style{
    //     cosmoscope::Color{ 0.,0.,0.,0. },
    //     cosmoscope::BrushStyle{0.0,-1.0}
    // };

    // cosmoscope::Color red{ 0.9,0.1,0.2,1.0};
    // cosmoscope::Color white{ 1.0,1.0,1.0,0.5 };
    // cosmoscope::Color green{ 0.1,0.9,0.2,1.0 };
    // cosmoscope::Color yellow{ 1.0,0.9,0.2,1.0 };
    // cosmoscope::BrushStyle soft_brush{ 0.1,0.0 };
    // cosmoscope::BrushStyle hard_brush{ 1.0,0.9 };

    // cosmoscope::Style soft_red{ red,soft_brush };
    // cosmoscope::Style soft_green{ green,soft_brush };
    // cosmoscope::Style soft_yellow{ yellow,soft_brush };

    // cosmoscope::FuncTree ftree;

    //// ftree.AddMonochromeFunc(-1, createCircle(200.0, 1.0), invisible);
    //// ftree.AddMonochromeFunc(0,  createCircle(150.0,1/150.0), invis ible);
    ////  ftree.AddMonochromeFunc(1, createCircle(60.0,-1.0),cosmoscope::Style{red,soft_brush});// &style1); 

    // Color blueChitchou{ 0.1,0.6,0.9,1.0 };
    // Color redChatchou{ 1.0,0.15,0.25,1.0 };

    // float zoom = 1;
    // float resolution = 90.0/128.0;
    // ftree.AddTimedMonochromeFunc(-1,timeMultiplier(resolution), createCircle(0.9 * zoom, 0.1344567), invisible);
    // ftree.AddMonochromeFunc(0,  createCircle(0.6 *zoom,1/5.73), invisible);
    // ftree.AddTimedPolychromeFunc(1, timeMultiplier(4), createCircle(0.3 * zoom, -1 / 5.0), gradient(15,redChatchou,blueChitchou));// Style{ white,soft_brush });
    // //ftree.AddMonochromeFunc(2, createCircle(0.3 * zoom, -1 / 32.0 * resolution), invisible);
    //// ftree.AddPolychromeFunc(2, createCircle(0.4 * zoom,8.752*128 * resolution), styleRedBlue);//cosmoscope::Style{ r,soft_brush });
    //
    // //ftree.AddMonochromeFunc(-1, createCircle(300,1/401.0), cosmoscope::Style{1.,0.,0.,1.,-1.});
    // //ftree.AddPolychromeFunc(0, createCircle(190,1/170.0), &style3);

    // int padx = 0;
    // int pady = 0;
    // int height = 1000;
    // int width = 1000;
    // SDL_Rect draw_area{ 0,0,width,height };
    // cosmoscopeSDL::CosmosDrawerSDL cosmos_drawer{draw_area};
    // cosmoscopeSDL::CosmovertorSDL cosmovertor {cosmoscopeSDL::Point{ width / 2.0 + padx, height / 2.0 + pady },
    //     sqrt(width * width + height * height) / 2.0, 100.0 };
    // cosmoscope::Scheduler scheduler{ std::move(ftree) };

    // WindowManager* cosmosWindow = new CosmosWindowSDL{"Cosmoscope",width,height,scheduler, cosmovertor, cosmos_drawer};
    // //WindowManager*  cosmosWindow = new CosmosWindowGL{"Cosmoscope",width,height,scheduler, cosmovertor, cosmos_drawer};
    // 
    // 
    // while (cosmosWindow->IsWindowOpen()) {
    //     cosmosWindow->ProcessEvents();
    //     cosmosWindow->UpdateFrame();
    // }
    // delete cosmosWindow;




    SDL_Quit();

    return 0;
}