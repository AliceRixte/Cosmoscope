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

	ColorFunc::ColorFunc(const Color& color) :
		m_colorCb([color](Time t) {return color; }) {
	}

	ColorFunc::ColorFunc(const ColorCallback& colorFunc) 
		: m_colorCb(colorFunc) {
	}

	Color ColorFunc::Compute(Time t) {
		return m_colorCb(t);
	}

	
}