#ifndef CODEENGINE_C_ENGINE_INTERFACE_ENGINE_CPP_ICPPGENERAL_H_
#define CODEENGINE_C_ENGINE_INTERFACE_ENGINE_CPP_ICPPGENERAL_H_

#include "interface/engine/cpp/ICppStructs.h"
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

    virtual int parseClassDef(std::string code, CppClassDef& def) = 0;
};

#endif