#define GL_GLEXT_PROTOTYPES
#include <SDL.h>
#include <glad/glad.h>
#include <GL/gl.h>
#include <SDL_opengl.h>
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) // initialisation de la SDL
    {
        std::cerr << "Error with SDL initialisation : "
                  << SDL_GetError()
                  << std::endl;
        return EXIT_FAILURE;
    }

    SDL_Window *window = SDL_CreateWindow("OpenGL Test",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
    if (window == NULL)
    {
        std::cerr << "Error while trying to create SDL Window : "
                  << SDL_GetError()
                  << std::endl;
        return EXIT_FAILURE;
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_GLContext context = SDL_GL_CreateContext(window);
    gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    SDL_Event event;
    bool closeWindow = false;

    const char *vertexShaderSource = "#version 450 core\n"
                                     "layout (location = 0) in vec3 aPos;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                     "}\0";

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infolog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infolog);
        std::cerr << "Error : Vertex shader compilation failed" << std::endl;
    }

    const char *fragmentShaderSource = "#version 450 core\n"
                                       "out vec4 FragColor;\n"
                                       "void main()\n"
                                       "{\n"
                                       "   FragColor = vec4(1.0f,0.1f,0.1f,1.0f);\n"
                                       "}\0";
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infolog);
        std::cerr << "Error : Fragment shader compilation failed" << std::endl;
    }

    unsigned int shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infolog);
        std::cerr << "Error : Shader program linking failed" << std::endl;
    }

    glUseProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f};

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    while (!closeWindow)
    {

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_CLOSE)
                {
                    closeWindow = true;
                }
                break;
            case SDL_KEYUP:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    closeWindow = true;
                }
                break;
            }
        }

        glClearColor(1.f, 0.f, 1.f, 0.f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        SDL_GL_SwapWindow(window);
        SDL_Delay(100);
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}