#include "CSC_FuncTree.h"

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
	FuncTree::FuncTree(const CartesianPos& origin) : m_origin(origin) {

	}


	std::vector<CartesianPos> FuncTree::ComputeAllPos(Time t) const {
		std::vector<CartesianPos> res;
		for (int i = 0; i < funcs.size(); i++) {
			int parent = funcs[i]->GetParent();

			CartesianPos rel_origin = m_origin; 
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

	std::vector<Style> FuncTree::ComputeAllStyle(Time t) const {
		std::vector<Style> res;
		for (auto f : funcs) {
			res.push_back(f->ComputeStyle(t));
		}
		return res;
	}



	int FuncTree::AddMonochromeCartesian(int parent_id, const CartesianCallback& cartesian_cb, const Style& style){
		funcs.push_back(new RelativeFunc{parent_id,cartesian_cb,style});
		return funcs.size() - 1;
	}

	int FuncTree::AddMonochromePolar(int parent_id, const PolarCallback& polar_cb, const Style& style) {
		funcs.push_back(new RelativeFunc{ parent_id,polar_cb,style });
		return funcs.size() - 1;
	}

	int FuncTree::AddPolychromeCartesian(int parent_id, const CartesianCallback& cartesian_cb, const StyleCallback& style_cb) {
		funcs.push_back(new RelativeFunc{parent_id,cartesian_cb,style_cb});
		return funcs.size() - 1;
	}

	int FuncTree::AddPolychromePolar(int parent_id, const PolarCallback& polar_cb, const StyleCallback& style_cb) {
		funcs.push_back(new RelativeFunc{ parent_id,polar_cb,style_cb });
		return funcs.size() - 1;
	}


	void FuncTree::SetOrigin(const CartesianPos& origin) {
		m_origin = origin;
	}

	FuncTree::~FuncTree() {
	for (auto f : this->funcs) {
		delete f;
		}
	}



}