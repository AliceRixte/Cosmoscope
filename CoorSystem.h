#pragma once

#include <cmath>

namespace cosmoscope {
	double degreesToRadian(double angle);
	double radianToDegrees(double angle);

	struct Position {
		double x, y;
		Position operator +(const Position& a);
	};

	enum class CoorSystem { Cartesian, Polar };

	Position cartesianToPolar(Position pos);
	Position polarToCartesian(Position pos);
}
