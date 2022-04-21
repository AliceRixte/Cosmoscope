/// @file WindowManager.h
/// @brief Contains the main class handling all the SDL window related events
/// 
/// @author Alice Rixte
/// @date 07/04/2022
#pragma once
#include <SDL.h>

#include "CSC_funcTree.h"
#include "CSC_CosmovertorSDL.h"
#include "CSC_CosmosDrawerSDL.h"
#include "savepng.h"



/// @brief This contains a whole cosmoscope with its own renderer and window
class WindowManager {
public:
	/// @brief Creates an SDL display environment for a tree of relative functions
	/// @param window_name The name  of the window
	/// @param width The width of the window, in pixels
	/// @param height The height of the window, in pixels
	/// @param func_tree A tree of relative functions
	WindowManager(const char* window_name, int width, int height, 
		const cosmoscopeSDL::CosmosDrawerSDL& cosmos_drawer, const cosmoscopeSDL::CosmovertorSDL& cosmovertor);



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

	~WindowManager();
private:

	SDL_Renderer* m_renderer;
	SDL_Window* m_window;

	bool m_isWindowOpen;
	bool m_altKeyDown;
	bool m_pause;


	const cosmoscopeSDL::CosmosDrawerSDL& m_cosmosDrawer;

	cosmoscopeSDL::SnapQueueSDL m_snapQueue;
	cosmoscopeSDL::CosmovertorSDL m_cosmovertor;


	double t;
		
		
};