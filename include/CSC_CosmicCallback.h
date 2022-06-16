#pragma once


#include <functional>

#include "CSC_CosmicObject.h"

namespace cosmoscope {
	using CosmicCallback = std::function<void(CosmicObject&)>;
}

