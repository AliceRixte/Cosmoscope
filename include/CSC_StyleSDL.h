/// @file CSC_SnapQueueSDL.h
/// @brief The SDL version of a cosmic style, with SDL units, type, and coordinate system.
///
/// @author Alice Rixte
/// @date 14/04/2022
#pragma once

#include <SDL.h>

namespace cosmoscopeSDL {


	/// @brief Contains generic values to control hardness and radius of the drawing brush
	struct BrushStyleSDL {
		/// @brief hardness : how hard the brush is applied. Ranges from 0.0 to 1.0. When set to -1.0, the function is not drawn.
		double h;
		/// @brief radius of the brush in pixels
		int radius;
	};

	/// @brief A structure used to store a drawing style (color, transparency and hardness). All values range from 0.0 to 1.0
	struct StyleSDL {
		/// @brief Use this constructor if you do not want to use a secondary color (it will be set identical to the main color)
		/// @param c The main color of the style
		/// @param b The brush style of the style
		StyleSDL(SDL_Color c, BrushStyleSDL b);
		/// @brief Use this constructor if you want a fully personnalized drawing style
		/// @param c  The main color of the style
		/// @param b  The brush style of the style
		/// @param c2 The secondary color of the style
		StyleSDL(SDL_Color c, BrushStyleSDL b, SDL_Color c2);

		/// @brief Main color of the style
		SDL_Color color;
		/// @brief Secondary color of the style
		SDL_Color color2;
		/// @brief Additional values to personalize the brush
		BrushStyleSDL brush;
	};

}