#include "CoorSystem.h"

#define PI 3.1415965359

namespace cosmoscope {

	double degreesToRadian(double angle) {
		return angle * PI / 180.0;
	}

	double radianToDegrees(double angle) {
		return angle * 180.0 / PI;
	}

	Position Position::operator +(const Position& a)
	{
		return Position{ a.x + x, a.y + y };
	}

	Position cartesianToPolar(const Position& pos) {
		return Position{ sqrt(pos.x * pos.x + pos.y * pos.y), atan(pos.y / pos.x) };
	}

	Position polarToCartesian(const Position& pos) {
		return Position{ pos.x * sin(degreesToRadian(pos.y)),pos.x * cos(degreesToRadian(pos.y)) };
	}

}
