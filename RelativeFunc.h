#pragma once

#include<functional>
#include "ColorFunc.h"

namespace Cosmoscope {

    class RelativeFunc {
    public:
        explicit RelativeFunc(const std::function<TraceData(Time)>& colorFunc, const int id_parent);
        explicit RelativeFunc(const std::function<Position(Time)>& paramFunc, const int id_parent, const Color& color);

        int GetParent();
        void SetParent(const int id_parent);
       
        TraceData Compute(const Time& t, const Position& origin);


        ~RelativeFunc();

    private:

        int m_parent;
        ColorFunc* m_colorFunc;

    };


}