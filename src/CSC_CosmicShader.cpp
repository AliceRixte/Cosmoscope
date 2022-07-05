#include "CSC_CosmicShader.h"
#include <iostream>

namespace cosmoscope {

	CosmicShader::CosmicShader() : 
		m_cb{ [](CosmicState& state, const std::unordered_map <std::string, CosmicShader>& shaders) {} },
		m_history{ 1 },
		m_childrenShaders{}
	{

	}

	CosmicShader::CosmicShader(const CosmicCallback& cb, int history_size) :
		m_cb{ cb },
		m_history{ history_size },
		m_childrenShaders{}
	{

	}

	CosmicShader::CosmicShader(const CosmicCallback& cb, const std::vector<std::string>& children, int history_size) :
		m_cb{ cb },
		m_history{ history_size },
		m_childrenShaders{children}
	{

	}

	void CosmicShader::Compute(const CosmicState& state, const std::unordered_map <std::string, CosmicShader>& shaders, 
		std::queue< std::shared_ptr<const CosmicState> >& resultQueue, std::stack<std::pair<std::string, std::shared_ptr<const CosmicState> > >& callStack) {

		std::shared_ptr<CosmicState> res = std::make_shared<CosmicState>(state);
		m_cb(*res, shaders);
		resultQueue.push(res);

		if (m_history.capacity() > 0) {
			m_history.push_back(res);
		}

		if (m_childrenShaders.size() > 0) {
			
			for (auto s : m_childrenShaders) {
				callStack.push({ s, res });
			}
		}	
	}

	bool CosmicShader::OlderStateExists(int age) const {
		return age < m_history.size();
	}

	std::shared_ptr<const CosmicState> CosmicShader::GetOlderState(int age) const {
		
		if (age < m_history.size()) {
			return m_history[m_history.size() - 1 - age ];
		}
		else {
			return NULL;
		}
	}
}
