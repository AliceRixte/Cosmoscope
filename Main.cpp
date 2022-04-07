#include <SDL.h>
#include <iostream>
#include "FuncTree.h"
#include <cmath>
#include "brushes.h"
#include "CosmosToSDL.h"




#include <filesystem>
#include <string>

namespace fs = std::filesystem;

using std::filesystem::current_path;

cosmoscope::Position line(cosmoscope::Time t) {
    return cosmoscope::Position{200,t};
}

cosmoscope::Position circle(cosmoscope::Time t) {
    return cosmoscope::Position{150,t/150.0};
}
cosmoscope::Position circle2(cosmoscope::Time t) {
    return cosmoscope::Position{ 60,t/60 };
}

cosmoscope::Position circle3(cosmoscope::Time t) {
    return cosmoscope::Position{ 10,t/2 };
}

cosmoscope::Position circle4(cosmoscope::Time t) {
    return cosmoscope::Position{ 60,-t };
}

cosmoscope::Style style1(cosmoscope::Time t) {
    return cosmoscope::Style{ 0,(static_cast<int>(t)%20000)/20000.0,0.8,1.,0.9};
}
cosmoscope::Style style2(cosmoscope::Time t) {
    return cosmoscope::Style{ 0,1.0-(static_cast<int>(t) % 20000) / 20000.0,0.8,1.,-1};
}

int main(int argc, char* argv[])
{
    //SDL initialisation
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    //main window creation
    SDL_Window* main_window; 
    SDL_Renderer* renderer;
    if (SDL_CreateWindowAndRenderer(900,900, SDL_WINDOW_RESIZABLE, &main_window, &renderer) < 0) {
        printf("Error in window/renderer creation: %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_SetWindowTitle(main_window, "Cosmoscope");

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

   
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

    SDL_Surface* img = SDL_LoadBMP("Screenshots/sample_640x426.bmp");
    if (!img)
    {
        printf("Erreur de chargement de l'image : %s", SDL_GetError());
        return -1;
    }
    SDL_Texture* monImage = SDL_CreateTextureFromSurface(renderer, img);
    
    SDL_FreeSurface(img);
    SDL_Rect position;
    position.x = 100;
    position.y = 200;
    SDL_QueryTexture(monImage, NULL, NULL, &position.w, &position.h);
    SDL_RenderCopy(renderer, monImage, NULL, &position);
    SDL_RenderPresent(renderer);


    SDL_Event event;
    bool app_running = true;

    cosmoscope::FuncTree ftree{cosmoscope::Position{450,450}};
    ftree.AddMonochromeFunc(-1,&line, cosmoscope::CoorSystem::Polar, cosmoscope::Style{ 1.,0.,0.,1.,-1.});
    ftree.AddPolychromeFunc(0, &circle,  cosmoscope::CoorSystem::Polar, &style2);
    ftree.AddMonochromeFunc(1, &circle4, cosmoscope::CoorSystem::Polar, cosmoscope::Style{ 0.9,0.1,0.2,1.,});
   // ftree.AddPolychromeFunc(1, &circle3, cosmoscope::CoorSystem::Polar, &style1);
    //ftree.AddPolychromeFunc(2, &circle3, cosmoscope::CoorSystem::Polar, &style2);

    double t = 0;
    std::vector<cosmoscope::Position> frame_pos;
    std::vector<cosmoscope::Style>    frame_style;


    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);    

    while (app_running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {  
            switch (event.type) {
                case SDL_WINDOWEVENT: 
                    if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
                        app_running = false; //window closing
                    }
                break;
            }
        }


        frame_pos = ftree.ComputeAllPos(t);
        frame_style = ftree.ComputeAllStyle(t);


        for (int i = 0; i < frame_pos.size(); i++) {
            cosmoscope::Position pos = frame_pos[i];
            cosmoscope::Style style = frame_style[i];
            if (style.h >= 0.0) {
                draw_SDL::DrawEllipse(renderer, SDL_Rect{ static_cast<int>(pos.x) - 1,static_cast<int>(pos.y) - 1,3,3},
                    cosmoscope_SDL::styleToColor(style), style.h);
            }
            
        }
        
        
        SDL_RenderPresent(renderer);
        SDL_Delay(1);
        t++;

    }


    SDL_DestroyWindow(main_window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();
    return 0;
}