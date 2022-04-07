#include "CSC_CallbackFuncs.h"

namespace cosmoscope {

	ParamFunc::ParamFunc(const CartesianCallback& cartesian_cb)
		: m_paramCb(cartesian_cb) {
	}

	ParamFunc::ParamFunc(const PolarCallback& polar_cb)
		: m_paramCb(polar_cb) {
	}


	CartesianPos ParamFunc::Compute(Time t) {
		if (std::holds_alternative<CartesianCallback>(m_paramCb)) {
			return std::get<CartesianCallback>(m_paramCb)(t);
		}
		else{
			return polarToCartesian(std::get<PolarCallback>(m_paramCb)(t));
		}
	}

	StyleFunc::StyleFunc(const Style& style) :
		m_styleCb([style](Time t) {return style; }) {
	}

	StyleFunc::StyleFunc(const StyleCallback& styleFunc) 
		: m_styleCb(styleFunc) {
	}

	Style StyleFunc::Compute(Time t) {
		return m_styleCb(t);
	}

	TimeFunc::TimeFunc() :
		m_timeCb([](Time t) {return t;}) {
	}

	TimeFunc::TimeFunc(const TimeCallback& timeFunc)
		: m_timeCb(timeFunc) {
	}

	Time TimeFunc::Compute(Time t) {
		return m_timeCb(t);
	}

	
}