#include "WindowManager.h"

#include "Brushes.h"
#include <cmath>


WindowManager::WindowManager(const char* window_name, int width, int height) : 
    m_window(NULL), m_renderer(NULL),
    m_isWindowOpen(true),
    m_altKeyDown(false), m_pause(false)
{
    //main window  and renderer creation
    if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_RESIZABLE, &m_window, &m_renderer) < 0) {
        printf("Error in window/renderer creation: %s", SDL_GetError());
    }
    else {
        SDL_SetWindowTitle(m_window, window_name);
        SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
    }
}


int WindowManager::ProcessEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_WINDOWEVENT:
            if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
                m_isWindowOpen = false; //window closing
            }
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_LALT) {
                m_altKeyDown = true;
            }
            else if (event.key.keysym.sym == SDLK_s && m_altKeyDown) {
                TakeScreenshot();
            }
            else if (event.key.keysym.sym == SDLK_SPACE) {
                m_pause = !m_pause;
            }
            break;
        case SDL_KEYUP:
            if (event.key.keysym.sym == SDLK_LALT) {
                m_altKeyDown = false;
            }
        }
       
    }
    return 0;
}

 

bool WindowManager::IsWindowOpen() const {
    return m_isWindowOpen;
}

int WindowManager::TakeScreenshot() const {
    int w, h = 0;
    SDL_GetWindowSize(m_window,&w,&h);
    SDL_Surface* sshot = SDL_CreateRGBSurface(0, w, h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    SDL_RenderReadPixels(m_renderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
    SDL_SavePNG(sshot, "screenshots/cosmoscope.png");
    SDL_FreeSurface(sshot);
    return 0;
}

WindowManager::~WindowManager() {
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
}



