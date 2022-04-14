#include "CSC_StyleSDL.h"


namespace cosmovertorSDL {

	StyleSDL::StyleSDL(SDL_Color c, BrushStyleSDL b) :
		color(c), brush(b), color2(c) {

	}

	StyleSDL::StyleSDL(SDL_Color c, BrushStyleSDL b, SDL_Color c2) :
		color(c), brush(b), color2(c2) {

	}
}