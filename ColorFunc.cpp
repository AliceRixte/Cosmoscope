#include "ColorFunc.h"

namespace Cosmoscope {

	ColorCallback::ColorCallback(std::function<TraceData(Time)> colorFunc) 
		: m_colorFunc(colorFunc) {
	}

	TraceData ColorCallback::Compute(Time t) {
		return this->m_colorFunc(t);
	}

	ParamCallback::ParamCallback(std::function<Position(Time)> paramFunc, Color color)
		: m_paramFunc(paramFunc), m_color(color) {
	}

	TraceData ParamCallback::Compute(Time t) {
		return TraceData{ this->m_paramFunc(t),this->m_color };
	}
}