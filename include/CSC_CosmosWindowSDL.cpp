#include "CSC_CosmosWindowSDL.h"

//#include "Brushes.h"
//#include <cmath>

namespace cosmoscopeSDL {

    CosmosWindowSDL::CosmosWindowSDL(const char* window_name, int width, int height,
        const cosmoscopeSDL::CosmosDrawerSDL& cosmos_drawer, const cosmoscopeSDL::CosmovertorSDL& cosmovertor,
        const cosmoscope::Scheduler& scheduler) :
        m_cosmosDrawer(cosmos_drawer),
        m_isWindowOpen(true),
        m_window(NULL), m_renderer(NULL), t(0), m_altKeyDown(false), m_pause(false),
        m_snapQueue(2),
        m_cosmovertor(cosmovertor),
        m_scheduler(scheduler),
        m_previousTick(0)
    {


        //main window  and renderer creation
        if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_RESIZABLE, &m_window, &m_renderer) < 0) {
            printf("Error in window/renderer creation: %s", SDL_GetError());
        }
        else {
            SDL_SetWindowTitle(m_window, "Cosmoscope");
            SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
        }
    }


    int CosmosWindowSDL::ProcessEvents() {
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

    int CosmosWindowSDL::UpdateFrame() {

        // if the cosmoscope is not on pause
        if (!m_pause) {
            m_scheduler.ComputeSnaps(t, 1);
            m_snapQueue.WriteSnap(m_cosmovertor.TreeSnapToSDL(m_scheduler.ReadSnaps()[0]));
            m_cosmosDrawer.DrawSnap(m_snapQueue, m_renderer);
            SDL_RenderPresent(m_renderer);
            t++;


            if (fmod(t, 100) < 0.5) {
                std::cout << "Total snaps" << t << "   SnapPS : " << 100000.0 / (SDL_GetTicks() - m_previousTick) << std::endl;

                m_previousTick = SDL_GetTicks();
            }
        }


        SDL_Delay(0);
        return 0;
    }


    bool CosmosWindowSDL::IsWindowOpen() const {
        return m_isWindowOpen;
    }

    int CosmosWindowSDL::TakeScreenshot() const {
        int w, h = 0;
        SDL_GetWindowSize(m_window, &w, &h);
        SDL_Surface* sshot = SDL_CreateRGBSurface(0, w, h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
        SDL_RenderReadPixels(m_renderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
        SDL_SavePNG(sshot, "screenshots/cosmoscope.png");
        SDL_FreeSurface(sshot);
        return 0;
    }

    CosmosWindowSDL::~CosmosWindowSDL() {
        SDL_DestroyWindow(m_window);
        SDL_DestroyRenderer(m_renderer);
    }

}