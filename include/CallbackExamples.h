/// @file CallbackExamples.h
/// @brief Contains a list of callbacks to be directly used to test the cosmoscope. Those functions shouldn't be used except from a user perspective
/// 
/// @author Alice Rixte
/// @date 07/04/2022
#pragma once

#include "CSC_CallbackFuncs.h"

#define TWOPI 6.28318530718

namespace cosmoscope {
    Position line(Time t) {
        return Position{ 200,t/TWOPI};
    }

    Position circle(Time t) {
        return Position{ 150,t / 150.0 /TWOPI };
    }
    Position circle2(Time t) {
        return Position{ 60,t / 60 /TWOPI };
    }

    Position circle3(Time t) {
        return Position{ 10,t / 2/TWOPI};
    }

    Position circle4(Time t) {
        return Position{ 60,-t/TWOPI};
    }

    Style style1(Time t) {
        return Style{ 0,(static_cast<int>(t) % 20000) / 20000.0,0.8,1.,0.9 };
    }
    Style style2(Time t) {
        return Style{ 0,1.0 - (static_cast<int>(t) % 20000) / 20000.0,0.8,1.,-1 };
    }

}
