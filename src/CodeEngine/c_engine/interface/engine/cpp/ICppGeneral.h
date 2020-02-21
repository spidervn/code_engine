#ifndef CODEENGINE_C_ENGINE_INTERFACE_ENGINE_CPP_ICPPGENERAL_H_
#define CODEENGINE_C_ENGINE_INTERFACE_ENGINE_CPP_ICPPGENERAL_H_

#include <string>

class ICppGeneral
{
private:
    /* data */
public:
    virtual ~ICppGeneral() {}
    virtual std::string generateIfDefPragma(
        std::string path_base,
        std::string header_file
    ) = 0;

};

#endif