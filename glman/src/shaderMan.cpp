#include "glman.h"

namespace glman
{

  ShaderProgram::ShaderProgram(const char *vertex_path, const char *fragment_path)
  {
    std::string vertex_source_str = util26::ReadWholeFile(vertex_path);
    std::string fragment_source_str = util26::ReadWholeFile(fragment_path);
    const char *vertex_source = vertex_source_str.c_str();
    const char *fragment_source = fragment_source_str.c_str();

    unsigned int vertex_id, fragment_id;
    int success;
    char infolog[512];

    vertex_id = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_id, 1, &vertex_source, NULL);
    glCompileShader(vertex_id);

    glGetShaderiv(vertex_id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
      glGetShaderInfoLog(vertex_id, 512, NULL, infolog);
      std::cerr << "Error while loading the following vertex shader \""
                << vertex_path << "\" :"
                << infolog << std::endl;
    }

    fragment_id = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_id, 1, &fragment_source, NULL);
    glCompileShader(fragment_id);

    glGetShaderiv(fragment_id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
      glGetShaderInfoLog(fragment_id, 512, NULL, infolog);
      std::cerr << "Error while loading the following fragment shader  \""
                << fragment_path << "\" : " <<std::endl
                << infolog << std::endl;
    }

    id = glCreateProgram();
    glAttachShader(id,vertex_id);
    glAttachShader(id,fragment_id);
    glLinkProgram(id);

    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success)
    {
      glGetProgramInfoLog(id, 512, NULL, infolog);
      std::cerr << "Error while linking the shader program containing the following shaders : \""
                << vertex_path << "\" , \""
                << fragment_path << "\" : " <<std::endl
                << infolog << std::endl;
    }

    glDeleteShader(vertex_id);
    glDeleteShader(fragment_id);
  }

  void ShaderProgram::Use()
  {
    glUseProgram(id);
  }

  void ShaderProgram::SetBool(const std::string &name, bool value) const
  {
    glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
  }
  void ShaderProgram::SetInt(const std::string &name, int value) const
  {
    glUniform1i(glGetUniformLocation(id, name.c_str()), value);
  }
  void ShaderProgram::SetFloat(const std::string &name, float value) const
  {
    glUniform1f(glGetUniformLocation(id, name.c_str()), value);
  }
}