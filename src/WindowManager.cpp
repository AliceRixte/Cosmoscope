#include "WindowManager.h"

#include "Brushes.h"
#include <cmath>


WindowManager::WindowManager(const char* window_name, int width, int height,
    const cosmoscopeSDL::CosmosDrawerSDL& cosmos_drawer, const cosmoscopeSDL::CosmovertorSDL& cosmovertor) : 
    m_cosmosDrawer(cosmos_drawer),
    m_isWindowOpen(true),
    m_window(NULL), m_renderer(NULL), t(0), m_altKeyDown(false), m_pause(false),
    m_snapQueue(2),
    m_cosmovertor(cosmovertor)
{

    //SDL initialisation
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
    }
    //main window  and renderer creation
    else if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_RESIZABLE, &m_window, &m_renderer) < 0) {
        printf("Error in window/renderer creation: %s", SDL_GetError());
    }
    else {
        SDL_SetWindowTitle(m_window, "Cosmoscope");
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

int WindowManager::UpdateFrame() {
    // if the cosmoscope is not on pause
    if (!m_pause) {
        m_cosmovertor.ComputeAndConvert(t, &m_snapQueue);
        m_cosmosDrawer.DrawSnap(m_snapQueue, m_renderer);
        SDL_RenderPresent(m_renderer);
        t++;
    }
    
    SDL_Delay(1);
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
    SDL_Quit();
}



