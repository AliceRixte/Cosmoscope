/// @file WindowManager.h
/// @brief Contains the main class handling all the SDL window related events
/// 
/// @author Alice Rixte
/// @date 07/04/2022
#pragma once
#include <SDL.h>

#include "savepng.h"



/// @brief This contains a whole cosmoscope with its own renderer and window
class WindowManager {
public:
	/// @brief Creates an SDL display environment for a tree of relative functions
	/// @param window_name The name  of the window
	/// @param width The width of the window, in pixels
	/// @param height The height of the window, in pixels
	WindowManager(const char* window_name, int width, int height);
		
	/// @brief Processes all the current events related to the windows
	/// @return 0 if everything went fine
	int ProcessEvents();

	/// @brief Displays a new frame based on current execution time
	/// @return 0 if everything went fine
	virtual int UpdateFrame() = 0;

	/// @brief States wether the window is opened or has been closed
	/// @return Switches to false when user closes the window
	bool IsWindowOpen() const;

	/// @brief Takes a screenshot
	/// @return A png file in the project "screenshots" folder
	int TakeScreenshot() const;

	~WindowManager();

protected:
	SDL_Renderer* m_renderer;
	bool m_pause;
		
private:
	SDL_Window* m_window;
	bool m_altKeyDown;
	bool m_isWindowOpen;
	
};