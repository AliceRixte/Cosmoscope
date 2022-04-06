#include "FuncTree.h"

namespace cosmoscope {

	//---------------------------- BadFuncOrdering --------------------------------------
	BadFuncOrdering::BadFuncOrdering(int id_problem, int parent_problem) :
		m_idProblem(id_problem), m_parentProblem(parent_problem) {

	}

	const char* BadFuncOrdering::what() const {
		return ("The hierarchy of relative funcs is broken or cyclic. The id " + std::to_string(m_idProblem) 
			+ "is pointing to the parrent id " + std::to_string(m_parentProblem)).c_str();
	}


	//---------------------------------- FuncTree  --------------------------------------
	FuncTree::FuncTree(const Position& origin) : m_origin(origin) {

	}


	std::vector<Position> FuncTree::ComputeAllPos(Time t) {
		std::vector<Position> res;
		for (int i = 0; i < funcs.size(); i++) {
			int parent = funcs[i]->GetParent();

			Position rel_origin = m_origin; 
			//the default origin will stay if the parent id is -1
			if (parent >= i) {
				throw BadFuncOrdering(i,parent);
			}
			else if (parent >= 0) {
				rel_origin = res[parent];
			}
			res.push_back(funcs[i]->ComputePos(t, rel_origin));
		} 
		return res;
	}

	int FuncTree::AddParamCallback(int parent_id, const ParamCallback& param_cb, CoorSystem coor, const Color& color){
		funcs.push_back(new RelativeFunc{parent_id,param_cb,coor,color});
		return funcs.size() - 1;
	}



	void FuncTree::SetOrigin(const Position& origin) {
		m_origin = origin;
	}

	FuncTree::~FuncTree() {
	for (auto f : this->funcs) {
		delete f;
		}
	}



}