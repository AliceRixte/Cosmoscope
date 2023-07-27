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
	FuncTree::FuncTree() {

	}


	FuncTree::FuncTree(const FuncTree& ft) {
		std::cout << "Cpy" << std::endl;
		for (int i = 0; i < ft.m_funcs.size(); i++) {
			m_funcs.push_back(new RelativeFunc(*ft.m_funcs[i]));
		}
	}

	FuncTree::FuncTree(FuncTree&& ft) {
		std::cout << "Mv" << std::endl;
		m_funcs = ft.m_funcs;
		for (int i = 0; i < ft.m_funcs.size(); i++) {
			ft.m_funcs[i] = nullptr;
		}
	}



	TreeSnap FuncTree::Compute(Time t) const {
		TreeSnap res;
		for (int i = 0; i < m_funcs.size(); i++) {
			int parent = m_funcs[i]->GetParent();

			CartesianPos rel_origin{0.0,0.0};
			Time rel_time = t;
			//the default origin will stay if the parent id is -1
			if (parent >= i) {
				throw BadFuncOrdering(i,parent);
			}
			else if (parent >= 0) {
				rel_origin = res[parent].p;
				rel_time = res[parent].tt;
			}
			res.push_back(m_funcs[i]->Compute(rel_time, rel_origin));
		} 
		return res;
	}



	int FuncTree::AddMonochromeFunc(int parent_id, const ParamCallback& param_cb, const Style& style){
		m_funcs.push_back(new RelativeFunc{parent_id,param_cb,style});
		return static_cast<int>(m_funcs.size()) - 1;
	}

	int FuncTree::AddTimedMonochromeFunc(int parent_id, const TimeCallback& time_cb, const ParamCallback& param_cb, const Style& style) {
		m_funcs.push_back(new RelativeFunc{ parent_id,time_cb,param_cb,style });
		return static_cast<int>(m_funcs.size()) - 1;
	}

	int FuncTree::AddPolychromeFunc(int parent_id, const ParamCallback& param_cb, const StyleCallback& style_cb) {
		m_funcs.push_back(new RelativeFunc{parent_id,param_cb,style_cb});
		return static_cast<int>(m_funcs.size()) - 1;
	}

	int FuncTree::AddTimedPolychromeFunc(int parent_id, const TimeCallback& time_cb, const ParamCallback& param_cb, const StyleCallback& style_cb) {
		m_funcs.push_back(new RelativeFunc{ parent_id,time_cb,param_cb,style_cb });
		return static_cast<int>(m_funcs.size()) - 1;
	}

	int FuncTree::Size() const {
		return static_cast<int>(m_funcs.size());
	}


	/*int FuncTree::GetRecurrenceDepth() const {
		return 1;
	}*/

	FuncTree::~FuncTree() {
	for (auto f : m_funcs) {
		delete f;
		}
	}



}