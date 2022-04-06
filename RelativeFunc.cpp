#include "RelativeFunc.h"

namespace cosmoscope {

	RelativeFunc::RelativeFunc(int id_parent, const ParamCallback& param_cb, const CoorSystem& coor, const Style& style) :
		m_parent(id_parent),
		m_paramFunc(ParamFunc{ param_cb, coor }),
		m_styleFunc(style) {
	}


	Position RelativeFunc::ComputePos(Time t, const Position& origin) {
		return m_paramFunc.Compute(t) + origin;
	}

	Style RelativeFunc::ComputeStyle(Time t) {
		return m_styleFunc.Compute(t);
	}

	int RelativeFunc::GetParent() {
		return this->m_parent;
	}

	void RelativeFunc::SetParent(int new_parent) {
		this->m_parent = new_parent;
	}

}
