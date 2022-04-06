/// @file CallbackFuncs.h
/// @brief Contains wrappers to use callback functions that are necessary for relative functions.
/// 
/// There are 3 types of callback functions : 
/// * Parametric callbacks : they are parametric functions, which associate to any time **t** a 2D position.
/// * Color callbacks : thay associate to any time **t** a color. This is not passed on to the children of the relative function.
/// * Time callbacks : they associate to any time **t** a new time **tt**. This allows to distort time depending on the relative function. 
/// This is passed on to the children of the relative function which uses this callback : it can be composed.
/// @author Alice Rixte
/// @date 05/04/2022
#pragma once

#include <functional>
#include <cstdint>

#include "CoorSystem.h"

namespace cosmoscope {

/// @brief A structure used to store a color. All values range between 0.0 and 1.0
	struct Color {
		/// @brief red : ranges between 0.0 and 1.0
		double r;
		/// @brief green: ranges between 0.0 and 1.0
		double g;
		/// @brief blue : ranges between 0.0 and 1.0
		double b; 
		/// @brief alpha (transparency) : ranges between 0.0 and 1.0
		double a;
	};

/// @brief An alias for time
using Time = double;
/// @brief An alias for parametric callbacks
using ParamCallback = std::function<Position(Time)>;
/// @brief An alias for color callbacks
using ColorCallback = std::function<Color(Time)>;

/// @brief A wrapper class for parametric callbacks
/// This allows to deal with coordinate system changes in particular.
class ParamFunc {
public:
	/// @brief The main constructor, asking for the parametric callback and the coordonate system type
	/// @param param_func The parametric callback tied to the class
	/// @param coor The coordonate system, by default cartesian
	explicit ParamFunc(const ParamCallback& param_cb, CoorSystem coor = CoorSystem::Cartesian);

	/// @brief Computes the parametric function at a time **t**
	/// @param t The current time
	/// @return The current relative position
	Position Compute(Time t);
private:
	ParamCallback m_paramCb;
	CoorSystem m_coor;
};

/// @brief A wraper class fo color callbacks
/// This allows to deal with the possibility to use more arguments tto determine the color
class ColorFunc {
public:
	/// @brief This constructor creates a constant (over time) color function using **color**
	/// @param color The unique color of the color function
	explicit ColorFunc(const Color& color);
	/// @brief Creates a color function out of a color callback
	/// @param color_cb The color callback tied to the class
	explicit ColorFunc(const ColorCallback& color_cb);

	/// @brief Computes the color function at a time **t**
	/// @param t The current time
	/// @return The current color
	Color Compute(Time t);
private:
	ColorCallback m_colorCb;
};
}