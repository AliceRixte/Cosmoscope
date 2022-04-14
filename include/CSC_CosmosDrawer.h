/// @file CSC_CosmosDrawer.h
/// @brief Contains the main SDL class handling all the display of the cosmoscope with the SDL library
/// 
/// @author Alice Rixte
/// @date 07/04/2022
#pragma once
#include <SDL.h>

#include "CSC_funcTree.h"
#include "CSC_CosmovertorSDL.h"
#include "savepng.h"




namespace cosmoscope_SDL {
	/// @brief This contains a whole cosmoscope with its own renderer and window
	class CosmosDrawer {
	public:
		/// @brief Creates an SDL display environment for a tree of relative functions
		/// @param window_name The name  of the window
		/// @param width The width of the window, in pixels
		/// @param height The height of the window, in pixels
		/// @param func_tree A tree of relative functions
		CosmosDrawer(const char* window_name, int width, int height, const cosmoscope::FuncTree* func_tree);

		//void Play();
		
		/// @brief Processes all the current events related to the windows
		/// @return 0 if everything went fine
		int ProcessEvents();

		/// @brief Displays a new frame based on current execution time
		/// @return 0 if everything went fine
		int UpdateFrame();

		/// @brief States wether the window is opened or has been closed
		/// @return Switches to false when user closes the window
		bool IsWindowOpen() const;

		int TakeScreenshot() const;

		~CosmosDrawer();
	private:

		SDL_Renderer* m_renderer;
		SDL_Window* m_window;

		bool m_isWindowOpen;
		bool m_altKeyDown;

		const cosmoscope::FuncTree* m_funcTree;
		cosmovertorSDL::SnapQueueSDL m_snapQueue;
		cosmovertorSDL::Cosmovertor m_cosmovertor;
		//cosmoscope::SnapQueueSDL m_snapQueue;


		double t;
		
		
	};
}