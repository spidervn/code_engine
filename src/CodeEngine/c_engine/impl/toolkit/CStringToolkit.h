#ifndef CODEENGINE_C_ENGINE_INTERFACE_TOOLKIT_CSTRINGTOOLKIT_H_
#define CODEENGINE_C_ENGINE_INTERFACE_TOOLKIT_CSTRINGTOOLKIT_H_

#include "c_engine/interface/toolkit/IStringToolkit.h"
#include <string>
#include <vector>
#include <memory>

#define CStringToolkitPtrNew std::make_shared<CStringToolkit>()

class CStringToolkit: public IStringToolkit
{
public:
    virtual ~CStringToolkit();
    int split(std::string content, std::string separator, std::vector<std::string>& v_split);
    int split(std::string content, std::vector<std::string> separators, std::vector<std::string>& v_split);
};

#endif