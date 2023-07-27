/// @file WindowManagerGL.h
/// @brief This contains a wrapper for SDL windows using OpenGL for rendering. Derives from WindowManager
/// 
/// @author Alice Rixte
/// @date 28/05/2022

#pragma once


#include "WindowManager.h"

#include "GL/glew.h"
#include <SDL_opengl.h>

class WindowManagerGL : public WindowManager {
public:
	/// @brief Creates a class wrapper for SDL Windows using en OpenGL context
	/// @param window_name The name  of the window
	/// @param width The width of the window, in pixels
	/// @param height The height of the window, in pixels
	WindowManagerGL(const char* window_name, int width, int height);

	/// @brief Takes a screenshot
	/// @return A png file in the project "screenshots" folder
	int TakeScreenshot() const;

	~WindowManagerGL();

protected:
	SDL_GLContext m_context;
	SDL_Window* m_window;
};