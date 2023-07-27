/// @file CosmosWindowSDL.h
/// @brief Contains a specialization of a window manager to run the cosmoscope on a Open GL -based engine.
/// 
/// @author Alice Rixte
/// @date 28/05/2022
/// 
/// 

#pragma once


#include "CSC_CosmovertorSDL.h"
#include "CSC_CosmosDrawerSDL.h"
#include "CSC_Scheduler.h"

#include "WindowManagerGL.h"

namespace cosmoscopeGL {

	/// @brief This contains a whole cosmoscope with its own renderer and window
	class CosmosWindowGL : public WindowManagerGL {
	public:


		/// @brief Creates a GL display environment for a tree of relative functions
		/// @param window_name The name  of the window
		/// @param width The width of the window, in pixels
		/// @param height The height of the window, in pixels 
		/// @param scheduler A scheduler to get the snapshots from the cosmoscope
		/// @param cosmovertor A convertor from cosmic unit to SDL units
		/// @param cosmos_drawer A drawer that draws the converted snapshots
		CosmosWindowGL(const char* window_name, int width, int height,
			const cosmoscope::Scheduler& scheduler, const cosmoscopeSDL::CosmovertorSDL& cosmovertor,
			const cosmoscopeSDL::CosmosDrawerSDL& cosmos_drawer);



		/// @brief Displays a new frame based on current execution time
		/// @return 0 if everything went fine
		int UpdateFrame();


		void InitShaders();
		void InitVertices();

		~CosmosWindowGL();

	private:

		const cosmoscopeSDL::CosmosDrawerSDL& m_cosmosDrawer;

		cosmoscopeSDL::SnapQueueSDL m_snapQueue;
		cosmoscopeSDL::CosmovertorSDL m_cosmovertor;
		cosmoscope::Scheduler m_scheduler;

		double t;

		int m_previousTick;

		unsigned int m_VAO;
		unsigned int m_shaderProgram;
		unsigned int m_VBO;

	};

}