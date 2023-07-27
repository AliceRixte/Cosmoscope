/// @file WindowManager.h
/// @brief Contains the main class handling all the SDL window related events
/// 
/// @author Alice Rixte
/// @date 07/04/2022

#pragma once

#include <SDL.h>

/// @brief This contains a whole cosmoscope with its own renderer and window
class WindowManager {
public:
	WindowManager();
		
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
	virtual int TakeScreenshot() const = 0;
protected:
	bool m_pause;
	bool m_altKeyDown;
	bool m_isWindowOpen;
	
};