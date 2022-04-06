#pragma once

#include<functional>
#include "CallbackFuncs.h"

namespace cosmoscope {

    class RelativeFunc {
    public:
        explicit RelativeFunc(int id_parent, const ParamCallback& param_cb,
                const CoorSystem& coor = CoorSystem::Cartesian, 
                const Color& color = Color {255,255,255,255});


        int GetParent();
        void SetParent(int id_parent);
       
        Position ComputePos(const Time& t, const Position& origin);

    private:

        int m_parent;
        ParamFunc m_paramFunc;
        ColorFunc m_colorFunc;

    };


}