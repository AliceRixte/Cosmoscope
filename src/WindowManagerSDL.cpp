#include "WindowManagerSDL.h"

#include <iostream>
#include "savepng.h"

WindowManagerSDL::WindowManagerSDL(const char* window_name, int width, int height) :
    m_window(NULL), m_renderer(NULL)
{
    //main window  and renderer creation
    if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_RESIZABLE, &m_window, &m_renderer) < 0) {
        std::cerr << "Error in window/renderer creation: " << SDL_GetError() << std::endl;
    }
    else {
        SDL_SetWindowTitle(m_window, window_name);
        SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
        //SDL_SetRenderDrawColor(m_renderer, 255, 255,255 , 255);
        SDL_RenderClear(m_renderer);
    }
}

int WindowManagerSDL::TakeScreenshot() const {
    int w, h = 0;
    SDL_GetWindowSize(m_window, &w, &h);
    SDL_Surface* sshot = SDL_CreateRGBSurface(0, w, h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    SDL_RenderReadPixels(m_renderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
    SDL_SavePNG(sshot, "screenshots/cosmoscope.png");
    SDL_FreeSurface(sshot);
    return 0;
}

WindowManagerSDL::~WindowManagerSDL() {
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
}



