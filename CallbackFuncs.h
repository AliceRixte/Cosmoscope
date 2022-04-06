#pragma once

#include <functional>
#include <cstdint>

#include "CoorSystem.h"

namespace cosmoscope {

struct Color {uint8_t  r, g, b, a; };



struct TraceData { Position pos;  Color c; };

using Time = double;
using ParamCallback = std::function<Position(Time)>;
using ColorCallback = std::function<Color(Time)>;


class ParamFunc {
public:
	explicit ParamFunc(const ParamCallback& param_func, CoorSystem coor = CoorSystem::Cartesian);
	Position Compute(Time t);
private:
	ParamCallback m_paramCb;
	CoorSystem m_coor;
};


class ColorFunc {
public:
	explicit ColorFunc(const Color& color);
	explicit ColorFunc(const ColorCallback& color_cb);
	Color Compute(Time t);
private:
	ColorCallback m_colorCb;
};


}