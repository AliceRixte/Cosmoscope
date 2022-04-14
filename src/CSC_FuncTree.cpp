#include "CSC_FuncTree.h"

#include <cstdio>

namespace cosmoscope {

	//---------------------------- BadFuncOrdering --------------------------------------
	BadFuncOrdering::BadFuncOrdering(int id_problem, int parent_problem) :
		m_message(std::string{"The hierarchy of relative funcs is broken or cyclic. The id " + std::to_string(id_problem) +
			 " is pointing to the parrent id " + std::to_string(parent_problem) + "." }) {

	}

	const char* BadFuncOrdering::what() const throw() {

		return m_message.c_str();
	}


	//---------------------------------- FuncTree  --------------------------------------
	FuncTree::FuncTree(const CartesianPos& origin) : m_origin(origin) {

	}



	void FuncTree::ComputeAll(Time t, SnapQueue* snap_q) const {
		std::vector<FuncSnap> res;
		for (int i = 0; i < funcs.size(); i++) {
			int parent = funcs[i]->GetParent();

			CartesianPos rel_origin = m_origin; 
			//the default origin will stay if the parent id is -1
			if (parent >= i) {
				throw BadFuncOrdering(i,parent);
			}
			else if (parent >= 0) {
				rel_origin = res[parent].p;
			}
			res.push_back(FuncSnap{
				t,
				funcs[i]->ComputePos(t, rel_origin),
				funcs[i]->ComputeStyle(t)
				}
			);
		} 
		snap_q->WriteSnap(res);
	}



	int FuncTree::AddMonochromeFunc(int parent_id, const ParamCallback& param_cb, const Style& style){
		funcs.push_back(new RelativeFunc{parent_id,param_cb,style});
		return static_cast<int>(funcs.size()) - 1;
	}

	int FuncTree::AddPolychromeFunc(int parent_id, const ParamCallback& param_cb, const StyleCallback& style_cb) {
		funcs.push_back(new RelativeFunc{parent_id,param_cb,style_cb});
		return static_cast<int>(funcs.size()) - 1;
	}


	int FuncTree::Size() const {
		return static_cast<int>(funcs.size());
	}

	void FuncTree::SetOrigin(const CartesianPos& origin) {
		m_origin = origin;
	}

	int FuncTree::GetRecurrenceDepth() const {
		return 1;
	}

	FuncTree::~FuncTree() {
	for (auto f : funcs) {
		delete f;
		}
	}



}