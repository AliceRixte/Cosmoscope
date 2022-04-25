/// @file CSC_Scheduler.h
/// @brief Contains a circular queue to store the history of relative function computations
/// 
/// @author Alice Rixte
/// @date 13/04/2022
#pragma once

#include <vector>

#include "CSC_CoorSystem.h"
#include "CSC_Time.h"
#include "CSC_Style.h"

#include "CSC_FuncTree.h"



namespace cosmoscope {


	class Scheduler {
	public:
		Scheduler(const FuncTree& func_tree);
		Scheduler(FuncTree&& func_tree);

		void ComputeSnaps(Time t , int nb_snaps);

		std::vector<TreeSnap> ReadSnaps() ;


	private:
		std::vector<TreeSnap> m_snapBuf;

		FuncTree m_ftree;	   
	};
}
