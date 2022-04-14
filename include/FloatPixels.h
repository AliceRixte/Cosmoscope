#pragma once

/// @file CSC_SnapQueueSDL.h
/// @brief This allows the creation of float positions. 
/// They can be represented by using alpha settings depending on the distance to the virtual float position. 
/// Double precision is not needed here because the difference would not be perceived.
///
/// @author Alice Rixte
/// @date 14/04/2022

namespace floatpix {
	struct Position {
		float x;
		float y;
	};

	using Distance = float;
}