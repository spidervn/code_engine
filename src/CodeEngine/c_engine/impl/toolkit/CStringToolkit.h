#ifndef CODEENGINE_C_ENGINE_INTERFACE_TOOLKIT_CSTRINGTOOLKIT_H_
#define CODEENGINE_C_ENGINE_INTERFACE_TOOLKIT_CSTRINGTOOLKIT_H_

#include "c_engine/interface/toolkit/IStringToolkit.h"

class CStringToolkit
{
public:
    virtual ~CStringToolkit();
    int split(std::string content, std::string separator, std::vector<std::string>& v_split);
};


#endif