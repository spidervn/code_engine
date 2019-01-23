#ifndef CODEENGINE_C_ENGINE_INTERFACE_ENGINE_GENERATOR_CCPPCLASS_H_
#define CODEENGINE_C_ENGINE_INTERFACE_ENGINE_GENERATOR_CCPPCLASS_H_

#include "c_engine/interface/engine/generator/ICppClass.h"

class CCppClass : public ICppClass
{
    public:
        virtual ~CCppClass();
        std::string generate_HeaderFile(std::string projectCode,
                                        std::string relative_Path,
                                        std::string className);
};

#endif