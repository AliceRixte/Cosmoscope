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


Style style1(Time t) {
    return Style{ 0,(static_cast<int>(t) % 20000) / 20000.0,0.8,1.,0.2 };
}
Style style2(Time t) {
    return Style{ 0,1.0 - (static_cast<int>(t)%2000 <= 999 ? static_cast<int>(t) % 1000 : 1.0 - static_cast<int>(t) % 1000) / 1000.0,0.8,1., };
}

Style style3(Time t) {
    double coeff = std::fmod(t,42.5 * TWOPI)/ (42.5 * TWOPI);
    return Style{ 0.00, coeff ,0.5 + 0.5*coeff,1.,0. };
}
