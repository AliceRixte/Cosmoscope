#pragma once

#include <boost/circular_buffer.hpp>
#include "CSC_CosmicCallback.h"



namespace cosmoscope {
	class CosmicShader {
	public:
		CosmicShader(int history_size);
		void Compute(const CosmicObject& object, const std::unordered_map <std::string, CosmicShader>& ccbs);
	private : 
		int m_now;
		boost::circular_buffer<CosmicObject> m_history;

	};
}
