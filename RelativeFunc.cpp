#include "RelativeFunc.h"

namespace Cosmoscope {

	RelativeFunc::RelativeFunc(const std::function<TraceData(Time)>& colorFunc, const int id_parent) 
		: m_parent(id_parent) {
		m_colorFunc = new ColorCallback{ colorFunc };
	}

	RelativeFunc::RelativeFunc(const std::function<Position(Time)>& paramFunc, const int id_parent, const Color& color)
		: m_parent(id_parent) {
		m_colorFunc = new ParamCallback{ paramFunc, color };

	}

	TraceData RelativeFunc::Compute(const Time& t, const Position& origin) {
		TraceData res =m_colorFunc->Compute(t);
		return TraceData{ res.pos + origin , res.c };
	}


	int RelativeFunc::GetParent() {
		return this->m_parent;
	}

	void RelativeFunc::SetParent(const int new_parent) {
		this->m_parent = new_parent;
	}

	RelativeFunc::~RelativeFunc() {
		delete this->m_colorFunc;
	}
}
