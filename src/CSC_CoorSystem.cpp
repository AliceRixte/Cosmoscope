#include "CSC_CoorSystem.h"


namespace cosmoscope {

	/*double degreesToRadian(double angle) {
		return angle * PI / 180.0;
	}

	double radianToDegrees(double angle) {
		return angle * 180.0 / PI;
	}*/

	CartesianPos CartesianPos::operator +(const CartesianPos& a)
	{
		return CartesianPos{ a.x + x, a.y + y };
	}

	PolarPos cartesianToPolar(const CartesianPos& pos) {
		return PolarPos{ sqrt(pos.x * pos.x + pos.y * pos.y), atan(pos.y / pos.x) };
	}

	CartesianPos polarToCartesian(const PolarPos& pos) {
		return CartesianPos{ pos.r * cos(pos.th * TWOPI),pos.r * sin(pos.th * TWOPI) };
	}

}
