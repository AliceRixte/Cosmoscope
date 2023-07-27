#include "CSC_CosmicMachine.h"

namespace cosmoscope {
	CosmicMachine::CosmicMachine() : 
		//m_currentState{}, m_initialShader{"main"},
		m_callStack{},
		m_shaders{}, m_resultQueue{} 
	{
		m_callStack.push({ "main",std::make_shared<CosmicState>() });
	}

	CosmicMachine::CosmicMachine(const CosmicState& initial_state) :  
		//m_currentState(initialState), m_initialShader(),
		m_shaders{}, m_callStack{}, m_resultQueue{}
	{
		m_callStack.push({ "main",std::make_shared<CosmicState>(initial_state) });
	}

	CosmicMachine::CosmicMachine(CosmicState&& initial_state) :
		//m_currentState(std::move(initialState)), m_initialShader("main"), 
		m_shaders {}, m_callStack{}, m_resultQueue{}
	{
		m_callStack.push({ "main",std::make_shared<CosmicState>(std::move(initial_state)) });
	}

	void CosmicMachine::AddShader(std::string name, const CosmicShader::CosmicCallback& ccb, int history_size) {
		m_shaders.insert({ name,CosmicShader(ccb,history_size)});
	}

	void CosmicMachine::AddShader(std::string name, const CosmicShader::CosmicCallback& ccb, const std::vector<std::string>& children, int history_size) {
		m_shaders.insert({ name,CosmicShader(ccb,children,history_size) });
	}

	void CosmicMachine::NextStep(){
		if (!m_callStack.empty()) {
			auto current_call = m_callStack.top();
			std::unordered_map<std::string, CosmicShader>::iterator current_shader = m_shaders.find(current_call.first);
			if (current_shader == m_shaders.end()) {
				std::cerr << "Shader \"" << current_call.first << "\" wasn't found" << std::endl;
			}
			else {
				current_shader->second.Compute(*current_call.second, m_shaders, m_resultQueue, m_callStack);
			}
		}
	}

	std::shared_ptr<const CosmicState> CosmicMachine::ReadNextState() {
		if (m_resultQueue.empty()) {
			return nullptr;
		}
		else {
			std::shared_ptr<const CosmicState> res = m_resultQueue.front();
			m_resultQueue.pop();
			return res;
		}
	}

	/*void CosmicMachine::SetInitialShader(const std::string& name) {
		m_initialShader = name;
	}*/
}
