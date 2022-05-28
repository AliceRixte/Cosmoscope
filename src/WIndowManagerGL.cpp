#include "WindowManagerGL.h"


#include <iostream>

WindowManagerGL::WindowManagerGL(const char* window_name, int width, int height) :
    m_window(NULL), m_context(NULL)
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    m_window = SDL_CreateWindow("CosmoscopeGL", 100, 100, width , height , SDL_WINDOW_OPENGL);
    if (m_window) {
        m_context = SDL_GL_CreateContext(m_window);
        if (m_context) {
            const GLubyte* renderer_info = glGetString(GL_RENDERER); // get renderer string
            const GLubyte* version_info = glGetString(GL_VERSION); // version as a string
            std::cout << "GL Renderer : " << renderer_info << std::endl;
            std::cout << "OpenGL version supported : " << version_info << std::endl;

            glewExperimental = GL_TRUE;

            if (GLEW_OK != glewInit()) {
                std::cerr << "Error in glew initialisation" << std::endl;
            }
            else {
                glViewport(0, 0, width, height);
            }
        }
        else {
            std::cerr << "Error in GL Context creation : " << SDL_GetError() << std::endl;
        }
    }
    else
    {
        std::cerr << "Error in GL Window creation : " << SDL_GetError() << std::endl;
    }
}

int WindowManagerGL::TakeScreenshot() const {
    /*int w, h = 0;
    SDL_GetWindowSize(m_window, &w, &h);
    SDL_Surface* sshot = SDL_CreateRGBSurface(0, w, h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    SDL_RenderReadPixels(m_renderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
    SDL_SavePNG(sshot, "screenshots/cosmoscope.png");
    SDL_FreeSurface(sshot);*/
    return 0;
}


WindowManagerGL::~WindowManagerGL() {
    SDL_GL_DeleteContext(m_context);
    SDL_DestroyWindow(m_window);
}



