/// @file CallbackExamples.h
/// @brief Contains a list of callbacks to be directly used to test the cosmoscope. Those functions shouldncosmosDrawer.m_renderer't be used except from a user perspective
/// 
/// @author Alice Rixte
/// @date 07/04/2022
#pragma once

#include "CSC_CallbackFuncs.h"

#define TWOPI 6.28318530718

using namespace cosmoscope;

PolarPos line(Time t) {
    return PolarPos{ 200,t/TWOPI};
}

PolarPos circle(Time t) {
    return PolarPos{ 150,t / 150.0 /TWOPI };
}
PolarPos circle2(Time t) {
    return PolarPos{ 60,t / 60 /TWOPI };
}

PolarPos circle3(Time t) {
    return PolarPos{ 10,t / 2/TWOPI};
}

PolarPos circle4(Time t) {
    return PolarPos{ 60,-t/TWOPI};
}

Style style1(Time t) {
    return Style{ 0,(static_cast<int>(t) % 20000) / 20000.0,0.8,1.,0.9 };
}
Style style2(Time t) {
    return Style{ 0,1.0 - (static_cast<int>(t) % 20000) / 20000.0,0.8,1.,-1 };
}

