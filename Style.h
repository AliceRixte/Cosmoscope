/// @file Style.h
/// @brief Contains all functions related to displaying the cosmoscope using the library SDL2
///
/// @author Alice Rixte
/// @date 05/04/2022
#pragma once

#include<SDL.h>
#include<cmath>

// this is probably not optimal, maybe using a texture would be better but the color constantly changes.

/// @brief  Draws an ellipse directly on the renderer that fits the given rectangle, with a gradient toward transparency
/// @param renderer The SDL_Renderer to draws on
/// @param ellipseRect The rectangle the ellipse must fit
/// @param color The color of the ellipse.
/// @param plainPercent Describes when the gradient towards transparency starts : if the plain percentage is 100, then there is now gradient,
/// if it's 0, the gradients immediately applies as the points move away from the focuses. 
/// @return 0 if everything went fine
int DrawEllipse(SDL_Renderer* renderer, const SDL_Rect& ellipseRect, const SDL_Color& color, double plainPercent = 100.0);
