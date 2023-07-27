#include "WindowManager.h"

WindowManager::WindowManager() : 
    m_isWindowOpen(true),
    m_altKeyDown(false), m_pause(false)
{

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


