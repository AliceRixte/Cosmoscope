
#include "brushes.h"

#include <iostream>
using namespace std;

namespace draw_SDL {

double distance(double x0, double y0, double x1, double y1) {
	return std::sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

int DrawEllipse(SDL_Renderer* renderer, const cosmoscopeSDL::Point& p , double width, double height, const SDL_Color& color, double plain_ratio, float grad_steepness) {
	if (plain_ratio < 0.0 || plain_ratio > 1.0) {
		return -1;
	}

	double a = width / 2.0;
	double b = height / 2.0;


	double c = 0.0;
	double f1x = p.get<0>();
	double f2x = f1x;
	double f1y = p.get<1>();
	double f2y = f1y;
	double ellipse_dist = 0.0;


	if (a >= b) {
		ellipse_dist = 2 * a;
		c = std::sqrt(a * a - b * b);
		f1x += c;
		f2x -= c;
	}
	else {
		ellipse_dist = 2 * b;
		c = std::sqrt(b * b - a * a);
		f1y += c;
		f2y -= c;
	}

	double plain_dist = 2 * c + (ellipse_dist - 2 * c) * plain_ratio;

	
	for (int x = std::ceil(p.get<0>() - a); x <= std::floor(p.get<0>() + a); x++) {
		for (int y = std::ceil(p.get<1>() - b); y <= std::floor(p.get<1>() + b); y++) {
			double dist = distance(f1x, f1y, static_cast<double>(x), static_cast<double>(y))
				+ distance(f2x, f2y, static_cast<double>(x), static_cast<double>(y));

			
			if (dist <= plain_dist) {
				SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
				SDL_RenderDrawPoint(renderer, x, y);
			}
			else if (dist <= ellipse_dist){
				SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 
					static_cast<Uint8>(color.a * pow(1.0 - (dist - plain_dist) / (ellipse_dist - plain_dist), grad_steepness)));
				SDL_RenderDrawPoint(renderer, x,y);
			}			
		}
	}
	return 0;
}




int DrawCircle(SDL_Renderer* renderer, const cosmoscopeSDL::Point& p, double radius, const SDL_Color& color, double plain_ratio, float grad_steepness) {
	if (plain_ratio < 0.0 || plain_ratio > 1.0) {
		return -1;
	}

	double plain_dist = radius * plain_ratio;

	for (int x = std::ceil(p.get<0>() - radius); x <= std::floor(p.get<0>() + radius); x++) {
		for (int y = std::ceil(p.get<1>() - radius); y <= std::floor(p.get<1>() + radius); y++) {
			double dist = distance(p.get<0>(), p.get<1>(), static_cast<double>(x), static_cast<double>(y));
			if (dist <= plain_dist) {
				SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
				SDL_RenderDrawPoint(renderer, x, y);
			}
			else if (dist <= radius) {
				SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b,
					static_cast<Uint8>(color.a * pow(1.0 - (dist - plain_dist)/ (radius - plain_dist), grad_steepness)));
				SDL_RenderDrawPoint(renderer, x, y);
			}
		}
	}
	return 0;
}

}