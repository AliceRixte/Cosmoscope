#include "CSC_CosmosWindowSDL.h"

//#include "Brushes.h"
//#include <cmath>

namespace cosmoscopeSDL {

    CosmosWindowSDL::CosmosWindowSDL(const char* window_name, int width, int height,
        const cosmoscope::Scheduler& scheduler, const cosmoscopeSDL::CosmovertorSDL& cosmovertor,
        const cosmoscopeSDL::CosmosDrawerSDL& cosmos_drawer) :
        WindowManagerSDL(window_name,width, height),
        m_cosmosDrawer(cosmos_drawer),
        t(0), 
        m_snapQueue(2),
        m_cosmovertor(cosmovertor),
        m_scheduler(scheduler),
        m_previousTick(0),
        m_firstTick(SDL_GetTicks())
    {

    }




    int CosmosWindowSDL::UpdateFrame() {

        // if the cosmoscope is not on pause
        if (!m_pause) {

            int nb_snap = 10;//0.2
            m_scheduler.ComputeSnaps(t, nb_snap); //6 sec
            std::vector<cosmoscope::TreeSnap> snaps = m_scheduler.ReadSnaps(); //0.3sec

            for (int i = 0; i < nb_snap; i++) {//0.2 sec
                m_snapQueue.WriteSnap(m_cosmovertor.TreeSnapToSDL(snaps[i])); //13sec
                m_cosmosDrawer.DrawSnap(m_snapQueue, m_renderer);//80sec
            }
            
            if (fmod(t, 10000) < 0.5) { //0.5
                SDL_RenderPresent(m_renderer);
                std::cout << "Total snaps : " << t << "    Total time : " << (SDL_GetTicks() - m_firstTick) / 1000 << "secs"  <<
                    "    SnapPS : " << static_cast<int>(10000.0*1000.0 / (SDL_GetTicks() - m_previousTick)) <<std::endl;

                m_previousTick = SDL_GetTicks();                
            }
        }


        //SDL_Delay(0);
        return 0;
    }
}