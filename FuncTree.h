#pragma once

#include <iostream>
#include <exception>
#include <string>
#include<vector>
#include<functional>

#include "RelativeFunc.h"
#include "CoorSystem.h"


// This class regroups all the relative functions. Their frame is tied to their parent function or to the chosen origin if their parent id is -1

namespace cosmoscope {


	class BadFuncOrdering : public std::exception
	{
	public:
		BadFuncOrdering(int id_problem, int parent_problem);
		virtual const char* what() const throw();
	private:
		int m_idProblem;
		int m_parentProblem;
	};


	class FuncTree {
	public:

		FuncTree(const Position& origin);
		//Computes all the relative functions at a time t, and taking for origin/center the position origin
		std::vector<Position> ComputeAllPos(Time t);

		//Adds a parametric function of parent parent_id, white by default
		//returs id of the new function
		int AddParamCallback(const int parent_id, const ParamCallback& param_cb, 
				CoorSystem coor = CoorSystem::Cartesian, const Color& color = { 255,255,255,255 });


		//sets the default origin attached to the "-1" parent
		void SetOrigin(const Position& origin);

		~FuncTree();


	private:
		std::vector<RelativeFunc*> funcs;
		Position m_origin;
	};

}