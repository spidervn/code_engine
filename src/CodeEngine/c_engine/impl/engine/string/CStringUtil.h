#ifndef CODEENGINE_C_ENGINE_INTERFACE_ENGINE_STRING_CSTRINGUTIL_H_
#define CODEENGINE_C_ENGINE_INTERFACE_ENGINE_STRING_CSTRINGUTIL_H_

#include "interface/engine/string/IStringUtil.h"

class CStringUtil: public IStringUtil
{
private:
    /* data */
public:
    CStringUtil(/* args */);
    virtual ~CStringUtil();
    int toUpper(std::string, std::string&);
};

#endif