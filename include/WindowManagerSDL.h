/// @file WindowManagerSDL.h
/// @brief This contains a wrapper for windows using SDL_Renderer as main rendering tool. Derives from WindowManager
/// 
/// @author Alice Rixte
/// @date 27/05/2022

#pragma once


#include "WindowManager.h"

class WindowManagerSDL : public WindowManager {
public:
	/// @brief Creates a class wrapper for SDL Window
	/// @param window_name The name  of the window
	/// @param width The width of the window, in pixels
	/// @param height The height of the window, in pixels
	WindowManagerSDL(const char* window_name, int width, int height);

	/// @brief Takes a screenshot
	/// @return A png file in the project "screenshots" folder
	int TakeScreenshot() const;

	~WindowManagerSDL();

protected:
	SDL_Renderer* m_renderer;

private:
	SDL_Window* m_window;
};