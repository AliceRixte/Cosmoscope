/// @file CosmosDrawer.h
/// @brief Contains the main SDL class handling all the display of the cosmoscope with the SDL library
/// 
/// @author Alice Rixte
/// @date 07/04/2022
#pragma once
#include <SDL.h>
#include "funcTree.h"

namespace cosmoscope_SDL {
	class CosmosDrawer {
	public:
		CosmosDrawer(const char* window_name, int width, int height, const cosmoscope::FuncTree* func_tree);
		void Play();

		SDL_Renderer* m_renderer;
		SDL_Window* m_window;
		bool m_isAppRunning;

		int ProcessEvents();
		int UpdateFrame();


		~CosmosDrawer();
	private:



		const cosmoscope::FuncTree* m_funcTree;
		double t;
		std::vector<cosmoscope::Position> frame_pos;
		std::vector<cosmoscope::Style>    frame_style;
		
	};
}