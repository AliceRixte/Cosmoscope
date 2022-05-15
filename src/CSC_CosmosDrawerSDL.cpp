#include "CSC_CosmosDrawerSDL.h"

#include "Brushes.h"
#include <cmath>

namespace cosmoscopeSDL {
    CosmosDrawerSDL::CosmosDrawerSDL(const SDL_Rect& draw_area) : 
        m_minX(draw_area.x),m_maxX(draw_area.x + draw_area.w),
        m_minY(draw_area.y),m_maxY(draw_area.y + draw_area.h)
    {
    }

   

    void CosmosDrawerSDL::DrawSnap(const SnapQueueSDL& snap_queue, SDL_Renderer* renderer) const {

        for (int i = 0; i < snap_queue.GetSnap(0).size(); i++) {
            Point pos = snap_queue.GetSnap(0)[i].p;
            StyleSDL style = snap_queue.GetSnap(0)[i].s;

            if (style.brush.h >= 0.0 
                && pos.get<0>() >= m_minX && pos.get<0>() < m_maxX 
                && pos.get<1>() >= m_minY && pos.get<1>() < m_maxY) {

                //draw_SDL::DrawEllipse(renderer, pos, style.brush.radius, style.brush.radius, style.color, style.brush.h, 15.0);
                draw_SDL::DrawCircle(renderer, pos, style.brush.radius/4, style.color, style.brush.h, 20.0);
            }
        }
    }

}




