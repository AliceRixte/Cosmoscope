#pragma once

#pragma once


#include <unordered_map>
#include <queue>

namespace cosmoscope {
	using CosmicObject = std::unordered_map <std::string, std::unordered_map<std::string, double>>;
	using ComsmicQueue = std::queue <CosmicObject>;
}

