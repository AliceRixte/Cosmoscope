#pragma once

#include <boost/circular_buffer.hpp>
#include <functional>
#include <stack>
#include <queue>
#include "json/single_include/nlohmann/json.hpp"


namespace cosmoscope {
	using CosmicState = nlohmann::json;

	class CosmicShader {
	public:
		using CosmicCallback = std::function <void(CosmicState&, const std::unordered_map <std::string, CosmicShader>& )>;

		CosmicShader();
		CosmicShader(const CosmicCallback& cb, int history_size = 1);
		CosmicShader(const CosmicCallback& cb, const std::vector<std::string>& children, int history_size = 1);
		void Compute(const CosmicState& object, const std::unordered_map <std::string, CosmicShader>& shaders,
					std::queue<std::shared_ptr<CosmicState> >& resultQueue, std::stack<std::pair<std::string, std::shared_ptr<CosmicState> > > & callStack );
		const CosmicState& GetOlderState(int age) const ;
		bool OlderStateExists(int age) const;
	private : 
		CosmicCallback m_cb;
		std::vector<std::string> m_childrenShaders;
		boost::circular_buffer<CosmicState> m_history;

	};
}
