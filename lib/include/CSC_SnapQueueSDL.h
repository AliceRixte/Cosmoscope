/// @file CSC_SnapQueueSDL.h
/// @brief The SDL version of a snapqueue, with SDL units, type, and coordinate system.
///
/// @author Alice Rixte
/// @date 14/04/2022

#pragma once


#include <vector>
#include <SDL.h>

#include "CSC_CoorSystemSDL.h"
#include "CSC_StyleSDL.h"


namespace cosmoscopeSDL {

	/// @brief Regroups all data needed to display a function at a precise moment of time (snapshot)
	struct FuncSnapSDL {
		// @brief The new relative time after calling the time callback function
		double tt;
		/// @brief The absolute cartesian position at the time of the snapshot
		Point p;
		/// @brief The style at the time of the snapshot
		StyleSDL s;
	};


	/// @brief All the data needed to display the func tree at a precise moment of time (snapshot)
	using TreeSnapSDL = std::vector<FuncSnapSDL>;


	class SnapQueueSDL {
	public:
		explicit SnapQueueSDL(unsigned int history_size = 2);
		void WriteSnap(const TreeSnapSDL& tree_snap);

		TreeSnapSDL GetSnap(unsigned int snap_age) const;
		int Size();


	private:
		int m_start;
		std::vector<TreeSnapSDL> m_history;

	};
}







namespace cosmoscope {

	

	

	
}
