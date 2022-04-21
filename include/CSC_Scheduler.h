/// @file CSC_SnapQueue.h
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

	/// @brief Regroups all data needed to display a function at a precise moment of time (snapshot)
	struct FuncSnap {
		// @brief The new relative time after calling the time callback function
		Time tt;
		/// @brief The absolute cartesian position at the time of the snapshot
		CartesianPos p;
		/// @brief The style at the time of the snapshot
		Style s;
	};
	
	/// @brief All the data needed to display the func tree at a precise moment of time (snapshot)
	using TreeSnap = std::vector<FuncSnap>;

	class Scheduler {
	public:
		Scheduler(const FuncTree func_tree, unsigned int size);
		void ComputeSnaps(const TreeSnap& tree_snap);

		void ReadSnaps(TreeSnap* p_tree_snap, int snap_number);


	private:
		int m_start;
		int m_readIndex;
		std::vector<TreeSnap> m_history;

		int NextIndex(int i);

	};
}
