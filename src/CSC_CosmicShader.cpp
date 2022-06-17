#include "CSC_CosmicShader.h"

namespace cosmoscope {

	CosmicShader::CosmicShader(int recursive_depth = 1) :
		m_now(0), m_history(recursive_depth)
	{

	}

	void CosmicShader::Compute(const CosmicObject& state, const std::unordered_map <std::string, CosmicShader>& ccbs) {

	}
}
