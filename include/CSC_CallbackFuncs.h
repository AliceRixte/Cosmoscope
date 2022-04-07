/// @file CSC_CallbackFuncs.h
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
#include <variant>

#include "CSC_CoorSystem.h"
#include "CSC_Time.h"
#include "CSC_Style.h"


namespace cosmoscope {


/// @brief An alias for parametric cartesian callbacks
using CartesianCallback = std::function<CartesianPos(Time)>;
/// @brief An alias for parametric polar callbacks
using PolarCallback = std::function<PolarPos(Time)>;
/// @brief An alias for style callbacks
using StyleCallback = std::function<Style(Time)>;
/// @brief An alias for time callbacks
using TimeCallback = std::function<Time(Time)>;

/// @brief A wrapper class for parametric callbacks
/// This allows to deal with coordinate system changes in particular.
class ParamFunc {
public:
	/// @brief The main constructor, asking for the parametric callback and the coordonate system type
	/// @param param_func The parametric callback tied to the class
	explicit ParamFunc(const CartesianCallback& param_cb);

	/// @brief The main constructor, asking for the parametric callback and the coordonate system type
	/// @param param_func The parametric callback tied to the class
	explicit ParamFunc(const PolarCallback& param_cb);

	/// @brief Computes the parametric function at a time **t**
	/// @param t The current time
	/// @return The current relative position
	CartesianPos Compute(Time t);
private:
	std::variant<CartesianCallback, PolarCallback> m_paramCb;
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


/// @brief A wraper class for time callbacks
/// This allows to deal with all the time distortion part
	class TimeFunc {
	public:
		/// @brief This constructor creates an identity function : time is not modified
		explicit TimeFunc();
		/// @brief Creates a time function out of a time callback
		/// @param time_cb The time callback tied to the class
		explicit TimeFunc(const TimeCallback& time_cb);

		/// @brief Computes the time function at a time **t**
		/// @param t The current time
		/// @return The new time ``tt``
		Time Compute(Time t);
	private:
		TimeCallback m_timeCb;
};

}