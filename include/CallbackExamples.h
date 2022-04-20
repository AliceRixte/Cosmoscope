/// @file CallbackExamples.h
/// @brief Contains a list of callbacks to be directly used to test the cosmoscope. Those functions shouldncosmosDrawer.m_renderer't be used except from a user perspective
/// 
/// @author Alice Rixte
/// @date 07/04/2022
#pragma once

#include "CSC_CallbackFuncs.h"
#include <cmath>

#define TWOPI 6.28318530718

using namespace cosmoscope;


Style styleFrozen(Time t) {
    return Style{
        Color{0,std::fmod(t,100.0) / 1000.0,0.8,1.0},
        BrushStyle{0.2,0.002}
    };
}

Style styleRedBlue(Time t) {
    double freq = 940;
    double mod = std::fmod(t+150.0, freq);
    double grad = 0;
    if (mod < freq / 2.0) {
        grad = 2.0 * mod / freq;
    }
    else {
        grad = 2.0 * (freq - mod) / freq;
    }
    return Style{
        Color{ grad,0.1,(1.0 - grad)* 0.8,1.0},
        BrushStyle{0.05,0.0}
    };
}

Style styleRedCyan(Time t) {
    double freq = 940.0;
    double mod = std::fmod(t + 150.0, freq);
    double grad = 0.0;
    if (mod < freq / 2.0) {
        grad = 2.0 * mod / freq;
    }
    else {
        grad = 2.0 * (freq - mod) / freq;
    }
    return Style{
        Color{ pow(grad,2.0),0.5*pow(1.0-grad,2.0),pow(1.0 - grad,2.0) * 0.9,1.0},
        BrushStyle{0.0,0.05}
    };
}

Style style2(Time t) {
    return Style{ 
        Color{0,1.0 - (static_cast<int>(t) % 2000 <= 999 ? static_cast<int>(t) % 1000 : 1.0 - static_cast<int>(t) % 1000) / 1000.0,0.8,1.},
        BrushStyle{0.2,0.5 }
     };
}

Style style3(Time t) {
    double coeff = std::fmod(t,42.5 * TWOPI)/ (42.5 * TWOPI);
    return Style{ 
        Color{0.00, coeff ,0.5 + 0.5 * coeff,1.},
        BrushStyle{0.5,0.0}
    };
}
