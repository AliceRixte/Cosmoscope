/// @file CosmosToSDL.h
/// @brief Contains all the practical conversion functions to make the cosmoscope communicate with the SDL library
///
/// @author Alice Rixte
/// @date 05/04/2022
#pragma once

#include <SDL.h>
#include "CSC_Time.h"
#include "CSC_CoorSystem.h"
#include "CSC_Style.h"

namespace cosmoscope_SDL {
	SDL_Color styleToColor(cosmoscope::Style style);
}
