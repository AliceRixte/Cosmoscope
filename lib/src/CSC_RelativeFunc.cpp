#include "CSC_RelativeFunc.h"

namespace cosmoscope {

	RelativeFunc::RelativeFunc(int id_parent, const ParamCallback& param_cb, const Style& style) :
		m_parent(id_parent),
		m_paramFunc(ParamFunc{param_cb}),
		m_styleFunc(style) {
	}

	RelativeFunc::RelativeFunc(int id_parent, const TimeCallback& time_cb, const ParamCallback& param_cb, const Style& style) :
		m_parent(id_parent),
		m_paramFunc(ParamFunc{ param_cb }),
		m_styleFunc(style),
		m_timeFunc(time_cb) {
	}

	RelativeFunc::RelativeFunc(int id_parent, const ParamCallback& param_cb, const StyleCallback& style_cb) :
		m_parent(id_parent),
		m_paramFunc(ParamFunc{param_cb}),
		m_styleFunc(style_cb) {
	}

	RelativeFunc::RelativeFunc(int id_parent, const TimeCallback& time_cb, const ParamCallback& param_cb, const StyleCallback& style_cb ) :
		m_parent(id_parent),
		m_paramFunc(ParamFunc{ param_cb }),
		m_styleFunc(style_cb),
		m_timeFunc(time_cb) {
	}

	Time RelativeFunc::ComputeTime(Time t) {
		return m_timeFunc.Compute(t);
	}

	CartesianPos RelativeFunc::ComputePos(Time t, const CartesianPos& origin) {
		return m_paramFunc.Compute(t) + origin;
	}

	Style RelativeFunc::ComputeStyle(Time t) {
		return m_styleFunc.Compute(t);
	}

	FuncSnap RelativeFunc::Compute(Time t, const CartesianPos& origin) {
		Time t2 = ComputeTime(t);
		return FuncSnap{ t2, ComputePos(t2,origin),ComputeStyle(t2) };
	}

	int RelativeFunc::GetParent() {
		return this->m_parent;
	}

	void RelativeFunc::SetParent(int new_parent) {
		this->m_parent = new_parent;
	}

}
