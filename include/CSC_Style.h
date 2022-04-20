/// @file CSC_Style.h
/// @brief Contains structures used to describe drawing style in the cosmoscope
/// 
/// @author Alice Rixte
/// @date 05/04/2022
#pragma once

#include <cstdint>

namespace cosmoscope {

	/// @brief A structure used to store a drawing color All values range from 0.0 to 1.0
	struct Color {
		/// @brief A constructor using double values ranging from 0.0 to 1.0 to define a color.
		/// @param r  red  : ranges from 0.0 to 1.0
		/// @param g  green: ranges from 0.0 to 1.0
		/// @param b  blue : ranges from 0.0 to 1.0
		/// @param a  alpha (transparency) : ranges from 0.0 to 1.0
		Color(double r, double g, double b, double a = 1.0);

		/// @brief A constructor using values ranging  from 0 to 255 to define a color
		/// @param r red  : ranges from 0 to 255
		/// @param g green: ranges from 0 to 255
		/// @param b blue : ranges from 0 to 255
		/// @param a alpha (transparency) : ranges from 0 to 255
		Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);

		/// @brief red : ranges from 0.0 to 1.0
		double r;
		/// @brief green: ranges from 0.0 to 1.0
		double g;
		/// @brief blue : ranges from 0.0 to 1.0
		double b;
		/// @brief alpha (transparency) : ranges from 0.0 to 1.0
		double a;
	};

	/// @brief Contains generic values to control hardness and radius of the drawing brush
	struct BrushStyle {
		/// @brief radius of the brush. Ranges from 0.0 to 1.0 
		double radius;
		/// @brief hardness : how hard the brush is applied. Ranges from 0.0 to 1.0. When set to -1.0, the function is not drawn.
		double h;

	};

	/// @brief A structure used to store a drawing style (color, transparency and hardness). All values range from 0.0 to 1.0
	struct Style {
		/// @brief Use this constructor if you do not want to use a secondary color (it will be set identical to the main color)
		/// @param c The main color of the style
		/// @param b The brush style of the style
		Style(Color c, BrushStyle b);
		/// @brief Use this constructor if you want a fully personnalized drawing style
		/// @param c  The main color of the style
		/// @param b  The brush style of the style
		/// @param c2 The secondary color of the style
		Style(Color c, BrushStyle b, Color c2);

		/// @brief Main color of the style
		Color color;
		/// @brief Secondary color of the style
		Color color2;
		/// @brief Additional values to personalize the brush
		BrushStyle brush;
	};

}