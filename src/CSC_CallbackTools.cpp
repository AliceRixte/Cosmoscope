#include "CSC_CallbackTools.h"

namespace cosmoscope{

	PolarCallback createCircle(double radius, double rotation_speed) {
		return [radius, rotation_speed](Time t) {return PolarPos{ radius ,t * rotation_speed }; };
	}
}