#include "CSC_CosmosDrawerSDL.h"

#include "Brushes.h"
#include <cmath>

namespace cosmoscopeSDL {
    CosmosDrawerSDL::CosmosDrawerSDL() {
    }


    void CosmosDrawerSDL::DrawSnap(const SnapQueueSDL& snap_queue, SDL_Renderer* renderer) const {

        for (int i = 0; i < snap_queue.GetSnap(0).size(); i++) {
            SDL_Point pos = snap_queue.GetSnap(0)[i].p;
            StyleSDL style = snap_queue.GetSnap(0)[i].s;

            if (style.brush.h >= 0.0) {

                draw_SDL::DrawEllipse(renderer,
                    SDL_Rect{ static_cast<int>(pos.x - style.brush.radius / 2 + 1),static_cast<int>(pos.y - style.brush.radius / 2 + 1),
                        static_cast<int>(style.brush.radius + 1), static_cast<int>(style.brush.radius + 1) },
                    style.color, 
                    style.brush.h, 15.0);
            }
        }
    }

}




