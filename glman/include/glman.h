#pragma once

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "util26.h"
namespace glman
{

  //More or less taken from the book learnopengl.com
  struct ShaderProgram
  {
    unsigned int id;

    ShaderProgram(const char *vertexPath, const char *fragmentPath);
    void Use();

    // utility uniform functions
    void SetBool(const std::string &name, bool value) const;
    void SetInt(const std::string &name, int value) const;
    void SetFloat(const std::string &name, float value) const;
  };
}