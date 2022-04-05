#pragma once

#include<SDL.h>
#include<cmath>

// this function draws an ellipse directly on the renderer that fits the given rectangle, with a gradient toward transparency
// this is probably not optimal, maybe using a texture would be better but the color constantly changes.
// Return value is 0if everything went fine
int DrawEllipse(SDL_Renderer* renderer, const SDL_Rect& ellipseRect, const SDL_Color& color, double plainPercent = 0.0);
