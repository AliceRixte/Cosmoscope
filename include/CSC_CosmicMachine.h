#pragma once


#include <unordered_map>
#include <stack>
#include <queue>

#include <iostream>
#include "CSC_CosmicShader.h"


namespace cosmoscope {
	class CosmicMachine {
	public:
		CosmicMachine();
		CosmicMachine(const CosmicState& initialState);
		CosmicMachine(CosmicState&& initialState);

		void AddShader(std::string name,const CosmicShader::CosmicCallback& ccb, int history_size = 0);
		void AddShader(std::string name,const CosmicShader::CosmicCallback& ccb, const std::vector<std::string>& children, int history_size = 0);
		void NextStep();//const std::string& start_shader = "");
		//void SetInitialShader(const std::string& name);

		std::shared_ptr<const CosmicState> ReadNextState();

	private:
		std::unordered_map <std::string, CosmicShader> m_shaders;
		std::stack<std::pair<std::string, std::shared_ptr<const CosmicState> > > m_callStack;
		std::queue<std::shared_ptr<const CosmicState> > m_resultQueue;
	};
}

