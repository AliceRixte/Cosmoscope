/// @file CSC_CallbackTools.h
/// @brief Contains tools to create different useful callback functions
/// 
/// @author Alice Rixte
/// @date 05/04/2022
#pragma once

#include "CSC_CallbackFuncs.h"

namespace cosmoscope {
	PolarCallback createCircle(double radius, double rotation_speed);
	TimeCallback timeMultiplier(double time_factor);
}
