#include "CallbackFuncs.h"

namespace cosmoscope {

	ParamFunc::ParamFunc(const ParamCallback& paramFunc, CoorSystem coor)
		: m_paramCb(paramFunc), m_coor(coor) {
	}

	Position ParamFunc::Compute(Time t) {
		switch (m_coor) {
		case CoorSystem::Cartesian:
			return m_paramCb(t);
		case CoorSystem::Polar:
			Position polar_res = m_paramCb(t);
			return Position{ polar_res.x * sin(polar_res.y), polar_res.x * cos(polar_res.y) };
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