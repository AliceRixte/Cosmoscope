/// @file CosmosDrawerSDL.h
/// @brief This class allows to draw a Tree snapshot on a given renderer.
/// 
/// @author Alice Rixte
/// @date 07/04/2022
/// 
#pragma once

#include "CSC_FuncTree.h"
#include "CSC_CosmovertorSDL.h"

namespace cosmoscopeSDL {
	class CosmosDrawerSDL {
	public:
		CosmosDrawerSDL(const cosmoscope::FuncTree* func_tree, double length_scale, floatpix::Position origin);

		void DrawSnap(double time, SDL_Renderer* renderer);

	private:
		const cosmoscope::FuncTree* m_funcTree;
		SnapQueueSDL m_snapQueue;
		CosmovertorSDL m_cosmovertor;

	};
}



