/// @file CosmosToSDL.h
/// @brief Contains all the practical conversion functions to make the cosmoscope communicate with the SDL library
///
/// @author Alice Rixte
/// @date 06/04/2022
#pragma once

#include <SDL.h>
#include "CSC_CallbackFuncs.h"


namespace cosmoscope_SDL {
	SDL_Color colorToSDL(cosmoscope::Color c);

}
