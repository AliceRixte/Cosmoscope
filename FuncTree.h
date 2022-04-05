#pragma once

#include<vector>
#include<functional>

#include "RelativeFunc.h"

// This class regroups all the relative functions. Their frame is tied to their parent function or to the chosen origin if their parent id is -1

namespace Cosmoscope {

	class FuncTree {
	public:

		//Computes all the relative functions at a time t, and taking for origin/center the position origin
		std::vector<TraceData> ComputeFuncs(Time t, Position origin);

		//Adds a parametric function of parent parent_id, white by default
		//returs id of the new function
		int AddParamCallback(const std::function<Position(Time)>& param_cb, const int parent_id = -1 , const Color& color = { 255,255,255,255 });

		//Adds a coloured parametric function of parent parent_id
		//returs id of the new function
		int AddColorCallback(const std::function<TraceData(Time)>& color_cb, const int parent_id = -1);

		~FuncTree();


	private:
		std::vector<RelativeFunc*> funcs;
	};

}