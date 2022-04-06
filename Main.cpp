#include <SDL.h>
#include <iostream>
#include "FuncTree.h"
#include <cmath>
#include "brushes.h"

cosmoscope::Position line(cosmoscope::Time t) {
    return cosmoscope::Position{t,t};
}

cosmoscope::Position circle(cosmoscope::Time t) {
    return cosmoscope::Position{100,t/10.0};
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
    if (SDL_CreateWindowAndRenderer(600, 600, SDL_WINDOW_RESIZABLE, &main_window, &renderer) < 0) {
        printf("Error in window/renderer creation: %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_SetWindowTitle(main_window, "Cosmoscope");

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

 

    SDL_Event event;
    bool app_running = true;

    cosmoscope::FuncTree ftree{cosmoscope::Position{0,0}};
    ftree.AddParamCallback(-1,&line);
    ftree.AddParamCallback(0,&circle,cosmoscope::CoorSystem::Polar);

    double t = 0;
    std::vector<cosmoscope::Position> frame;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_SetRenderDrawColor(renderer,0, 0, 255, 0);

    //DrawEllipse(renderer, SDL_Rect{ 100,100,200,400 }, SDL_Color{ 255,0,0,255 },0.9);
    

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


        frame = ftree.ComputeAllPos(t);

        for (auto pos : frame) {

            DrawEllipse(renderer, SDL_Rect{ static_cast<int>(pos.x) - 2,static_cast<int>(pos.y) - 2,5,5}, SDL_Color{ 255,0,0,255 }, 0.0);
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