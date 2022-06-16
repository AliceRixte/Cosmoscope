#pragma once


#include <unordered_map>

#include "CSC_CosmicShader.h"


namespace cosmoscope {
	class CosmosMachine {
	public:
		CosmosMachine();

		void AddShader(std::string name, CosmicCallback ccb);
		void NextStep();
	private:
		std::unordered_map <std::string, CosmicShader> shaders;
		CosmicQueue objects;
	};
}

