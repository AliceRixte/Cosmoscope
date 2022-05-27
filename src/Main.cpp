
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

const GLint WIDTH = 1700, HEIGHT = 600;

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

    //
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    //SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    //SDL_Window* glwin = SDL_CreateWindow("CosmoscopeGL", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);

    //SDL_GLContext context = SDL_GL_CreateContext(glwin);

    //const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
    //const GLubyte* version = glGetString(GL_VERSION); // version as a string
    //printf("Renderer: %s\n", renderer);
    //printf("OpenGL version supported %s\n", version);

    //glewExperimental = GL_TRUE;

    //if (GLEW_OK != glewInit()) {
    //    std::cout << "Error in glew initialisation"<< std::endl;
    //    return EXIT_FAILURE;
    //}
    //glViewport(0, 0, WIDTH, HEIGHT);

    //unsigned int VBO;

    //

    //float triangle[] = {
    //-0.5f, -0.5f, 0.0f,
    // 0.5f, -0.5f, 0.0f,
    // 0.0f,  0.5f, 0.0f
    //};
    //

    //glGenBuffers(1, &VBO);
    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

    //const char* vertexShaderSource = 
    //    "#version 400\n"
    //    "in vec3 vp;"
    //    "void main() {"
    //    "  gl_Position = vec4(vp, 1.0);"
    //    "}"; 

    //unsigned int vertexShader;
    //vertexShader = glCreateShader(GL_VERTEX_SHADER);
    //glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);

    //int success;
    //char infoLog[512];
    //
    //glCompileShader(vertexShader);
    //glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    //if (!success) {
    //    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    //    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    //}

    //const char* fragmentShaderSource =
    //    "#version 330 core\n"
    //    "out vec4 FragColor;"
    //    "void main()"
    //    "    {"
    //    "FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);"
    //    "}\0";

    //unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    //glShaderSource(fragment_shader, 1, &fragmentShaderSource, NULL);

    //glCompileShader(fragment_shader);
    //glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    //if (!success) {
    //    glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
    //    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    //}

    //unsigned int shaderProgram = glCreateProgram();

    //glAttachShader(shaderProgram, vertexShader);
    //glAttachShader(shaderProgram, fragment_shader);
    //glLinkProgram(shaderProgram);

    //glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    //if (!success) {
    //    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    //    std::cout << "ERROR::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
    //}
    //
    ////glUseProgram(shaderProgram);
    //glDeleteShader(vertexShader);
    //glDeleteShader(fragment_shader);

    //unsigned int VAO;
    //glGenVertexArrays(1, &VAO);
    //glBindVertexArray(VAO);

    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    //glEnableVertexAttribArray(0);

    //SDL_Event event;
    //bool isWindowOpen = true;
    //while (isWindowOpen) {
    //    while (SDL_PollEvent(&event)) {
    //        switch (event.type) {
    //        case SDL_WINDOWEVENT:
    //            if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
    //                isWindowOpen = false; //window closing
    //            }
    //        }
    //    }


    //    glUseProgram(shaderProgram);
    //    glBindVertexArray(VAO);
    //    glDrawArrays(GL_POINTS, 0, 3);

    //  /*  glClearColor(1.0, 0.0, 0.0, 0.0f);
    //    glClear(GL_COLOR_BUFFER_BIT);
    //    glClearColor(1.0, 1.0, 0.0, 0.0f);
    //    glClear(GL_COLOR_BUFFER_BIT);*/

    //    SDL_GL_SwapWindow(glwin);
    //}

    //SDL_GL_DeleteContext(context);
    

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