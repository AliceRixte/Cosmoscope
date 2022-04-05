#include "FuncTree.h"

namespace Cosmoscope {

	std::vector<TraceData> FuncTree::ComputeFuncs(Time t, Position origin) {
		std::vector<TraceData> res;
		for (auto f : this->funcs) {
			res.push_back(f->Compute(t, origin));
		}
		return res;
	}

	int FuncTree::AddParamCallback(const std::function<Position(Time)>& param_cb, const int parent_id, const Color& color) {
		funcs.push_back(new RelativeFunc{param_cb,parent_id,color});
		return funcs.size() - 1;
	}

	int FuncTree::AddColorCallback(const std::function<TraceData(Time)>& param_cb, const int parent_id) {

		funcs.push_back(new RelativeFunc{param_cb,parent_id});
		return funcs.size() - 1;
	}

	FuncTree::~FuncTree() {
	for (auto f : this->funcs) {
		delete f;
		}
	}



}