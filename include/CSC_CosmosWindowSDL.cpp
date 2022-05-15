#include "CSC_CosmosWindowSDL.h"

//#include "Brushes.h"
//#include <cmath>

namespace cosmoscopeSDL {

    CosmosWindowSDL::CosmosWindowSDL(const char* window_name, int width, int height,
        const cosmoscope::Scheduler& scheduler, const cosmoscopeSDL::CosmovertorSDL& cosmovertor,
        const cosmoscopeSDL::CosmosDrawerSDL& cosmos_drawer) :
        WindowManager(window_name,width, height),
        m_cosmosDrawer(cosmos_drawer),
       // m_isWindowOpen(true),
        t(0), 
        m_snapQueue(2),
        m_cosmovertor(cosmovertor),
        m_scheduler(scheduler),
        m_previousTick(0)
    {


        //main window  and renderer creation
        /*if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_RESIZABLE, &m_window, &m_renderer) < 0) {
            printf("Error in window/renderer creation: %s", SDL_GetError());
        }
        else {
            SDL_SetWindowTitle(m_window, "Cosmoscope");
            SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
        }*/
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



    

    /*CosmosWindowSDL::~CosmosWindowSDL() {
        SDL_DestroyWindow(m_window);
        SDL_DestroyRenderer(m_renderer);
    }*/

}