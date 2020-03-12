#ifndef CODEENGINE_C_ENGINE_INTERFACE_ENGINE_STRING_ISTRINGUTIL_H_
#define CODEENGINE_C_ENGINE_INTERFACE_ENGINE_STRING_ISTRINGUTIL_H_

#include <string>
#include <memory>

class IStringUtil
{
private:
    /* data */
public:
    virtual ~IStringUtil() {}
    virtual int toUpper(std::string, std::string&) = 0;

    /* Input; Output;  */
    // virtual int wildcard_find(std::string input, std::string wildcard) = 0;
};

typedef std::shared_ptr<IStringUtil> IStringUtilPtr;

#endif