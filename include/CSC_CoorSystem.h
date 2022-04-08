/// @file CSC_CoorSystem.h
/// @brief This header allows the Cosmoscope to use different types coordinate systems, for now cartesian and polar systems. 
/// 
/// **Angles** should be measured with *degrees* with 0° being the horizontal and using the trigonometric direction.\n\n
/// 
/// **Distances** are described using a *percentage* of the half of the window's diagonal.
/// As a consequence, for any square window, the position of the right top corner is ``(r,th) = (100,45)`` or, in cartesian style ``(x,y) = (sin(45)*100, cos(45)*100)`` ,
/// the top left corner is ``(r,th) = (100,135)``, the bottom left corner is ``(r,th) = (100,225) = (100,-135)`` 
/// and the bottom right corner is ``(r,th) = (100,315) = (100,-45)``.\n
/// As a consequence, ``x``, ``y``and ``r`` all evolve between ``-100`` and ``+100``. 
/// Even in that range, a lot of points are actually outside of the windowand won't be drawn, 
/// but this allows to make the Cosmoscope programs independent from the window in which they will be executed.
///
/// @author Alice Rixte
/// @date 06/04/2022
#pragma once

#include <cmath>

namespace cosmoscope {
	namespace {
		#define TWOPI 6.28318530718
	}

	/// @brief Converts degrees to radians
	/// @param angle An angle in degrees.
	/// @return The same angle in radians.
	//double degreesToRadian(double angle);

	/// @brief Converts radians to degrees
	/// @param angle An angle in radians.
	/// @return The same angle in radians.
	//double radianToDegrees(double angle);

	/// @brief Cartesuan position container using a cartesian (x,y) notation
	struct CartesianPos {
		/// The abscissa of the position
		double x; 
		/// The ordinate of the position
		double y; 
		/// @brief Adds two coordinates in a cartesian style.
		/// @param pos Position to be added to **this** 
		/// @return  The sum of the positions (x0+x1, y0+y1)
		CartesianPos operator +(const CartesianPos& pos); /// 
	};

	/// @brief Polar position container using a cartesian (r,th) notation
	/// 
	struct PolarPos {
		/// The radius coordinate of the polar position
		double r;
		/// The angle ``theta`` of the polar coordinate. ``1`` corresponds to a whole circular rotation of 360 degrees
		/// followinfg trigonometric diredction.
		/// Hence 2 are two complete rotations, and so on
		double th;
	};


	/// @brief Converts cartesian coordinates to polar coordinates.
	/// @param pos A position using cartesian coordinates.
	/// @return The same position using polar coordinates.
	PolarPos cartesianToPolar(const CartesianPos& cart_pos);

	/// @brief Converts polar coordinates to cartesian coordinates.
	/// @param pos A position using polar coordinates.
	/// @return The same position using cartesian coordinates.
	CartesianPos polarToCartesian(const PolarPos& pol_pos);
}

