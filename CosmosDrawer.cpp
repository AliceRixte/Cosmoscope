#include "CosmosDrawer.h"

#include "Brushes.h"
#include "CosmosToSDL.h"

namespace cosmoscope_SDL {

    CosmosDrawer::CosmosDrawer(const char* window_name, int width, int height, const cosmoscope::FuncTree* func_tree) : 
        m_funcTree(func_tree),
        m_isAppRunning(true) {

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


    int CosmosDrawer::ProcessEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
                    m_isAppRunning = false; //window closing
                }
                break;
            }
        }
        return 0;
    }

    int CosmosDrawer::UpdateFrame() {
        frame_pos = m_funcTree->ComputeAllPos(t);
        frame_style = m_funcTree->ComputeAllStyle(t);


        for (int i = 0; i < frame_pos.size(); i++) {
            cosmoscope::Position pos = frame_pos[i];
            cosmoscope::Style style = frame_style[i];
            if (style.h >= 0.0) {
                draw_SDL::DrawEllipse(m_renderer, SDL_Rect{ static_cast<int>(pos.x) - 1,static_cast<int>(pos.y) - 1,3,3 },
                    cosmoscope_SDL::styleToColor(style), style.h);
            }

        }


        SDL_RenderPresent(m_renderer);
        SDL_Delay(1);
        t++;

        return 0;
    }

    CosmosDrawer::~CosmosDrawer() {
        SDL_DestroyWindow(m_window);
        SDL_DestroyRenderer(m_renderer);

        SDL_Quit();
    }


}


