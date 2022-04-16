#include "CSC_CosmosDrawerSDL.h"

#include "Brushes.h"
#include <cmath>

namespace cosmoscopeSDL {
    CosmosDrawerSDL::CosmosDrawerSDL(const cosmoscope::FuncTree* func_tree, double length_scale, floatpix::Position origin) :
        m_funcTree(func_tree), m_snapQueue(2),
        m_cosmovertor(func_tree, length_scale, origin) {

    }


    void CosmosDrawerSDL::DrawSnap(double time, SDL_Renderer* renderer) {

        // m_funcTree->ComputeAll(t,&m_snapQueue);
        m_cosmovertor.ComputeAndConvert(time, &m_snapQueue);

        for (int i = 0; i < m_funcTree->Size(); i++) {
            SDL_Point pos = m_snapQueue.GetSnap(0)[i].p;
            StyleSDL style = m_snapQueue.GetSnap(0)[i].s;

            if (style.brush.h >= 0.0) {
                int diam_brush = style.brush.radius;
                draw_SDL::DrawEllipse(renderer,
                    SDL_Rect{ static_cast<int>(pos.x) - diam_brush / 2 + 1,static_cast<int>(pos.y) - diam_brush / 2 + 1,diam_brush + 1,diam_brush + 1 },
                    style.color, style.brush.h, 15.0);
            }
        }
    }
}




