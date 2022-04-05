#include <SDL.h>
#include <iostream>
#include "FuncTree.h"
#include <cmath>

Cosmoscope::Position line(Cosmoscope::Time t) {
    return Cosmoscope::Position{ 100,t };
}

Cosmoscope::Position circle(Cosmoscope::Time t) {
    return Cosmoscope::Position{100*std::sin(t),100*std::cos(t)};
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

 

    SDL_Event event;
    bool app_running = true;

    Cosmoscope::FuncTree ftree;
    ftree.AddParamCallback(&line);
    ftree.AddParamCallback(&circle);

    double t = 0;
    std::vector<Cosmoscope::TraceData> frame;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, 0,0,100,100);

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


        frame = ftree.ComputeFuncs(t, Cosmoscope::Position{ 300,300 });

        for (auto td : frame) {
            SDL_SetRenderDrawColor(renderer, td.c.r, td.c.g, td.c.b , td.c.a);
            SDL_RenderDrawPoint(renderer, td.pos.x, td.pos.y);
        }
        
        
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
        t++;

    }


    SDL_DestroyWindow(main_window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();
    return 0;
}