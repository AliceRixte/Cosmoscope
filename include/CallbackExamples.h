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

Time faster(Time t) {
    return t + (t * t)/2000;
}


Time slower(Time t) {
    return 30 * t;
}

Style styleFrozen(Time t) {
    return Style{
        Color{0,std::fmod(t,100.0) / 1000.0,0.8,1.0},
        BrushStyle{0.2,0.002}
    };
}



Style styleRedBlue(Time t) {
    double freq = 15;
    double mod = std::fmod(t, freq);
    double grad = 0;
    if (mod < freq / 2.0) {
        grad = 2.0 * mod / freq;
    }
    else {
        grad = 2.0 * (freq - mod) / freq;
    }
   /* double freq2 = freq / 20;
    double mod2 = std::fmod(t, freq2);
    double grad2 = 0;
    if (mod < freq / 2.0) {
        grad2 = 2.0 * mod2 / freq2;
    }
    else {
        grad2 = 2.0 * (freq2 - mod2) / freq2;
    }*/
    return Style{
        Color{ grad, grad,1-grad,1.0},// Color{ grad,0.1,(1.0 - grad) * 0.8,1.0},// +0.5 * grad2},
        BrushStyle{0.5,0.0}
    };
}

Style styleBlackWhite(Time t) {
    double freq = 20000;
    double mod = std::fmod(t, freq);
    double grad = 0;
    if (mod < freq / 2.0) {
        grad = 2.0 * mod / freq;
    }
    else {
        grad = 2.0 * (freq - mod) / freq;
    }
    /* double freq2 = freq / 20;
     double mod2 = std::fmod(t, freq2);
     double grad2 = 0;
     if (mod < freq / 2.0) {
         grad2 = 2.0 * mod2 / freq2;
     }
     else {
         grad2 = 2.0 * (freq2 - mod2) / freq2;
     }*/
    return Style{
        Color{ 1.0 - grad*grad,1.0 - grad*grad ,1.0 - grad*grad,1.0 },// +0.5 * grad2
        BrushStyle{0.5,0.0}
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
        BrushStyle{1.0,0.0}
    };
}

Style style2(Time t) {
    return Style{ 
        Color{0,1.0 - (static_cast<int>(t) % 2000 <= 999 ? static_cast<int>(t) % 1000 : 1.0 - static_cast<int>(t) % 1000) / 1000.0,0.8,1.},
        BrushStyle{1.0,0.0 }
     };
}

Style style3(Time t) {
    double coeff = std::fmod(t,42.5 * TWOPI)/ (42.5 * TWOPI);
    return Style{ 
        Color{0.00, coeff ,0.5 + 0.5 * coeff,1.},
        BrushStyle{1.0,0.0}
    };
}
