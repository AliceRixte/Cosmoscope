/// @file CallbackFuncs.h
/// @brief Contains wrappers to use callback functions that are necessary for relative functions.
/// 
/// There are 3 types of callback functions : 
/// * Parametric callbacks : they are parametric functions, which associate to any time **t** a 2D position.
/// * Style callbacks : thay associate to any time **t** a style. This is not passed on to the children of the relative function.
/// * Time callbacks : they associate to any time **t** a new time **tt**. This allows to distort time depending on the relative function. 
/// This is passed on to the children of the relative function which uses this callback : it can be composed.
/// @author Alice Rixte
/// @date 05/04/2022
#pragma once

#include <functional>
#include <cstdint>

#include "CoorSystem.h"

namespace cosmoscope {

/// @brief A structure used to store a drawing style (color, transparency and hardness). All values range from 0.0 to 1.0
	struct Style {
		/// @brief red : ranges from 0.0 to 1.0
		double r;
		/// @brief green: ranges from 0.0 to 1.0
		double g;
		/// @brief blue : ranges from 0.0 to 1.0
		double b; 
		/// @brief alpha (transparency) : ranges from 0.0 to 1.0
		double a;
		/// @brief hardness : how hard the brush is applied. Ranges from 0.0 to 1.0. When set to -1.0, the function is not drawn.
		double h;
	};

/// @brief An alias for time
using Time = double;
/// @brief An alias for parametric callbacks
using ParamCallback = std::function<Position(Time)>;
/// @brief An alias for style callbacks
using StyleCallback = std::function<Style(Time)>;

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

/// @brief A wraper class for style callbacks
/// This allows to deal with the possibility to use more arguments tto determine the style
class StyleFunc {
public:
	/// @brief This constructor creates a constant (over time) style function using **style**
	/// @param style The unique style of the style function
	explicit StyleFunc(const Style& style);
	/// @brief Creates a style function out of a style callback
	/// @param style_cb The style callback tied to the class
	explicit StyleFunc(const StyleCallback& style_cb);

	/// @brief Computes the style function at a time **t**
	/// @param t The current time
	/// @return The current style
	Style Compute(Time t);
private:
	StyleCallback m_styleCb;
};
}