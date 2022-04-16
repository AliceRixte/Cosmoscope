#include "brushes.h"

#include <iostream>
using namespace std;

namespace draw_SDL {

double distance(double x0, double y0, double x1, double y1) {
	return std::sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

int DrawEllipse(SDL_Renderer* renderer, const SDL_Rect& ellipse_rect, const SDL_Color& color, double plain_ratio, float grad_steepness) {
	if (plain_ratio < 0.0 || plain_ratio > 1.0) {
		return -1;
	}

	double a = static_cast<float>(ellipse_rect.w) / 2.0;
	double b = static_cast<float>(ellipse_rect.h) / 2.0;



	double c = 0.0;
	double f1x = a, f2x = a;
	double f1y = b, f2y = b;
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


	for (int x = 0; x < ellipse_rect.w; x++) {
		for (int y = 0; y < ellipse_rect.h; y++) {

			double transparency = 0.0;
			double dist = distance(f1x, f1y, static_cast<double>(x), static_cast<double>(y))
				+ distance(f2x, f2y, static_cast<double>(x), static_cast<double>(y));

			if (dist > ellipse_dist) {
				transparency = 0.0;
			}
			else if (dist <= plain_dist) {
				transparency = color.a;
			}
			else {
				transparency = color.a * pow((1.0 - (dist - plain_dist) / (ellipse_dist - plain_dist)), grad_steepness);
			}

			SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, static_cast<Uint8>(transparency));
			SDL_RenderDrawPoint(renderer, ellipse_rect.x + x, ellipse_rect.y + y);
		}
	}
	return 0;
}

}