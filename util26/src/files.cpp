#include "util26.h"

namespace util26
{
  std::string ReadWholeFile(const char* path)
  {
    std::ifstream file;

    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
      file.open(path);
      std::stringstream strm;
      strm << file.rdbuf();
      file.close();
      return strm.str();
    }
    catch (std::ifstream::failure e)
    {
      std::cerr << "Error while loading the following file : \""
                << path << "\""
                << std::endl;
      return "";
    }
  }

}