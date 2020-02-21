#ifndef CODEENGINE_C_ENGINE_INTERFACE_ENGINE_CPP_CCPPGENERAL_H_
#define CODEENGINE_C_ENGINE_INTERFACE_ENGINE_CPP_CCPPGENERAL_H_

#include "interface/engine/cpp/ICppGeneral.h"
#include <string>

class CCppGeneral
{
private:
    /* data */
public:
    CCppGeneral(/* args */);
    virtual ~CCppGeneral();

    std::string generateIfDefPragma(
        std::string path_base,
        std::string header_file);
};

#endif