#ifndef CODEENGINE_C_ENGINE_INTERFACE_TOOLKIT_ISTRINGTOOLKIT_H_
#define CODEENGINE_C_ENGINE_INTERFACE_TOOLKIT_ISTRINGTOOLKIT_H_

#include <string>
#include <vector>

class IStringToolkit
{
public:
    virtual ~IStringToolkit() {}
    virtual int split(std::string content, std::string separator, std::vector<std::string>& v_split) = 0;
};

#endif