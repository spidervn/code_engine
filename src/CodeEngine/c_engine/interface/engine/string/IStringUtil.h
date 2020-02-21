#ifndef CODEENGINE_C_ENGINE_INTERFACE_ENGINE_STRING_ISTRINGUTIL_H_
#define CODEENGINE_C_ENGINE_INTERFACE_ENGINE_STRING_ISTRINGUTIL_H_

#include <string>

class IStringUtil
{
private:
    /* data */
public:
    virtual ~IStringUtil() {}
    virtual int toUpper(std::string, std::string&) = 0;
};

#endif