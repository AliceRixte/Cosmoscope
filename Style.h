/// @file Style.h
/// @brief Contains structures used to describe drawing style in the cosmoscope
/// 
/// @author Alice Rixte
/// @date 05/04/2022
#pragma once


namespace cosmoscope {

	/// @brief A structure used to store a drawing style (color, transparency and hardness). All values range from 0.0 to 1.0
	struct Style {
		/// @brief red : ranges from 0.0 to 1.0
		double r;
		/// @brief green: ranges from 0.0 to 1.0
		double g;
		/// @brief blue : ranges from 0.0 to 1.0
		double b;
		/// @brief alpha (transparency) : ranges from 0.0 to 1.0
		double a;
		/// @brief hardness : how hard the brush is applied. Ranges from 0.0 to 1.0. When set to -1.0, the function is not drawn.
		double h;
	};
}