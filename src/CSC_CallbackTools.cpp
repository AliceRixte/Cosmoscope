#include "CSC_CallbackTools.h"

namespace cosmoscope{

	PolarCallback createCircle(double radius, double rotation_speed) {
		return [radius, rotation_speed](Time t) {return PolarPos{ radius ,t * rotation_speed }; };
	}

	TimeCallback timeMultiplier(double time_factor) {
		return [time_factor](Time t) {return t * time_factor; };
	} 

    StyleCallback gradient(double freq, Color color1, Color color2) {
        return [freq, color1, color2](Time t) {
            double mod = std::fmod(t, freq);
            double grad = 0;
            if (mod < freq / 2.0) {
                grad = 2.0 * mod / freq;
            }
            else {
                grad = 2.0 * (freq - mod) / freq;
            }

            return Style{
                Color{(1 - grad) * color1.r + grad * color2.r,
                      (1 - grad) * color1.g + grad * color2.g,
                      (1 - grad) * color1.b + grad * color2.b,
                      (1 - grad) * color1.a + grad * color2.a},
                BrushStyle{0.5,0.0}
            };
        };
    }

    
}