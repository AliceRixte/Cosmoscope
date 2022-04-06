#include "CosmosToSDL.h"


namespace cosmoscope_SDL {

	//converts a double ranging from 0 to 1 to an integer ranging from 0 to 255
	Uint8 double01to255(double v) {
		return static_cast<Uint8>(255 * v);
	}

	SDL_Color styleToColor(cosmoscope::Style style) {
		return SDL_Color{	double01to255(style.r),
							double01to255(style.g),
							double01to255(style.b),
							double01to255(style.a) 
		};
	}
}