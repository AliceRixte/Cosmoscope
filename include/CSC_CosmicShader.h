#pragma once


#include "CSC_CosmicCallback.h"


namespace cosmoscope {
	class CosmicShader {
	public:
		CosmicShader(const CosmicCallback& ccb, int history_size);
		void Compute(CosmicObject& object);
	private : 
		int m_now;
		std::vector<CosmicObject> m_history;
		CosmicCallback m_cosmicCB;

	};
}
