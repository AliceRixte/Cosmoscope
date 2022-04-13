#include "CSC_style.h"


namespace cosmoscope {

	double uint8ToDouble(uint8_t i) {
		return static_cast<double>(i) / 255.0;
	}

	Color::Color(double r, double g, double b, double a)  :
		r(r), g(g), b(b), a(a) {

	}
	Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) :
		r(uint8ToDouble(r)), g(uint8ToDouble(g)), b(uint8ToDouble(b)), a(uint8ToDouble(a)) {

	}
	
	Style::Style(Color c, BrushStyle b) : 
		color(c), brush(b), color2(c) {

	}

	Style::Style(Color c, BrushStyle b, Color c2) :
		color(c), brush(b), color2(c2) {

	}
}