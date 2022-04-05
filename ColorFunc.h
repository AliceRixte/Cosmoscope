#pragma once

#include <functional>
#include <cstdint>

namespace Cosmoscope {

struct Color {uint8_t  r, g, b, a; };

struct Position { 
	double x, y; 
	Position operator +(const Position& a)
	{
		return Position{a.x + x, a.y +y};
	}
};
struct TraceData { Position pos;  Color c; };

using Time = double;


class ColorFunc {
public: 
	virtual TraceData Compute(Time t)=0;
};

class ColorCallback : public ColorFunc {
public:
	explicit ColorCallback(std::function<TraceData(Time)> colorFunc);
	TraceData Compute(Time t);
private:
	std::function<TraceData(Time)> m_colorFunc;
};


class ParamCallback : public ColorFunc {
public:
	explicit ParamCallback(std::function<Position(Time)> paramFunc,Color color);
	TraceData Compute(Time t);
	void setColor(Color color);

private:
	std::function<Position(Time)> m_paramFunc;
	Color m_color;
};

}