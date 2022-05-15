#include "CSC_CallbackTools.h"

namespace cosmoscope{

	PolarCallback createCircle(double radius, double rotation_speed) {
		return [radius, rotation_speed](Time t) {return PolarPos{ radius ,t * rotation_speed }; };
	}

	TimeCallback timeMultiplier(double time_factor) {
		return [time_factor](Time t) {return t * time_factor; };
	} 
}