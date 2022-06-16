#include "CSC_CosmicShader.h"

namespace cosmoscope {

	CosmicShader::CosmicShader(const CosmicCallback& ccb, int recursive_depth = 1) :
		m_now(0), m_history(recursive_depth), m_cosmicCB(ccb)
	{

	}

	void CosmicShader::Compute(CosmicObject& state) {

	}
}
